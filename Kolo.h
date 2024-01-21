#pragma once

//#include <GL/glut.h>
#include "Dependencies/glew-2.1.0/include/GL/glew.h"

#include <cmath>

class Kolo {
public:
    Kolo(float x, float y, float z);
    void setTexture(const char* textureName);
    void draw();

private:
    float x, y, z;        // Po�o�enie kola
    int sides;            // Liczba bok�w kola (ilo�� tr�jk�t�w)
    const float height = 0.2f;
    const float radius = 0.2f;
    const char* textureName = "";
};
