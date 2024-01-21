#pragma once

//#include <GL/glut.h>
#include "Dependencies/glew-2.1.0/include/GL/glew.h"

#include <cmath>

class Tlumik {
public:
    Tlumik(float x, float y, float z);
    void draw();

private:
    float x, y, z;
    int sides;
    const float height = 0.3f;
    const float radius = 0.05f;
};
