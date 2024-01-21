#include "Dependencies/glew-2.1.0/include/GL/glew.h"
#define TINYOBJLOADER_IMPLEMENTATION
#include "tinyobjloader/tiny_obj_loader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "loader.h"

GLuint loadTexture(const char* filename) {
    GLuint texture;
    glewInit();
    //glewExperimental = GL_TRUE;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, STBI_rgb);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    stbi_image_free(data);
    return texture;
}

std::pair<std::vector<float>, std::vector<float>> loadObjFile(const std::string& filename, GLuint textureName)
{
    std::vector<float> vertices;
    std::vector<float> textures;
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, filename.c_str());
    GLuint textureID = textureName;

    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 0]);
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 1]);
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 2]);

            if (!attrib.texcoords.empty()) {
                textures.push_back(attrib.texcoords[2 * index.texcoord_index + 0]);
                textures.push_back(attrib.texcoords[2 * index.texcoord_index + 1]);
            }
        }
    }
    return std::make_pair(vertices, textures);
}

void drawObjects(GLuint textureName, std::pair<std::vector<float>, std::vector<float>> vectors, GLfloat red, GLfloat green, GLfloat blue, float x, float y, float z, float scaleX, float scaleY, float scaleZ)
{
    GLuint textureID = textureName;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_TRIANGLES);
    glColor3f(red, green, blue);
    int textureIndex = 0;
    for (size_t i = 0; i < vectors.first.size(); i += 3) {
        if (textureIndex < vectors.second.size()) {
            glTexCoord2f(vectors.second[textureIndex], vectors.second[textureIndex + 1]);
            textureIndex += 2;
        }
        glVertex3f(scaleX * vectors.first[i] + x, scaleY * vectors.first[i + 1] + y, scaleZ * vectors.first[i + 2] + z);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}