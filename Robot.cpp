#include "Robot.h"

//Robot::Robot(float rotationAngle, float x, float y, float z) {
//    this->x = x;
//    this->y = y;
//    this->z = z;
//    this->rotationAngle = rotationAngle;
//    isA = false;
//    isD = false;
//    inclinationDegree = 0.0f;
//}

Robot::Robot() {
    x = 0.0f;
    y = 0.0f;
    z = 0.5f;
    rotationAngle = 0.0f;
    isA = false;
    isD = false;
    inclinationDegree = 0.0f;
}

void Robot::draw() {

    glPushMatrix();

    glTranslatef(x, y, z);

    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);

    glRotatef(inclinationDegree, 1.0f, 0.0f, 0.0f);

    glTranslatef(-x, -y, -z);

    Korpus korpus(x, y, z); //wymiary: 3.0f, 1.0f, 0.4f
    korpus.draw();

    //KO£A LEWE
    for (float i = 0; i < 3; i++) {
        Kolo kolo(x - 1.5f + i * 1.5f, y + 0.63f, z-0.2f);       //wymiary 0.5f, 0.5f
        kolo.setTexture("textures/tire2.png");
        kolo.draw();
    }

    //KO£A PRAWE
    for (float i = 0; i < 3; i++) {
        Kolo kolo(x - 1.5f + i * 1.5f, y - 0.63f, z-0.2f);       //wymiary 0.5f, 0.5f
        kolo.setTexture("textures/tire.jpg");
        kolo.draw();
    }

    for (float i = 0; i < 3; i++) {
        Lacznik lacznik(x - 1.5f + i * 1.5f, y, z - 0.2f);
        lacznik.draw();
    }
    for (float i = 0; i < 2; i++) {
        Tablica tablica(x - 1.5f + i * 3.0f, y, z);
        tablica.draw();
    }
    Przod przod(x-0.3f, y-0.5f, z + 0.2f);
    przod.draw();

    Tyl tyl(x-0.9f, y, z+0.65f);
    tyl.draw();

    for (float i = 0.0; i < 2; i++) {
        Swiatlo swiatlo(x - 1.5f, y - 0.35f + 0.7 * i, z);
        swiatlo.draw();
    }
    for (float i = 0.0; i < 2; i++) {
        Swiatlo swiatlo(x + 1.5f, y - 0.35f + 0.7 * i, z);
        swiatlo.draw();
    }
    for (float i = 0.0; i < 2; i++) {
        Slupek slupek(x - 1.45f, y + 0.45f - 0.9 * i, z + 1.25f);
        slupek.draw();
    }
    for (float i = 0.0; i < 2; i++) {
        Slupek slupek(x - 0.35f, y + 0.45f - 0.9 * i, z + 1.25f);
        slupek.draw();
    }

    Dach dach(x - 0.9f, y, z + 1.5f);
    dach.draw();

    for (float i = 0.0; i < 2; i++) {
        Rura rura(x + 0.3f, y + 0.25f + 0.15 * i, z + 1.10f);
        rura.draw();
        Tlumik tlumik(x + 0.3f, y + 0.25f + 0.15 * i, z + 1.10f);
        tlumik.draw();
    }

    for (int i = 0.0; i < 2; i++) {
        if (i == 0) {
            Kierunkowskaz kierunkowskaz(x - 0.3f, y + 0.5f - i * 1.0, z + 0.55f, isA);
            kierunkowskaz.draw();
        }
        else {
            Kierunkowskaz kierunkowskaz(x - 0.3f, y + 0.5f - i * 1.0, z + 0.55f, isD);
            kierunkowskaz.draw();
        }
    }

    glPopMatrix();

}

void Robot::setRotate(float isA, float isD)
{
    this->isA = isA;
    this->isD = isD;
}