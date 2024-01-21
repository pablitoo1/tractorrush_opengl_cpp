#include "Game.h"


Game::Game() {
    tekstury.resize(100);
}

void Game::loadAll()
{
    tekstury[0] = loadTexture("textures/moutain1600.jpg");
    vectors.push_back(loadObjFile("obj/moutains3.obj", tekstury[0]));

    tekstury[1] = loadTexture("textures/grass2048.jpg");
    vectors.push_back(loadObjFile("obj/square.obj", tekstury[1]));

    //TREES
    tekstury[2] = loadTexture("textures/leaves.jpg");
    vectors.push_back(loadObjFile("obj/tree.obj", tekstury[2]));

    tekstury[3] = loadTexture("textures/leaves2.jpg");
    vectors.push_back(loadObjFile("obj/tree.obj", tekstury[3]));

    tekstury[4] = loadTexture("textures/leaves3.png");
    vectors.push_back(loadObjFile("obj/tree.obj", tekstury[4]));

    //CARROTS
    tekstury[5] = loadTexture("textures/orange.jpg");
    vectors.push_back(loadObjFile("obj/carrot_down.obj", tekstury[5]));

    tekstury[6] = loadTexture("textures/green.jpg");
    vectors.push_back(loadObjFile("obj/carrot_top.obj", tekstury[6]));
}

void Game::newResult(double result)
{
    bestResults.push_back(result);

    sort(bestResults.begin(), bestResults.end());

    if (bestResults.size() > 3) {
        bestResults.resize(3);
    }

    // Otwieramy plik do zapisu na koñcu
    std::ofstream outputFile("top3.txt", std::ios::trunc);

    // Sprawdzamy, czy plik jest otwarty poprawnie
    if (outputFile.is_open()) {
        // Zapisujemy trzy najlepsze wyniki do pliku
        for (const auto& value : bestResults) {
            outputFile << value << std::endl;
        }

        // Zamykamy plik
        outputFile.close();
    }
    else {
        // W przypadku problemów z otwarciem pliku, wypisujemy komunikat o b³êdzie
        std::cerr << "Nie uda³o siê otworzyæ pliku top3.txt do zapisu." << std::endl;
    }
}

void Game::setLastResult(double last)
{
    lastResult = last;
}

void Game::loadResultsFromFile()
{
    std::ifstream inputFile("top3.txt");

    // Sprawdzamy, czy plik jest otwarty poprawnie
    if (inputFile.is_open()) {
        double value;
        // Wczytujemy dane z pliku do wektora
        while (inputFile >> value) {
            bestResults.push_back(value);
        }
        // Zamykamy plik
        inputFile.close();
    }
    else {
        // W przypadku problemów z otwarciem pliku, wypisujemy komunikat o b³êdzie
        std::cerr << "Nie uda³o siê otworzyæ pliku top3.txt do odczytu." << std::endl;
    }
}

void Game::endGame()
{
    collisions.setCollectedCarrots(0);
    gameStarted = false;
    speedRoverForward = 0.01f;
    speedRoverBackward = 0.01f;
    addedTimeForCollision = 0;
    robot.rotationAngle = 0.0f;
    robot.inclinationDegree = 0.0f;
    robot.x = 0.0f;
    robot.y = 0.0f;
    cameraPosX = -18.75f;
    cameraPosY = 0.0f;
    cameraPosZ = 15.0f;
    goUp = true;
    licznik = 0;
    licznik2 = 0;
    licznik3 = 0;
    tempRand = 0;
    randCarrotsXY.clear();
    indexToDelete.clear();
    collisions.clearVectors();
}

void Game::specialKeys(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_UP:
        cameraPosX += moveSpeed;
        break;
    case GLUT_KEY_DOWN:
        cameraPosX -= moveSpeed;
        break;
    case GLUT_KEY_LEFT:
        cameraPosY += moveSpeed;
        break;
    case GLUT_KEY_RIGHT:
        cameraPosY -= moveSpeed;
        break;
    }

    glutPostRedisplay();
}

void Game::keyboardCallback(unsigned char key, int x, int y)
{
    switch (key) {
    case 'P':
    case 'p':
        if (gameStarted) {
            stop = !stop;
        }
        break;
    case 13:    //ENTER
        if (!gameStarted) {
            startTime = high_resolution_clock::now();
        }
        gameStarted = true;
        break;
    case 8:     //BACKSPACE
        stop = false;
        endGame();
        break;
    case 9:
        tab = !tab;
        break;
    case 'Z':
    case 'z':
        if (goUp) {
            cameraPosZ += 6 * moveSpeed;
            cameraPosX -= 7.5 * moveSpeed;
            if (cameraPosZ >= 30.0f) {
                goUp = false;
            }
        }
        else if (!goUp) {
            cameraPosZ -= 6 * moveSpeed;
            cameraPosX += 7.5 * moveSpeed;
            if (cameraPosZ <= 12.0f) {
                goUp = true;
            }
        }
        break;
    case 'W':
    case 'w':
        isW = true;
        break;
    case 'S':
    case 's':
        isS = true;
        break;
    case 'A':
    case 'a':
        isA = true;
        break;
    case 'D':
    case 'd':
        isD = true;
        break;
    }

    glutPostRedisplay();
}

void Game::keyboardUpCallback(unsigned char key, int x, int y)
{
    switch (key) {
    case 'W':
    case 'w':
        isW = false;
        break;
    case 'S':
    case 's':
        isS = false;
        break;
    case 'D':
    case 'd':
        isD = false;
        robot.setRotate(isA, isD);
        break;
    case 'A':
    case 'a':
        isA = false;
        robot.setRotate(isA, isD);
        break;
    }

    glutPostRedisplay();
}

void Game::randomCarrotsXYGenerate()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    uniform_real_distribution<float> x_dist(-23.0, 28.0);
    uniform_real_distribution<float> y_dist(10.0, 36.0);

    do {
        float randX = x_dist(gen);
        float randY = y_dist(gen);
        randCarrotsXY.push_back({ randX, randY });
        collisions.addCarrotsXY(randX, randY);
        licznik++;
    } while (licznik < 8);

    uniform_real_distribution<float> x_dist2(-20.0, 16.0);
    uniform_real_distribution<float> y_dist2(-6.0, 9.0);

    do {
        float randX2 = x_dist2(gen);
        float randY2 = y_dist2(gen);
        randCarrotsXY.push_back({ randX2, randY2 });
        collisions.addCarrotsXY(randX2, randY2);
        licznik2++;
    } while (licznik2 < 4);

    uniform_real_distribution<float> x_dist3(-21.0, 22.0);
    uniform_real_distribution<float> y_dist3(-33.0, -8.0);

    do {
        float randX3 = x_dist3(gen);
        float randY3 = y_dist3(gen);
        randCarrotsXY.push_back({ randX3, randY3 });
        collisions.addCarrotsXY(randX3, randY3);
        licznik3++;
    } while (licznik3 < 8);
}

void Game::idle()
{
    if (stop || !gameStarted) {
        return;
    }

    high_resolution_clock::time_point currentTime = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(currentTime - startTime);

    if (tempRand == 0) {
        randomCarrotsXYGenerate();
        tempRand = 1;
    }

    if (isW) {
        tempX = robot.x + ((speedRoverForward + (max_speed_forward / 30)) * cos(robot.rotationAngle * M_PI / 180.0f));
        tempY = robot.y + ((speedRoverForward + (max_speed_forward / 30)) * sin(robot.rotationAngle * M_PI / 180.0f));
        collisions.setRobotX(tempX);
        collisions.setRobotY(tempY);
        collisions.setRobotZ(robot.z);
        radiansRA = robot.rotationAngle * M_PI / 180.0f;
        collisions.setRobotRA(radiansRA);
        if (!collisions.isCollisionDetected()) {
            if (speedRoverForward < max_speed_forward) {
                speedRoverForward += (max_speed_forward / 30);
            }
            robot.x += speedRoverForward * cos(robot.rotationAngle * M_PI / 180.0f);
            robot.y += speedRoverForward * sin(robot.rotationAngle * M_PI / 180.0f);
            cameraPosY += speedRoverForward * sin(robot.rotationAngle * M_PI / 180.0f);
            cameraPosX += speedRoverForward * cos(robot.rotationAngle * M_PI / 180.0f);
            liczenie = 0;
        }
        else {
            if (speedRoverForward != 0 || speedRoverBackward != 0) {

                if (liczenie == 0) {
                    robot.inclinationDegree = 0.0f;
                    speedRoverForward = -speedRoverForward / 2;
                    speedRoverBackward = 0;
                    addedTimeForCollision += 0.5;
                    engineCollision->play2D("sounds/crash.mp3", false);
                }
                liczenie = 1;
            }
        }
    }

    if (isS) {
        tempX = robot.x - ((speedRoverBackward + (max_speed_backward / 30)) * cos(robot.rotationAngle * M_PI / 180.0f));
        tempY = robot.y - ((speedRoverBackward + (max_speed_backward / 30)) * sin(robot.rotationAngle * M_PI / 180.0f));
        collisions.setRobotX(tempX);
        collisions.setRobotY(tempY);
        collisions.setRobotZ(robot.z);
        radiansRA = robot.rotationAngle * M_PI / 180.0f;
        collisions.setRobotRA(radiansRA);
        if (!collisions.isCollisionDetected()) {
            if (speedRoverBackward < max_speed_backward) {
                speedRoverBackward += (max_speed_backward / 30);
            }
            robot.x -= speedRoverBackward * cos(robot.rotationAngle * M_PI / 180.0f);
            robot.y -= speedRoverBackward * sin(robot.rotationAngle * M_PI / 180.0f);
            cameraPosY -= speedRoverBackward * sin(robot.rotationAngle * M_PI / 180.0f);
            cameraPosX -= speedRoverBackward * cos(robot.rotationAngle * M_PI / 180.0f);
            liczenie = 0;
        }
        else {
            if (liczenie == 0) {
                robot.inclinationDegree = 0.0f;
                speedRoverForward = 0;
                speedRoverBackward = -speedRoverBackward / 2;
                addedTimeForCollision += 0.5;
                engineCollision->play2D("sounds/crash.mp3", false);
            }
            liczenie = 1;
        }
    }

    if (isA) {
        tempX = robot.x - ((speedRoverBackward + (max_speed_backward / 30)) * cos(robot.rotationAngle * M_PI / 180.0f));
        tempY = robot.y - ((speedRoverBackward + (max_speed_backward / 30)) * sin(robot.rotationAngle * M_PI / 180.0f));
        collisions.setRobotX(tempX);
        collisions.setRobotY(tempY);
        collisions.setRobotZ(robot.z);
        if (!isS) {
            radiansRA = (robot.rotationAngle + turning_angle) * M_PI / 180.0f;
            if (speedRoverForward >= max_speed_forward && robot.inclinationDegree < 8.0f) {
                robot.inclinationDegree += 0.25f;
            }
            else if (robot.inclinationDegree > 0.0f) {
                robot.inclinationDegree -= 0.25f;
            }
        }
        else {
            radiansRA = (robot.rotationAngle - turning_angle) * M_PI / 180.0f;
        }
        collisions.setRobotRA(radiansRA);
        if (!collisions.isCollisionDetected()) {
            collisionA = false;
            robot.setRotate(isA, isD);
            if (!isS) {
                robot.rotationAngle += turning_angle;
            }
            else {
                robot.rotationAngle -= turning_angle;
            }
        }
        else {
            if (!collisionA) {
                robot.inclinationDegree = 0.0f;
                addedTimeForCollision += 0.5;
                engineCollision->play2D("sounds/crash.mp3", false);
                collisionA = true;
            }
        }
    }
    else if (isD) {
        tempX = robot.x - ((speedRoverBackward + (max_speed_backward / 30)) * cos(robot.rotationAngle * M_PI / 180.0f));
        tempY = robot.y - ((speedRoverBackward + (max_speed_backward / 30)) * sin(robot.rotationAngle * M_PI / 180.0f));
        collisions.setRobotX(tempX);
        collisions.setRobotY(tempY);
        collisions.setRobotZ(robot.z);
        if (!isS) {
            radiansRA = (robot.rotationAngle - turning_angle) * M_PI / 180.0f;
            if (speedRoverForward >= max_speed_forward && robot.inclinationDegree > -8.0f) {
                robot.inclinationDegree -= 0.25f;
            }
            else if (robot.inclinationDegree > 0.0f) {
                robot.inclinationDegree += 0.25f;
            }
        }
        else {
            radiansRA = (robot.rotationAngle + turning_angle) * M_PI / 180.0f;
        }        collisions.setRobotRA(radiansRA);
        if (!collisions.isCollisionDetected()) {
            collisionD = false;
            robot.setRotate(isA, isD);
            if (!isS) {
                robot.rotationAngle -= turning_angle;
            }
            else {
                robot.rotationAngle += turning_angle;
            }
        }
        else {
            if (!collisionD) {
                robot.inclinationDegree = 0.0f;
                addedTimeForCollision += 0.5;
                engineCollision->play2D("sounds/crash.mp3", false);
                collisionD = true;
            }
        }
    }

    if (!isW && speedRoverForward > (max_speed_forward / 50)) {

        if (isS) {
            speedRoverForward -= (max_speed_forward / 50); // szybsze hamowanie
        }
        else {
            speedRoverForward -= (max_speed_forward / 60);
        }

        tempX = robot.x + ((speedRoverForward + (max_speed_forward / 30)) * cos(robot.rotationAngle * M_PI / 180.0f));
        tempY = robot.y + ((speedRoverForward + (max_speed_forward / 30)) * sin(robot.rotationAngle * M_PI / 180.0f));
        collisions.setRobotX(tempX);
        collisions.setRobotY(tempY);
        collisions.setRobotZ(robot.z);
        radiansRA = robot.rotationAngle * M_PI / 180.0f;
        collisions.setRobotRA(radiansRA);
        if (!collisions.isCollisionDetected()) {

            robot.x += speedRoverForward * cos(robot.rotationAngle * M_PI / 180.0f);
            robot.y += speedRoverForward * sin(robot.rotationAngle * M_PI / 180.0f);
            cameraPosY += speedRoverForward * sin(robot.rotationAngle * M_PI / 180.0f);
            cameraPosX += speedRoverForward * cos(robot.rotationAngle * M_PI / 180.0f);
        }
        else {
            if (speedRoverForward != 0 || speedRoverBackward != 0) {
                speedRoverForward = -speedRoverForward / 2;
                speedRoverBackward = 0;
                addedTimeForCollision += 0.5;
                engineCollision->play2D("sounds/crash.mp3", false);
            }
        }
    }
    else if (!isW && speedRoverForward <= (max_speed_forward / 50)) {
        speedRoverForward = 0;
    }

    if (!isS && speedRoverBackward > (max_speed_backward / 50)) {

        if (isW) {
            speedRoverBackward -= (max_speed_backward / 50); // szybsze hamowanie
        }
        else {
            speedRoverBackward -= (max_speed_backward / 60);
        }

        tempX = robot.x - ((speedRoverBackward + (max_speed_backward / 30)) * cos(robot.rotationAngle * M_PI / 180.0f));
        tempY = robot.y - ((speedRoverBackward + (max_speed_backward / 30)) * sin(robot.rotationAngle * M_PI / 180.0f));
        collisions.setRobotX(tempX);
        collisions.setRobotY(tempY);
        collisions.setRobotZ(robot.z);
        radiansRA = robot.rotationAngle * M_PI / 180.0f;
        collisions.setRobotRA(radiansRA);
        if (!collisions.isCollisionDetected()) {

            robot.x -= speedRoverBackward * cos(robot.rotationAngle * M_PI / 180.0f);
            robot.y -= speedRoverBackward * sin(robot.rotationAngle * M_PI / 180.0f);
            cameraPosY -= speedRoverBackward * sin(robot.rotationAngle * M_PI / 180.0f);
            cameraPosX -= speedRoverBackward * cos(robot.rotationAngle * M_PI / 180.0f);
        }
        else {
            if (speedRoverForward != 0 || speedRoverBackward != 0) {
                speedRoverForward = 0;
                speedRoverForward = -speedRoverBackward / 2;
                addedTimeForCollision += 0.5;
                engineCollision->play2D("sounds/crash.mp3", false);
            }
        }
    }
    else if (!isS && speedRoverBackward <= (max_speed_backward / 50)) {
        speedRoverBackward = 0;
    }

    if (!isA) {
        if (robot.inclinationDegree > 0.0f) {
            robot.inclinationDegree -= 0.25f;
        }
    }
    if (!isD) {
        if (robot.inclinationDegree < 0.0f) {
            robot.inclinationDegree += 0.25f;
        }
    }

    if (collisions.getCollectedCarrots() == 20) {
        newResult(time_span.count() + (double)addedTimeForCollision);
        setLastResult(time_span.count() + (double)addedTimeForCollision);
        endGame();
    }

    glutPostRedisplay();
}

void Game::DrawText(const char* text, GLfloat x, GLfloat y, GLfloat fontSize, int ID)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 1000);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(static_cast<int>(x + 5), static_cast<int>(y + 20));
    for (const char* c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    if (ID == 1) {
        glColor3f(1.0, 1.0, 1.0);
    }
    else if (ID == 2) {
        if (speed > 45) {
            glColor3f(0.7, 0.0, 0.0);
        }
        else if (speed > 15) {
            glColor3f(0.8, 0.8, 0.0);
        }
        else if (speed >= 0) {
            glColor3f(0.0, 1.0, 0.0);
        }
    }
    else if (ID == 3) {
        glColor3f(0.4, 0.4, 0.9);
    }
    else if (ID == 4) {
        glColor3f(1.0, 0.84, 0.0);
    }
    else if (ID == 5) {
        glColor3f(0.75, 0.75, 0.75);
    }
    else if (ID == 6) {
        glColor3f(0.65, 0.17, 0.17);
    }
    else if (ID == 7) {
        glColor3f(0.4, 0.4, 0.7);
    }
    else if (ID == 8) {
        glColor3f(0.3, 0.3, 0.3);
    }
    else if (ID == 9) {
        glColor3f(0.25, 0.25, 0.25);
    }

    glBegin(GL_QUADS);
    glVertex2i(static_cast<int>(x), static_cast<int>(y));
    glVertex2i(static_cast<int>(x) + 200, static_cast<int>(y));
    glVertex2i(static_cast<int>(x) + 200, static_cast<int>(y) + 60);
    glVertex2i(static_cast<int>(x), static_cast<int>(y) + 60);
    glEnd();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void Game::drawTextObjects()
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 1000);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);

    char gameTime[40];
    char collectedCarrots[30];
    char robotSpeed[30];
    char gameBeggining[50];
    char top3table[30];
    char top1[30];
    char top2[30];
    char top3[30];
    char showLastResult[50];
    char controls[20];
    char wsad[40];
    char zoom[30];
    char pauza[30];
    char backspace[30];
    char stopped[40];
    char zoomSize[40];

    if (!gameStarted) {
        speed = 0;
    }
    else if (speedRoverForward > speedRoverBackward) {
        speed = speedRoverForward;
    }
    else {
        speed = speedRoverBackward;
    }

    if (collisions.getCollectedCarrots() > 16) {
        speed = (speed / 0.15) * 60;
    }
    else if (collisions.getCollectedCarrots() > 12) {
        speed = (speed / 0.15) * 55;
    }
    else if (collisions.getCollectedCarrots() > 8) {
        speed = (speed / 0.15) * 50;
    }
    else if (collisions.getCollectedCarrots() > 4) {
        speed = (speed / 0.15) * 45;
    }
    else {
        speed = (speed / 0.15) * 40;
    }

    if (cameraPosZ == 12.0f) {
        zoomX = 0.5;
    }
    else if (cameraPosZ == 15.0f) {
        zoomX = 1.0;
    }
    else if (cameraPosZ == 18.0f) {
        zoomX = 1.5;
    }
    else if (cameraPosZ == 21.0f) {
        zoomX = 2.0;
    }
    else if (cameraPosZ == 24.0f) {
        zoomX = 2.5;
    }
    else if (cameraPosZ == 27.0f) {
        zoomX = 3.0;
    }
    else if (cameraPosZ == 30.0f) {
        zoomX = 3.5;
    }

    sprintf_s(gameTime, "Czas gry: %0.2f s + %0.1f s (kolizje)", time_span.count(), addedTimeForCollision);
    sprintf_s(collectedCarrots, "Zebrano %d/20 marchewek", collisions.getCollectedCarrots());
    sprintf_s(robotSpeed, "%0.2f km/h", speed);
    sprintf_s(gameBeggining, "      Aby zagrac, wcisnij [ENTER]");
    sprintf_s(top3table, "Tablica wynikow: ");
    sprintf_s(top1, "#1: %0.2f s", bestResults.size() > 0 ? bestResults[0] : 0.00);
    sprintf_s(top2, "#2: %0.2f s", bestResults.size() > 1 ? bestResults[1] : 0.00);
    sprintf_s(top3, "#3: %0.2f s", bestResults.size() > 2 ? bestResults[2] : 0.00);
    sprintf_s(showLastResult, "        Twoj ostatni wynik: %0.2f s", lastResult);
    sprintf_s(controls, "Sterowanie [TAB]");
    sprintf_s(wsad, "W/S/A/D - poruszanie pojazdem");
    sprintf_s(zoom, "Z - przybliz/oddal widok");
    sprintf_s(pauza, "P - pauza podczas gry");
    sprintf_s(backspace, "BACKSPACE - graj od nowa");
    sprintf_s(stopped, "      Aby wznowic gre, wcisnij [P]");
    sprintf_s(zoomSize, "Przyblizenie: %0.1fx", zoomX);

    if (gameStarted) {
        DrawText(gameTime, 20, 80, 20, 1);
        DrawText(collectedCarrots, 20, 150, 20, 1);
        DrawText(robotSpeed, 920, 80, 20, 2);
        DrawText(top3table, 20, 920, 20, 1);
        DrawText(top1, 20, 860, 20, 4);
        DrawText(top2, 20, 800, 20, 5);
        DrawText(top3, 20, 740, 20, 6);
        DrawText(controls, 800, 920, 20, 1);
        DrawText(zoomSize, 20, 220, 20, 1);
        if (tab) {
            DrawText(wsad, 800, 860, 20, 8);
            DrawText(zoom, 800, 800, 20, 9);
            DrawText(pauza, 800, 740, 20, 8);
            DrawText(backspace, 800, 680, 20, 9);
        }
        if (stop) {
            DrawText(stopped, 407, 530, 20, 7);
        }
    }
    else {
        DrawText(gameBeggining, 407, 530, 20, 7);
        if (lastResult > 0.00) {
            DrawText(showLastResult, 407, 450, 20, 3);
        }
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void Game::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(-10 + cameraPosX, cameraPosY, 7 + cameraPosZ, cameraPosX, cameraPosY, cameraPosZ, 0, 0, 1);
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);

    robot.draw();

    drawTextObjects();

    //grass and moutains
    drawObjects(tekstury[0], vectors[0], 1, 1, 1, 0, 0, 0, 1, 1, 1);
    drawObjects(tekstury[1], vectors[1], 1, 1, 1, 0, 0, 0.7, 1, 1, 1);

    //trees
    drawObjects(tekstury[2], vectors[2], 1, 1, 1, 5, 0, -0.9, 2, 2, 2);
    drawObjects(tekstury[3], vectors[3], 1, 1, 1, 6, 6, -0.9, 1.5, 1.5, 1.5);
    drawObjects(tekstury[4], vectors[4], 1, 1, 1, 4, 13, -0.9, 2.0, 2.0, 2.0);
    drawObjects(tekstury[2], vectors[2], 1, 1, 1, -18, 18, -0.9, 2.0, 2.0, 2.0);
    drawObjects(tekstury[2], vectors[2], 1, 1, 1, 12, 24, -0.9, 1.5, 1.5, 1.5);
    drawObjects(tekstury[3], vectors[3], 1, 1, 1, 14, -13, -0.9, 1.5, 1.5, 1.5);
    drawObjects(tekstury[3], vectors[3], 1, 1, 1, 7, -23, -0.4, 1.0, 1.0, 1.0);
    drawObjects(tekstury[4], vectors[4], 1, 1, 1, -15, -19, -0.9, 2.0, 2.0, 2.0);
    drawObjects(tekstury[2], vectors[2], 1, 1, 1, 19, 28, -0.9, 1.5, 1.5, 1.5);
    drawObjects(tekstury[4], vectors[4], 1, 1, 1, -7, 32, -0.4, 1.0, 1.0, 1.0);
    drawObjects(tekstury[3], vectors[3], 1, 1, 1, -2, 31, -0.4, 1.0, 1.0, 1.0);
    drawObjects(tekstury[3], vectors[3], 1, 1, 1, 3, 25, -0.9, 1.5, 1.5, 1.5);
    drawObjects(tekstury[2], vectors[2], 1, 1, 1, -5, 10, -0.9, 2.0, 2.0, 2.0);
    drawObjects(tekstury[2], vectors[2], 1, 1, 1, -12, -8, -0.9, 1.5, 1.5, 1.5);
    drawObjects(tekstury[4], vectors[4], 1, 1, 1, 1, -13, -0.9, 2.0, 2.0, 2.0);
    drawObjects(tekstury[3], vectors[3], 1, 1, 1, 19, -26, -0.9, 1.5, 1.5, 1.5);
    drawObjects(tekstury[4], vectors[4], 1, 1, 1, -5, -30, -0.4, 1.0, 1.0, 1.0);
    drawObjects(tekstury[2], vectors[2], 1, 1, 1, -6, 20, -0.9, 1.5, 1.5, 1.5);
    drawObjects(tekstury[3], vectors[3], 1, 1, 1, -15, 28, -0.9, 1.5, 1.5, 1.5);
    drawObjects(tekstury[2], vectors[2], 1, 1, 1, -14, 5, -0.9, 1.5, 1.5, 1.5);
    drawObjects(tekstury[3], vectors[3], 1, 1, 1, -7, -16, -0.9, 2.0, 2.0, 2.0);
    drawObjects(tekstury[2], vectors[2], 1, 1, 1, 11, -28, -0.4, 1.0, 1.0, 1.0);
    drawObjects(tekstury[4], vectors[4], 1, 1, 1, -16, -26, -0.9, 2.0, 2.0, 2.0);
    drawObjects(tekstury[4], vectors[4], 1, 1, 1, -12, 27, -0.4, 1.0, 1.0, 1.0);

    //carrots
    indexToDelete = collisions.getIndexToDelete();
    sort(indexToDelete.begin(), indexToDelete.end(), greater<int>());

    for (int i = 0; i < randCarrotsXY.size(); i++) {
        if (find(indexToDelete.begin(), indexToDelete.end(), i) == indexToDelete.end()) {
            drawObjects(tekstury[5], vectors[5], 1, 1, 1, randCarrotsXY[i].first, randCarrotsXY[i].second, 0.75 + movingCarrot, 0.8, 0.8, 0.8);
            drawObjects(tekstury[6], vectors[6], 1, 1, 1, randCarrotsXY[i].first, randCarrotsXY[i].second, 0.1 + movingCarrot, 1.0, 1.0, 1.0);
        }
    }

    if (!up) {
        movingCarrot -= 0.0025;
        if (movingCarrot <= -0.1 + tolerance)
            up = true;
    }
    else if (up) {
        movingCarrot += 0.0025;
        if (movingCarrot >= 0.1 - tolerance)
            up = false;
    }

    glutSwapBuffers();
}

void Game::reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(20.0, (float)width / (float)height, 1.0, 100.0);
}
