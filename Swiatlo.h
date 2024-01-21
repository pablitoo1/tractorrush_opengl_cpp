#pragma once

#include "Dependencies/glew-2.1.0/include/GL/glew.h"

//#include <GL/glut.h>
#include <cmath>

class Swiatlo {
public:
    Swiatlo(float x, float y, float z);
    void draw();

private:
    float x, y, z;   
    int sides;           
    const float height = 0.05f;
    const float radius = 0.05f;
};
