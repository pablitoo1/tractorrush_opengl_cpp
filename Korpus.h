#pragma once

//#include <GL/glut.h>
#include "Dependencies/glew-2.1.0/include/GL/glew.h"

class Korpus
{
public:
	Korpus(float x, float y, float z);
	void draw();

private:
	float x, y, z;
};