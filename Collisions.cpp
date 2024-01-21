#include "Collisions.h"

using namespace std;

Collisions::Collisions() {
	punkty = 0;

	robot = { robotX, robotY, robotZ, robotRA };

	treesPP.push_back({ 5.0, 0.0, -0.9 });
	treesPP.push_back({ 6.0, 6.0, -0.9 });
	treesPP.push_back({ 4.0, 13.0, -0.9 });
	treesPP.push_back({ 12.0, 24.0, -0.9 });
	treesPP.push_back({ 19.0, 28.0, -0.9 });
	treesPP.push_back({ 3, 25, -0.9 });

	treesNP.push_back({ -18.0, 18.0, -0.9 });
	treesNP.push_back({ -7, 32, -0.4 });
	treesNP.push_back({ -2, 31, -0.4 });
	treesNP.push_back({ -5, 10, -0.9 });
	treesNP.push_back({ -6, 20, -0.9 });
	treesNP.push_back({ -15, 28, -0.9 });
	treesNP.push_back({ -14, 5, -0.9 });
	treesNP.push_back({ -12, 27, -0.4 });

	treesPN.push_back({ 14.0, -13.0, -0.9 });
	treesPN.push_back({ 5.0, 0.0, -0.9 });
	treesPN.push_back({ 7.0, -23.0, -0.4 });
	treesPN.push_back({ -2, 31, -0.4 });
	treesPN.push_back({ 1, -13, -0.9 });
	treesPN.push_back({ 19, -26, -0.9 });
	treesPN.push_back({ 11, -28, -0.4 });

	treesNN.push_back({ -15.0, -19.0, -0.9 });
	treesNN.push_back({ -12, -8, -0.9 });
	treesNN.push_back({ 1, -13, -0.9 });
	treesNN.push_back({ -5, -30, -0.4 });
	treesNN.push_back({ -7, -16, -0.9 });
	treesNN.push_back({ -16, -26, -0.9 });

	linesPN.push_back({ {17.8, 4.5, -0.4}, {17.8, -1.15, -0.4} });
	linesPN.push_back({ {19.7, -1.15, -0.4}, {17.8, -1.15, -0.4} });
	linesPN.push_back({ {19.7, -1.15, -0.4}, {19.7, -3.75, -0.4} });
	linesPN.push_back({ {24.0, -3.75, -0.4}, {19.7, -3.75, -0.4} });
	linesPN.push_back({ {24.0, -3.75, -0.4}, {24.0, -6.0, -0.4} });
	linesPN.push_back({ {24.0, -6.0, -0.4}, {26.1, -6.0, -0.4} });
	linesPN.push_back({ {26.1, -8.5, -0.4}, {26.1, -6.0, -0.4} });
	linesPN.push_back({ {27.8, -8.5, -0.4}, {27.8, -28.0, -0.4} });
	linesPN.push_back({ {30.5, -28.0, -0.4}, {27.8, -28.0, -0.4} });
	linesPN.push_back({ {30.5, -28.0, -0.4}, {30.5, -30.5, -0.4} });
	linesPN.push_back({ {32.5, -30.5, -0.4}, {30.5, -30.5, -0.4} });
	linesPN.push_back({ {32.5, -30.5, -0.4}, {32.5, -34.7, -0.4} });
	linesPN.push_back({ {24.0, -34.7, -0.4}, {32.5, -34.7, -0.4} });
	linesPN.push_back({ {24.0, -34.7, -0.4}, {19.5, -43.2, -0.4} });
	linesPN.push_back({ {14.6, -42.1, -0.4}, {19.5, -43.2, -0.4} });
	linesPN.push_back({ {14.6, -42.1, -0.4}, {12.7, -35.2, -0.4} });
	linesPN.push_back({ {4.6, -35.2, -0.4}, {12.7, -35.2, -0.4} });
	linesPN.push_back({ {4.6, -35.2, -0.4}, {3.3, -37.8, -0.4} });
	linesPN.push_back({ {0.3, -38.6, -0.4}, {3.3, -37.8, -0.4} });
	linesPN.push_back({ {0.3, -38.6, -0.4}, {-2.9, -42.9, -0.4} });
	linesPN.push_back({ {-15.9, -42.9, -0.4}, {-2.9, -43.5, -0.4} });

	linesNN.push_back({ {0.3, -38.6, -0.4}, {-2.9, -42.9, -0.4} });
	linesNN.push_back({ {-15.9, -42.9, -0.4}, {-2.9, -43.5, -0.4} });
	linesNN.push_back({ {-15.9, -43.5, -0.4}, {-32.5, -22.9, -0.4} });
	linesNN.push_back({ {-31.5, -7.9, -0.4}, {-32.5, -22.9, -0.4} });
	linesNN.push_back({ {-31.5, -7.9, -0.4}, {-26.1, -5.6, -0.4} });
	linesNN.push_back({ {-24.4, 3.9, -0.4}, {-26.1, -5.6, -0.4} });

	linesNP.push_back({ {-24.4, 3.9, -0.4}, {-26.1, -5.6, -0.4} });
	linesNP.push_back({ {-24.4, 3.9, -0.4}, {-26.5, 3.9, -0.4} });
	linesNP.push_back({ {-26.5, 5.5, -0.4}, {-26.5, 3.9, -0.4} });
	linesNP.push_back({ {-26.5, 5.5, -0.4}, {-28.9, 5.1, -0.4} });
	linesNP.push_back({ {-31.1, 6.8, -0.4}, {-28.9, 5.1, -0.4} });
	linesNP.push_back({ {-31.1, 6.8, -0.4}, {-31.1, 12.8, -0.4} });
	linesNP.push_back({ {-34.1, 17.3, -0.4}, {-31.1, 12.8, -0.4} });
	linesNP.push_back({ {-34.1, 17.3, -0.4}, {-32.9, 22.1, -0.4} });
	linesNP.push_back({ {-31.2, 30.7, -0.4}, {-32.9, 22.1, -0.4} });
	linesNP.push_back({ {-31.2, 30.7, -0.4}, {-26.3, 34.0, -0.4} });
	linesNP.push_back({ {-24.2, 41.1, -0.4}, {-26.3, 34.0, -0.4} });
	linesNP.push_back({ {-24.2, 41.1, -0.4}, {-20.1, 43.1, -0.4} });
	linesNP.push_back({ {-20.0, 41.0, -0.4}, {-20.1, 43.1, -0.4} });
	linesNP.push_back({ {-20.0, 41.0, -0.4}, {-21.0, 41.0, -0.4} });
	linesNP.push_back({ {-21.4, 41.9, -0.4}, {-16.9, 41.7, -0.4} });
	linesNP.push_back({ {1.4, 40.4, -0.4}, {-16.9, 41.7, -0.4} });

	linesPP.push_back({ {1.4, 40.4, -0.4}, {-16.9, 41.7, -0.4} });
	linesPP.push_back({ {1.4, 40.4, -0.4}, {1.5, 38.4, -0.4} });
	linesPP.push_back({ {9.2, 37.7, -0.4}, {1.5, 37.7, -0.4} });
	linesPP.push_back({ {9.3, 39.7, -0.4}, {13.9, 39.7, -0.4} });
	linesPP.push_back({ {13.6, 37.8, -0.4}, {23.6, 37.8, -0.4} });
	linesPP.push_back({ {28.2, 40.2, -0.4}, {23.6, 38.3, -0.4} });
	linesPP.push_back({ {28.2, 40.2, -0.4}, {30.5, 37.4, -0.4} });
	linesPP.push_back({ {30.5, 33.0, -0.4}, {30.5, 37.4, -0.4} });
	linesPP.push_back({ {32.3, 32.3, -0.4}, {32.3, 30.4, -0.4} });
	linesPP.push_back({ {30.6, 27.8, -0.4}, {32.3, 30.4, -0.4} });
	linesPP.push_back({ {30.2, 27.8, -0.4}, {30.2, 10.9, -0.4} });
	linesPP.push_back({ {32.4, 11.2, -0.4}, {32.4, 8.4, -0.4} });
	linesPP.push_back({ {21.1, 8.8, -0.4}, {32.4, 8.8, -0.4} });
	linesPP.push_back({ {21.1, 8.8, -0.4}, {17.8, 4.5, -0.4} });
	linesPP.push_back({ {17.8, 4.5, -0.4}, {17.8, -1.15, -0.4} });
}

void Collisions::setRobotX(float liczba)
{
	robotX = liczba;

	robot = { robotX, robotY, robotZ, robotRA };

}

void Collisions::setRobotY(float liczba)
{
	robotY = liczba;

	robot = { robotX, robotY, robotZ, robotRA };

}

void Collisions::setRobotZ(float liczba)
{
	robotZ = liczba;

	robot = { robotX, robotY, robotZ, robotRA };

}

void Collisions::setRobotRA(float liczba)
{
	robotRA = liczba;

	robot = { robotX, robotY, robotZ, robotRA };
}

void Collisions::addCarrotsXY(float x, float y)
{
	carrotsXY.push_back({ x, y, 0.1 });
}

vector<int> Collisions::getIndexToDelete()
{
	return indexToDelete;
}

int Collisions::getCollectedCarrots()
{
	return punkty;
}

void Collisions::setCollectedCarrots(int liczba)
{
	punkty = liczba;
}

void Collisions::clearVectors()
{
	indexToDelete.clear();
	carrotsXY.clear();
}

float robotWidth = 3.1f;
float robotHeight = 1.4f;

bool Collisions::czyLinieSiePrzecinaja(Linia a, Linia b)
{

	float denominator = ((b.punkt2.y - b.punkt1.y) * (a.punkt2.x - a.punkt1.x)) - ((b.punkt2.x - b.punkt1.x) * (a.punkt2.y - a.punkt1.y));
	float numerator1 = ((b.punkt2.x - b.punkt1.x) * (a.punkt1.y - b.punkt1.y)) - ((b.punkt2.y - b.punkt1.y) * (a.punkt1.x - b.punkt1.x));
	float numerator2 = ((a.punkt2.x - a.punkt1.x) * (a.punkt1.y - b.punkt1.y)) - ((a.punkt2.y - a.punkt1.y) * (a.punkt1.x - b.punkt1.x));

	if (denominator == 0) return numerator1 == 0 && numerator2 == 0;

	float r = numerator1 / denominator;
	float s = numerator2 / denominator;

	return (r >= 0 && r <= 1) && (s >= 0 && s <= 1);
}

bool Collisions::czyProstokatKolidujeZLinia(WspolrzedneRobot robot, float robotWidth, float robotHieght, Linia linia)
{
	Wspolrzedne punkt1 = { robot.x - robotWidth / 2, robot.y - robotHieght / 2, -0.4 };
	Wspolrzedne punkt2 = { robot.x + robotWidth / 2, robot.y - robotHieght / 2, -0.4 };
	Wspolrzedne punkt3 = { robot.x - robotWidth / 2, robot.y + robotHieght / 2, -0.4 };
	Wspolrzedne punkt4 = { robot.x + robotWidth / 2, robot.y + robotHieght / 2, -0.4 };

	Linia krawedz1 = { punkt1, punkt2 };
	Linia krawedz2 = { punkt2, punkt4 };
	Linia krawedz3 = { punkt4, punkt3 };
	Linia krawedz4 = { punkt3, punkt1 };

	return czyLinieSiePrzecinaja(krawedz1, linia) ||
		czyLinieSiePrzecinaja(krawedz2, linia) ||
		czyLinieSiePrzecinaja(krawedz3, linia) ||
		czyLinieSiePrzecinaja(krawedz4, linia);
}

bool Collisions::checkingCollision(WspolrzedneRobot a, Wspolrzedne b) {
	// Oblicz wspó³rzêdne okrêgu w uk³adzie wspó³rzêdnych prostok¹ta
	float cosTheta = cos(-robot.ra);
	float sinTheta = sin(-robot.ra);
	float dx = b.x - a.x;
	float dy = b.y - a.y;
	float x = dx * cosTheta - dy * sinTheta;
	float y = dx * sinTheta + dy * cosTheta;

	// ZnajdŸ najbli¿szy punkt na prostok¹cie do œrodka okrêgu
	float najblizszyX = max(-robotWidth / 2, min(x, robotWidth / 2));
	float najblizszyY = max(-robotHeight / 2, min(y, robotHeight / 2));

	// Oblicz dystans miêdzy tym punktem a œrodkiem okrêgu
	float dystansX = x - najblizszyX;
	float dystansY = y - najblizszyY;

	float promien = 0.15;

	if (b.z == -0.4) {
		promien = 0.15;
	}
	else if (b.z == -0.9) {
		promien = 0.25;
	}
	else if (b.z == 0.1) {
		promien = 0.1;
	}

	// Jeœli dystans jest mniejszy lub równy promieniowi okrêgu, mamy kolizjê
	return (dystansX * dystansX + dystansY * dystansY) <= (promien * promien);
}

bool Collisions::isCollisionDetected() 
{
	//X+ i Y+
	if (robotX >= 0 && robotY >= 0) {
		for (const auto& tree : treesPP) {
			if (checkingCollision(robot, tree)) {
				return true;
			}
		}
		for (const auto& line : linesPP) {
			if (czyProstokatKolidujeZLinia(robot, robotWidth, robotHeight, line)) {
				return true;
			}
		}
	}

	//X+ i Y-
	if (robotX >= 0 && robotY <= 0) {
		for (const auto& tree : treesPN) {
			if (checkingCollision(robot, tree)) {
				return true;
			}
		}
		for (const auto& line : linesPN) {
			if (czyProstokatKolidujeZLinia(robot, robotWidth, robotHeight, line)) {
				return true;
			}
		}
	}

	//X- i Y+
	if (robotX <= 0 && robotY >= 0) {
		for (const auto& tree : treesNP) {
			if (checkingCollision(robot, tree)) {
				return true;
			}
		}
		for (const auto& line : linesNP) {
			if (czyProstokatKolidujeZLinia(robot, robotWidth, robotHeight, line)) {
				return true;
			}
		}
	}

	//X- i Y-
	if (robotX <= 0 && robotY <= 0) {
		for (const auto& tree : treesNN) {
			if (checkingCollision(robot, tree)) {
				return true;
			}
		}
		for (const auto& line : linesNN) {
			if (czyProstokatKolidujeZLinia(robot, robotWidth, robotHeight, line)) {
				return true;
			}
		}
	}

	for (int i = 0; i < carrotsXY.size(); i++) {
		if (find(indexToDelete.begin(), indexToDelete.end(), i) == indexToDelete.end()) {
			if (checkingCollision(robot, carrotsXY[i])) {
				indexToDelete.push_back(i);
				punkty += 1;
				enginePoint->play2D("sounds/collect_point.mp3", false);
				return false;
			}
		}
	}

	return false;
}