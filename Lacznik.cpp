#include "Lacznik.h"

Lacznik::Lacznik(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    sides = 50;  // Domyœlna liczba boków kola
}

void Lacznik::draw() {
    glPushMatrix();
    glTranslatef(x, y, z);

    // Rysuj górn¹ powierzchniê kola
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, height / 2.0f, 0.0f);
    for (int i = 0; i <= sides; i++) {
        float angle = 2.0f * 3.14 * (float)i / (float)sides;
        glVertex3f(radius * cos(angle), height / 2.0f, radius * sin(angle));
    }
    glEnd();

    // Rysuj doln¹ powierzchniê kola
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, -height / 2.0f, 0.0f);
    for (int i = 0; i <= sides; i++) {
        float angle = 2.0f * 3.14 * (float)i / (float)sides;
        glVertex3f(radius * cos(angle), -height / 2.0f, radius * sin(angle));
    }
    glEnd();

    // Rysuj boki kola za pomoc¹ trójk¹tów
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < sides; i++) {
        float angle1 = 2.0f * 3.14 * (float)i / (float)sides;
        float angle2 = 2.0f * 3.14 * (float)(i + 1) / (float)sides;

        // Górna trójk¹tna œciana
        glVertex3f(radius * cos(angle1), height / 2.0f, radius * sin(angle1));
        glVertex3f(radius * cos(angle2), height / 2.0f, radius * sin(angle2));
        glVertex3f(radius * cos(angle2), -height / 2.0f, radius * sin(angle2));

        // Dolna trójk¹tna œciana
        glVertex3f(radius * cos(angle2), -height / 2.0f, radius * sin(angle2));
        glVertex3f(radius * cos(angle1), -height / 2.0f, radius * sin(angle1));
        glVertex3f(radius * cos(angle1), height / 2.0f, radius * sin(angle1));
    }
    glEnd();

    glPopMatrix();
}