/*
  ==============================================================================

    HeadMesh.h

    Loads a Wavefront OBJ, centres and scales it to the unit head space used by
    the visualiser (y spans roughly -1..1), and optionally reduces it to a
    triangle budget the software renderer can sustain.

  ==============================================================================
*/

#pragma once

#include <vector>

class HeadMesh
{
public:
    struct Vertex { float x = 0.0f, y = 0.0f, z = 0.0f; };
    struct Triangle { int a = 0, b = 0, c = 0; };

    // Pass a positive triangleBudget to decimate on load; 0 keeps the model as authored.
    bool loadFromObj(const void* data, int numBytes, int triangleBudget = 0);

    bool isValid() const noexcept { return !triangles.empty(); }
    const std::vector<Vertex>& getVertices() const noexcept { return vertices; }
    const std::vector<Triangle>& getTriangles() const noexcept { return triangles; }

private:
    void normalise();
    void fixWinding();
    void decimate(int triangleBudget);

    std::vector<Vertex> vertices;
    std::vector<Triangle> triangles;
};
