// Kolo.cpp
#include "Kolo.h"
#include "loader.h"
//#include "loader.cpp"

Kolo::Kolo(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    sides = 50;  // Domyœlna liczba boków kola
}

void Kolo::setTexture(const char* textureName) {
    this->textureName = textureName;
}


void Kolo::draw() {
    glPushMatrix();
    glTranslatef(x, y, z);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, loadTexture(textureName));

    // Rysuj górn¹ powierzchniê kola
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.0f, height / 2.0f, 0.0f);

    for (int i = 0; i <= sides; i++) {
        float angle = 2.0f * 3.14 * (float)i / (float)sides;
        glTexCoord2f(0.5f * cos(angle) + 0.5f, 0.5f * sin(angle) + 0.5f);
        glVertex3f(radius * cos(angle), height / 2.0f, radius * sin(angle));
    }
    glEnd();

    // Rysuj doln¹ powierzchniê kola
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.0f, -height / 2.0f, 0.0f);

    for (int i = 0; i <= sides; i++) {
        float angle = 2.0f * 3.14 * (float)i / (float)sides;
        glTexCoord2f(0.5f * cos(angle) + 0.5f, 0.5f * sin(angle) + 0.5f);
        glVertex3f(radius * cos(angle), -height / 2.0f, radius * sin(angle));
    }
    glEnd();

    // Rysuj boki kola za pomoc¹ trójk¹tów
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < sides; i++) {
        float angle1 = 2.0f * 3.14 * (float)i / (float)sides;
        float angle2 = 2.0f * 3.14 * (float)(i + 1) / (float)sides;

        // Górna trójk¹tna œciana
        glTexCoord2f(0.5f * cos(angle1) + 0.5f, 0.5f * sin(angle1) + 0.5f);
        glVertex3f(radius * cos(angle1), height / 2.0f, radius * sin(angle1));

        glTexCoord2f(0.5f * cos(angle2) + 0.5f, 0.5f * sin(angle2) + 0.5f);
        glVertex3f(radius * cos(angle2), height / 2.0f, radius * sin(angle2));

        glTexCoord2f(0.5f * cos(angle2) + 0.5f, 0.5f * sin(angle2) + 0.5f);
        glVertex3f(radius * cos(angle2), -height / 2.0f, radius * sin(angle2));

        // Dolna trójk¹tna œciana
        glTexCoord2f(0.5f * cos(angle2) + 0.5f, 0.5f * sin(angle2) + 0.5f);
        glVertex3f(radius * cos(angle2), -height / 2.0f, radius * sin(angle2));

        glTexCoord2f(0.5f * cos(angle1) + 0.5f, 0.5f * sin(angle1) + 0.5f);
        glVertex3f(radius * cos(angle1), -height / 2.0f, radius * sin(angle1));

        glTexCoord2f(0.5f * cos(angle1) + 0.5f, 0.5f * sin(angle1) + 0.5f);
        glVertex3f(radius * cos(angle1), height / 2.0f, radius * sin(angle1));
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    glPopMatrix();
}