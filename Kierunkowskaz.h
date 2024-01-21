#pragma once
//#include <GL/glut.h>
#include "Dependencies/glew-2.1.0/include/GL/glew.h"


class Kierunkowskaz
{
public:
	Kierunkowskaz(float x, float y, float z, bool isTurn);
	void draw();
private:
	float x, y, z;
	bool isTurn = false;
};
