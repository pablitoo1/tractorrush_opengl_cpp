#include "Dach.h"

Dach::Dach(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Dach::draw() {
    glPushMatrix();
    glTranslatef(x, y, z);

    float halfWidth = 1.2f / 2.0f;
    float halfHeight = 1.0f / 2.0f;
    float halfDepth = 0.1f / 2.0f;

    glColor3f(1.0f, 0.1f, 0.1f);
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