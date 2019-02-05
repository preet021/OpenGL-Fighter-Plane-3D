#include "main.h"
#include "volcano.h"

Volcano::Volcano(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->side = 50;

    GLfloat vertex_buffer_data[] = {
        
        50.0f, 0.0f, -50.0f,
        50.0f, 0.0f, 50.0f,
        0.0f, 70.0f, 0.0f,

        50.0f, 0.0f, 50.0f,
        -50.0f, 0.0f, 50.0f,
        0.0f, 70.0f, 0.0f,

        -50.0f, 0.0f, 50.0f,
        -50.0f, 0.0f, -50.0f,
        0.0f, 70.0f, 0.0f,

        -50.0f, 0.0f, -50.0f,
        50.0f, 0.0f, -50.0f,
        0.0f, 70.0f, 0.0f,

    };

    GLfloat vertex_buffer_color[] = {
        
        139/255.0f, 69/255.0f, 19/255.0f,
        139/255.0f, 69/255.0f, 19/255.0f,
        1, 69/255.0f, 0.0f,

        139/255.0f, 69/255.0f, 19/255.0f,
        139/255.0f, 69/255.0f, 19/255.0f,
        1, 69/255.0f, 0.0f,

        139/255.0f, 69/255.0f, 19/255.0f,
        139/255.0f, 69/255.0f, 19/255.0f,
        1, 69/255.0f, 0.0f,

        139/255.0f, 69/255.0f, 19/255.0f,
        139/255.0f, 69/255.0f, 19/255.0f,
        1, 69/255.0f, 0.0f,

    };
    
    this->object = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data, vertex_buffer_color, GL_FILL);
}

void Volcano::draw(glm::mat4 VP) {
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
