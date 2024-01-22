#pragma once
#include "Dependencies/glew-2.1.0/include/GL/glew.h"
#include "loader.h"
#include "Kolo.h"
#include "Korpus.h"
#include "Lacznik.h"
#include "Tablica.h"
#include "Przod.h"
#include "Tyl.h"
#include "Swiatlo.h"
#include "Slupek.h"
#include "Dach.h"
#include "Rura.h"
#include "Tlumik.h"
#include "Kierunkowskaz.h"

class Robot
{
public:
	//Robot(float rotationAngle, float x, float y, float z);
	Robot();
	void draw();
	float x, y, z, rotationAngle, inclinationDegree;
	bool isA, isD;
	void setRotate(float isA, float isD);
};
