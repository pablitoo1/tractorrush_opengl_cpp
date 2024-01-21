#include "Korpus.h"

Korpus::Korpus(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Korpus::draw() {
    glPushMatrix();
    glTranslatef(x, y, z);

    float halfWidth = 3.0f / 2.0f;
    float halfHeight = 1.0f / 2.0f;
    float halfDepth = 0.4f / 2.0f;

    glColor3f(0.2f, 0.2f, 0.2f);
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