#pragma once

//#include <GL/glut.h>
#include "Dependencies/glew-2.1.0/include/GL/glew.h"

#include <cmath>

class Rura {
public:
    Rura(float x, float y, float z);
    void draw();

private:
    float x, y, z;
    int sides;
    const float height = 0.95f;
    const float radius = 0.025f;
};
