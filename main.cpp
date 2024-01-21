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

#include "Game.h"

using namespace std;
using namespace chrono;
using namespace irrklang;

ISoundEngine* engine = createIrrKlangDevice();

Game game;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);

    glutInitWindowSize(screenWidth, screenHeight);

    glutInitWindowPosition(0, 0);    
    
    glutCreateWindow("Tractor Rush: Carrots Edition");

    glEnable(GL_DEPTH_TEST);

    game.loadResultsFromFile();

    game.loadAll();

    glutDisplayFunc([]() {
        game.display();
    });

    glutReshapeFunc([](int width, int height) {
        game.reshape(width, height);
    });

    glutKeyboardFunc([](unsigned char key, int x, int y) {
        game.keyboardCallback(key, x, y);
    });

    glutKeyboardUpFunc([](unsigned char key, int x, int y) {
        game.keyboardUpCallback(key, x, y);
    });

    glutIdleFunc([]() {
        game.idle();
    });

    if (!engine) {
        return 0;
    }
    engine->play2D("sounds/farming.mp3", true);

    glutMainLoop();

    return 0;
}
