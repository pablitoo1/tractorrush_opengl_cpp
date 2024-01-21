#include "Przod.h"

Przod::Przod(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Przod::draw() {
    float szerokosc = 1.8f;
    float wysokosc = 0.7f;
    float glebokosc = 1.0f;


    glPushMatrix();
    glTranslatef(x, y, z);

    glBegin(GL_TRIANGLE_STRIP);
    glColor3d(0.2, 0.4, 0.2);
    for (float stepX = 0.0f; stepX <= szerokosc; stepX += 0.02f)
    {
        glVertex3f(stepX, 0.0f, 0.0f);
        glVertex3f(stepX, glebokosc, 0.0f);
    }
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3d(0.2, 0.4, 0.2);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(szerokosc, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, wysokosc);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3d(0.2, 0.4, 0.2);
    glVertex3f(0.0f, glebokosc, 0.0f);
    glVertex3f(szerokosc, glebokosc, 0.0f);
    glVertex3f(0.0f, glebokosc, wysokosc);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3d(0.2, 0.4, 0.2);
    for (float stepY= 0.0f; stepY <= glebokosc; stepY += 0.02f)
    {
        glVertex3f(0.0f, stepY, 0.0f);
        glVertex3f(0.0f, stepY, wysokosc);
    }
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3d(0.2, 0.4, 0.2);
    glVertex3f(szerokosc, 0.0f, 0.0f);
    glVertex3f(szerokosc, glebokosc, 0.0f);
    glVertex3f(0.0f, 0.0f, wysokosc);
    glVertex3f(0.0f, glebokosc, wysokosc);
    glEnd();
    

    glPopMatrix();
}