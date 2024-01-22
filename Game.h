#pragma once
#include "Dependencies/glew-2.1.0/include/GL/glew.h"
//#include <GL/glut.h>
#include <irrKlang.h>
#include "Robot.h"
#include "Collisions.h"
#include <GL/freeglut_std.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <random>
#include <chrono>
#include <future>
#include <iomanip>
#include <fstream>
#define M_PI 3.14159265358979323846

using namespace std;
using namespace chrono;
using namespace irrklang;

class Game
{
private:
	high_resolution_clock::time_point startTime;
	high_resolution_clock::time_point pauseStart;
	high_resolution_clock::time_point pauseEnd;
	bool stop = false;
	bool gameStarted = false;
	bool tab = false;
	bool goUp = true;
	bool isS = false;
	bool isW = false;
	bool isD = false;
	bool isA = false;
	bool isCollision = false;
	float tempX = 0;
	float tempY = 0;
	float radiansRA = 0;
	float max_speed_forward = 0.15f;
	float max_speed_backward = 0.1f;
	float turning_angle = 2.0f;
	float movingCarrot = 0;
	int tempRand = 0;
	const double tolerance = 0.001;
	bool up = false;
	int licznik = 0, licznik2 = 0, licznik3 = 0;
	int liczenie = 0;
	vector<pair<float, float>> randCarrotsXY;
	vector<int> indexToDelete;
	duration<double> time_span = duration<double>(0.0);
	duration<double> time_span_pause = duration<double>(0.0);
	float addedTimeForCollision = 0;
	vector<double> bestResults;
	double lastResult = 0.00;
	bool collisionA = true, collisionD = true;
	float speed = 0; //dla wyswietlania na ekranie km/h
	float zoomX = 0; //dla wyswietlania na ekranie zoomSize
	bool isMoving = false;
	float speedRoverForward = 0.01f;
	float speedRoverBackward = 0.01f;
	const float moveSpeed = 0.5f;
	float cameraPosX = -18.75f;
	float cameraPosY = 0.0f;
	float cameraPosZ = 15.0f;
	float rotationAngle = 0.0f;
	float rotationRobot = 0.0f;
	float przod = 0.0f;
	float bok = 0.0f;
	float gora = 0.5f;
	vector<GLuint> tekstury;
	vector<pair<vector<float>, vector<float>>> vectors;
	Collisions collisions;
	Robot robot;
	ISoundEngine* engineCollision = createIrrKlangDevice();
public:
	Game();
	void loadAll();
	void newResult(double result);
	void setLastResult(double last);
	void loadResultsFromFile();
	void endGame();
	void specialKeys(int key, int x, int y);
	void keyboardCallback(unsigned char key, int x, int y);
	void keyboardUpCallback(unsigned char key, int x, int y);
	void randomCarrotsXYGenerate();
	void idle();
	void DrawText(const char* text, GLfloat x, GLfloat y, GLfloat fontSize, int ID);
	void drawTextObjects();
	void display();
	void reshape(int width, int height);
};