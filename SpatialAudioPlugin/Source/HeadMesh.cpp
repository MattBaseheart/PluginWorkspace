/*
  ==============================================================================

    HeadMesh.cpp

  ==============================================================================
*/

#include "HeadMesh.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unordered_map>

bool HeadMesh::loadFromObj(const void* data, int numBytes, int triangleBudget)
{
    vertices.clear();
    triangles.clear();

    if (data == nullptr || numBytes <= 0) return false;

    // Copied so the parser is guaranteed a null terminator to stop on
    const std::string text(static_cast<const char*>(data), (size_t)numBytes);
    const char* p = text.c_str();
    const char* end = p + text.size();

    while (p < end) {
        const char* lineEnd = static_cast<const char*>(std::memchr(p, '\n', (size_t)(end - p)));
        if (lineEnd == nullptr) lineEnd = end;

        if (lineEnd - p >= 2 && (p[1] == ' ' || p[1] == '\t')) {
            if (p[0] == 'v') {
                char* cursor = const_cast<char*>(p + 2);
                Vertex v;
                v.x = std::strtof(cursor, &cursor);
                v.y = std::strtof(cursor, &cursor);
                v.z = std::strtof(cursor, &cursor);
                vertices.push_back(v);
            } else if (p[0] == 'f') {
                int corners[64];
                int numCorners = 0;
                const char* cursor = p + 2;

                while (cursor < lineEnd && numCorners < 64) {
                    while (cursor < lineEnd && (*cursor == ' ' || *cursor == '\t')) ++cursor;
                    if (cursor >= lineEnd) break;

                    char* after = nullptr;
                    const long parsed = std::strtol(cursor, &after, 10);
                    if (after == cursor) break;

                    // OBJ indices are 1-based; negative values count back from the end
                    corners[numCorners++] = parsed < 0 ? (int)vertices.size() + (int)parsed
                                                       : (int)parsed - 1;

                    while (cursor < lineEnd && *cursor != ' ' && *cursor != '\t') ++cursor;
                }

                for (int i = 1; i + 1 < numCorners; ++i) {
                    const Triangle t{ corners[0], corners[i], corners[i + 1] };
                    if (t.a >= 0 && t.b >= 0 && t.c >= 0
                        && t.a < (int)vertices.size() && t.b < (int)vertices.size() && t.c < (int)vertices.size())
                        triangles.push_back(t);
                }
            }
        }

        p = lineEnd + 1;
    }

    if (vertices.empty() || triangles.empty()) return false;

    decimate(triangleBudget);
    normalise();
    fixWinding();
    return !triangles.empty();
}

void HeadMesh::normalise()
{
    if (vertices.empty()) return;

    Vertex lo = vertices.front(), hi = vertices.front();
    for (const auto& v : vertices) {
        lo.x = std::min(lo.x, v.x); hi.x = std::max(hi.x, v.x);
        lo.y = std::min(lo.y, v.y); hi.y = std::max(hi.y, v.y);
        lo.z = std::min(lo.z, v.z); hi.z = std::max(hi.z, v.z);
    }

    const Vertex centre{ (lo.x + hi.x) * 0.5f, (lo.y + hi.y) * 0.5f, (lo.z + hi.z) * 0.5f };
    const float height = std::max(hi.y - lo.y, 1.0e-6f);
    const float scale = 2.0f / height; // match the unit head space (y spans -1..1)

    for (auto& v : vertices) {
        v.x = (v.x - centre.x) * scale;
        v.y = (v.y - centre.y) * scale;
        v.z = (v.z - centre.z) * scale;
    }
}

void HeadMesh::fixWinding()
{
    // Signed volume is negative when the triangles wind inward, which would make the
    // renderer's backface cull hide the outside of the model instead of the inside.
    double volume = 0.0;
    for (const auto& t : triangles) {
        const auto& a = vertices[(size_t)t.a];
        const auto& b = vertices[(size_t)t.b];
        const auto& c = vertices[(size_t)t.c];
        volume += (double)a.x * ((double)b.y * c.z - (double)b.z * c.y)
                - (double)a.y * ((double)b.x * c.z - (double)b.z * c.x)
                + (double)a.z * ((double)b.x * c.y - (double)b.y * c.x);
    }

    if (volume < 0.0)
        for (auto& t : triangles)
            std::swap(t.b, t.c);
}

void HeadMesh::decimate(int triangleBudget)
{
    if (triangleBudget <= 0 || (int)triangles.size() <= triangleBudget || vertices.empty()) return;

    Vertex lo = vertices.front(), hi = vertices.front();
    for (const auto& v : vertices) {
        lo.x = std::min(lo.x, v.x); hi.x = std::max(hi.x, v.x);
        lo.y = std::min(lo.y, v.y); hi.y = std::max(hi.y, v.y);
        lo.z = std::min(lo.z, v.z); hi.z = std::max(hi.z, v.z);
    }

    const float spanX = std::max(hi.x - lo.x, 1.0e-6f);
    const float spanY = std::max(hi.y - lo.y, 1.0e-6f);
    const float spanZ = std::max(hi.z - lo.z, 1.0e-6f);

    // A closed surface through an NxNxN grid leaves roughly 2*N^2 triangles, so start near that
    int grid = std::clamp((int)std::lround(std::sqrt((float)triangleBudget * 0.5f)), 6, 128);

    for (int attempt = 0; attempt < 10; ++attempt) {
        std::unordered_map<long long, int> cellToVertex;
        std::vector<Vertex> sums;
        std::vector<int> counts;
        std::vector<int> remap(vertices.size(), 0);
        cellToVertex.reserve(vertices.size());

        for (size_t i = 0; i < vertices.size(); ++i) {
            const auto& v = vertices[i];
            const int cx = std::clamp((int)((v.x - lo.x) / spanX * (float)grid), 0, grid - 1);
            const int cy = std::clamp((int)((v.y - lo.y) / spanY * (float)grid), 0, grid - 1);
            const int cz = std::clamp((int)((v.z - lo.z) / spanZ * (float)grid), 0, grid - 1);
            const long long key = ((long long)cx * grid + cy) * grid + cz;

            auto found = cellToVertex.find(key);
            int index;
            if (found == cellToVertex.end()) {
                index = (int)sums.size();
                cellToVertex.emplace(key, index);
                sums.push_back({ 0.0f, 0.0f, 0.0f });
                counts.push_back(0);
            } else {
                index = found->second;
            }

            sums[(size_t)index].x += v.x;
            sums[(size_t)index].y += v.y;
            sums[(size_t)index].z += v.z;
            counts[(size_t)index]++;
            remap[i] = index;
        }

        std::vector<Triangle> reduced;
        reduced.reserve(triangles.size() / 4);
        for (const auto& t : triangles) {
            const int a = remap[(size_t)t.a], b = remap[(size_t)t.b], c = remap[(size_t)t.c];
            if (a != b && b != c && a != c)
                reduced.push_back({ a, b, c });
        }

        if ((int)reduced.size() <= triangleBudget || grid <= 6 || attempt == 9) {
            std::vector<Vertex> merged(sums.size());
            for (size_t i = 0; i < sums.size(); ++i) {
                const float n = (float)std::max(1, counts[i]);
                merged[i] = { sums[i].x / n, sums[i].y / n, sums[i].z / n };
            }
            vertices.swap(merged);
            triangles.swap(reduced);
            return;
        }

        grid = std::max(6, (int)((float)grid * 0.78f));
    }
}
