#include "Tablica.h"

Tablica::Tablica(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Tablica::draw() {
    glPushMatrix();
    glTranslatef(x, y, z);

    float halfWidth = 0.05f / 2.0f;
    float halfHeight = 0.45f / 2.0f;
    float halfDepth = 0.2f / 2.0f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);

    // Przód
    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, -halfHeight, halfDepth);

    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, halfDepth);

    // Ty³
    glVertex3f(halfWidth, halfHeight, -halfDepth);
    glVertex3f(-halfWidth, halfHeight, -halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);

    glVertex3f(halfWidth, halfHeight, -halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glVertex3f(halfWidth, -halfHeight, -halfDepth);

    // Góra
    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, halfHeight, -halfDepth);

    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, halfHeight, -halfDepth);
    glVertex3f(-halfWidth, halfHeight, -halfDepth);

    // Dó³
    glVertex3f(halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);

    glVertex3f(halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glVertex3f(halfWidth, -halfHeight, -halfDepth);

    // Lewa strona
    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);

    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glVertex3f(-halfWidth, halfHeight, -halfDepth);

    // Prawa strona
    glVertex3f(halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, -halfHeight, halfDepth);
    glVertex3f(halfWidth, -halfHeight, -halfDepth);

    glVertex3f(halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, -halfHeight, -halfDepth);
    glVertex3f(halfWidth, halfHeight, -halfDepth);

    glEnd();

    glPopMatrix();




    //////obwodka czarna
    glPushMatrix();
    glTranslatef(x, y, z);

    halfWidth = 0.02f / 2.0f;
    halfHeight = 0.5f / 2.0f;
    halfDepth = 0.25f / 2.0f;


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);

    // Przód
    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, -halfHeight, halfDepth);

    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, halfDepth);

    // Ty³
    glVertex3f(halfWidth, halfHeight, -halfDepth);
    glVertex3f(-halfWidth, halfHeight, -halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);

    glVertex3f(halfWidth, halfHeight, -halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glVertex3f(halfWidth, -halfHeight, -halfDepth);

    // Góra
    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, halfHeight, -halfDepth);

    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, halfHeight, -halfDepth);
    glVertex3f(-halfWidth, halfHeight, -halfDepth);

    // Dó³
    glVertex3f(halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);

    glVertex3f(halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glVertex3f(halfWidth, -halfHeight, -halfDepth);

    // Lewa strona
    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);

    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glVertex3f(-halfWidth, halfHeight, -halfDepth);

    // Prawa strona
    glVertex3f(halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, -halfHeight, halfDepth);
    glVertex3f(halfWidth, -halfHeight, -halfDepth);

    glVertex3f(halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, -halfHeight, -halfDepth);
    glVertex3f(halfWidth, halfHeight, -halfDepth);

    glEnd();

    glPopMatrix();
}