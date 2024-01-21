#pragma once

//#include <GL/glut.h>
#include "Dependencies/glew-2.1.0/include/GL/glew.h"

#include <cmath>

class Lacznik
{
public:
	Lacznik(float x, float y, float z);
	void draw();

private:
	float x, y, z;
	int sides;            // Liczba boków kola (iloœæ trójk¹tów)
	const float height = 1.25f;
	const float radius = 0.05f;
};