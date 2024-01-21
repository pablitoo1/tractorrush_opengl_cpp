#pragma once
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <irrKlang.h>

using namespace std;
using namespace irrklang;

typedef struct wspolrzedne
{
	float x;
	float y;
	float z;
}Wspolrzedne;

typedef struct wspolrzedneRobot
{
	float x;
	float y;
	float z;
	float ra;
}WspolrzedneRobot;

struct Linia {
	Wspolrzedne punkt1;
	Wspolrzedne punkt2;
};

class Collisions
{
public:
	Collisions();
	bool isCollisionDetected();
	void setRobotX(float liczba);
	void setRobotY(float liczba);
	void setRobotZ(float liczba);
	void setRobotRA(float liczba);
	void addCarrotsXY(float x, float y);
	vector<int> getIndexToDelete();
	int getCollectedCarrots();
	void setCollectedCarrots(int liczba);
	void clearVectors();
private:
	ISoundEngine* enginePoint = createIrrKlangDevice();
	bool czyLinieSiePrzecinaja(Linia a, Linia b);
	bool czyProstokatKolidujeZLinia(WspolrzedneRobot robot, float robotWidth, float robotHieght, Linia linia);
	bool checkingCollision(WspolrzedneRobot a, Wspolrzedne b);
	float robotX = 0.0, robotY = 0.0, robotZ = 0.0, robotRA = 0.0;
	int punkty;
	vector<int> indexToDelete;
	vector<Wspolrzedne> carrotsXY;
	WspolrzedneRobot robot;
	vector<Wspolrzedne> treesPP;	//+X i +Y
	vector<Wspolrzedne> treesPN;	//+X i +Y
	vector<Wspolrzedne> treesNP;	//+X i +Y
	vector<Wspolrzedne> treesNN;	//+X i +Y
	vector<Linia> linesPP;			//+X i +Y
	vector<Linia> linesPN;			//+X i -Y
	vector<Linia> linesNP;			//-X i +Y
	vector<Linia> linesNN;			//-X i -Y
};