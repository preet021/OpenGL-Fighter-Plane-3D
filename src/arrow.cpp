#include "main.h"
#include "arrow.h"
#include <iostream>
using namespace std;
Arrow::Arrow(float x, float y, float z, float rot) {
    this->position = glm::vec3(x, y, z);
    this->rotation = rot;

    GLfloat vertex_buffer_data[] = {

        -0.5, 0, 0,
        0.5, 0, 0,
        0.5, 1, 0,

        0.5, 1, 0,
        -0.5, 1, 0,
        -0.5, 0, 0,

        -1, 1, 0,
        1, 1, 0,
        0, 2, 0

    };

    color_t r = {255, 0, 0};
    
    this->object = create3DObject(GL_TRIANGLES, 9, vertex_buffer_data, r, GL_FILL);
}

void Arrow::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    //draw3DObject(this->ob1);
}
