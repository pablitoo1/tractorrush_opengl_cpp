#include "Tlumik.h"

Tlumik::Tlumik(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    sides = 50;  // Domy�lna liczba bok�w kola
}

void Tlumik::draw() {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

    // Rysuj g�rn� powierzchni� kola
    glColor3f(0.6f, 0.5f, 0.6f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, height / 2.0f, 0.0f);
    for (int i = 0; i <= sides; i++) {
        float angle = 2.0f * 3.14 * (float)i / (float)sides;
        glVertex3f(radius * cos(angle), height / 2.0f, radius * sin(angle));
    }
    glEnd();

    // Rysuj doln� powierzchni� kola
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, -height / 2.0f, 0.0f);
    for (int i = 0; i <= sides; i++) {
        float angle = 2.0f * 3.14 * (float)i / (float)sides;
        glVertex3f(radius * cos(angle), -height / 2.0f, radius * sin(angle));
    }
    glEnd();

    // Rysuj boki kola za pomoc� tr�jk�t�w
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < sides; i++) {
        float angle1 = 2.0f * 3.14 * (float)i / (float)sides;
        float angle2 = 2.0f * 3.14 * (float)(i + 1) / (float)sides;

        // G�rna tr�jk�tna �ciana
        glVertex3f(radius * cos(angle1), height / 2.0f, radius * sin(angle1));
        glVertex3f(radius * cos(angle2), height / 2.0f, radius * sin(angle2));
        glVertex3f(radius * cos(angle2), -height / 2.0f, radius * sin(angle2));

        // Dolna tr�jk�tna �ciana
        glVertex3f(radius * cos(angle2), -height / 2.0f, radius * sin(angle2));
        glVertex3f(radius * cos(angle1), -height / 2.0f, radius * sin(angle1));
        glVertex3f(radius * cos(angle1), height / 2.0f, radius * sin(angle1));
    }
    glEnd();

    glPopMatrix();
}
