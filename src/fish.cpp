#include "main.h"
#include "fish.h"

Fish::Fish(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = rand()%180;

    GLfloat vertex_buffer_data[] = {
        -5.0f,-5.0f,-5.0f,
        -5.0f,-5.0f, 5.0f,
        -5.0f, 5.0f, 5.0f,
        5.0f, 5.0f,-5.0f,
        -5.0f,-5.0f,-5.0f,
        -5.0f, 5.0f,-5.0f,
        5.0f,-5.0f, 5.0f,
        -5.0f,-5.0f,-5.0f,
        5.0f,-5.0f,-5.0f,
        5.0f, 5.0f,-5.0f,
        5.0f,-5.0f,-5.0f,
        -5.0f,-5.0f,-5.0f,
        -5.0f,-5.0f,-5.0f,
        -5.0f, 5.0f, 5.0f,
        -5.0f, 5.0f,-5.0f,
        5.0f,-5.0f, 5.0f,
        -5.0f,-5.0f, 5.0f,
        -5.0f,-5.0f,-5.0f,
        -5.0f, 5.0f, 5.0f,
        -5.0f,-5.0f, 5.0f,
        5.0f,-5.0f, 5.0f,
        5.0f, 5.0f, 5.0f,
        5.0f,-5.0f,-5.0f,
        5.0f, 5.0f,-5.0f,
        5.0f,-5.0f,-5.0f,
        5.0f, 5.0f, 5.0f,
        5.0f,-5.0f, 5.0f,
        5.0f, 5.0f, 5.0f,
        5.0f, 5.0f,-5.0f,
        -5.0f, 5.0f,-5.0f,
        5.0f, 5.0f, 5.0f,
        -5.0f, 5.0f,-5.0f,
        -5.0f, 5.0f, 5.0f,
        5.0f, 5.0f, 5.0f,
        -5.0f, 5.0f, 5.0f,
        5.0f,-5.0f, 5.0f
    };

    color_t c = {25, 100, 20};
    
    this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, c, GL_FILL);
}

void Fish::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}
