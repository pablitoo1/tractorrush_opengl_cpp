#pragma once
#include <string>
//#include <gl\gl.h>
//#include <gl\glu.h>
#include "Dependencies/glew-2.1.0/include/GL/glew.h"
#include <iostream>
#include <vector>
#define  _CRT_SECURE_NO_WARNINGS
#ifdef _MSC_VER
//#  pragma comment(lib, "opengl32.lib")
//#  pragma comment(lib, "glu32.lib")
#endif
#include <windows.h>
#include <math.h>
#include <stdio.h>

GLuint loadTexture(const char* filename);
std::pair<std::vector<float>, std::vector<float>> loadObjFile(const std::string& filename, GLuint textureName);
void drawObjects(GLuint textureName, std::pair<std::vector<float>, std::vector<float>> vectors, GLfloat red, GLfloat green, GLfloat blue, float x, float y, float z, float scaleX, float scaleY, float scaleZ);