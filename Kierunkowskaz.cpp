#include "Kierunkowskaz.h"

Kierunkowskaz::Kierunkowskaz(float x, float y, float z, bool isTurn) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->isTurn = isTurn;
}

void Kierunkowskaz::draw() {
    glPushMatrix();
    glTranslatef(x, y, z);

    float halfWidth = 0.1f / 2.0f;
    float halfHeight = 0.05f / 2.0f;
    float halfDepth = 0.05f / 2.0f;

    if (!isTurn) {
        glColor3f(1.0f, 0.7f, 0.0f);
    }
    else {
        glColor3f(1.0f, 0.4f, 0.0f);
    }

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