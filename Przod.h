#pragma once
//#include <GL/glut.h>
#include "Dependencies/glew-2.1.0/include/GL/glew.h"


class Przod
{
public:
	Przod(float x, float y, float z);
	void draw();
private:
	float x, y, z;
};
