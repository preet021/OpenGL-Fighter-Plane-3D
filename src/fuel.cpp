#include "main.h"
#include "fuel.h"

Fuel::Fuel(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 180;
    this->side = 5.0f;

    GLfloat vertex_buffer_data[] = {
        -5.0f,-5.0f,-2.0f,
        -5.0f,-5.0f, 2.0f,
        -5.0f, 5.0f, 2.0f,

        5.0f, 5.0f,-2.0f,
        -5.0f,-5.0f,-2.0f,
        -5.0f, 5.0f,-2.0f,
        
        5.0f,-5.0f, 2.0f,
        -5.0f,-5.0f,-2.0f,
        5.0f,-5.0f,-2.0f,
        
        5.0f, 5.0f,-2.0f,
        5.0f,-5.0f,-2.0f,
        -5.0f,-5.0f,-2.0f,
        
        -5.0f,-5.0f,-2.0f,
        -5.0f, 5.0f, 2.0f,
        -5.0f, 5.0f,-2.0f,
        
        5.0f,-5.0f, 2.0f,
        -5.0f,-5.0f, 2.0f,
        -5.0f,-5.0f,-2.0f,
        
        -5.0f, 5.0f, 2.0f,
        -5.0f,-5.0f, 2.0f,
        5.0f,-5.0f, 2.0f,
        
        5.0f, 5.0f, 2.0f,
        5.0f,-5.0f,-2.0f,
        5.0f, 5.0f,-2.0f,
        
        5.0f,-5.0f,-2.0f,
        5.0f, 5.0f, 2.0f,
        5.0f,-5.0f, 2.0f,
        
        5.0f, 5.0f, 2.0f,
        5.0f, 5.0f,-2.0f,
        -5.0f, 5.0f,-2.0f,
        
        5.0f, 5.0f, 2.0f,
        -5.0f, 5.0f,-2.0f,
        -5.0f, 5.0f, 2.0f,
        
        5.0f, 5.0f, 2.0f,
        -5.0f, 5.0f, 2.0f,
        5.0f,-5.0f, 2.0f
    };

    GLfloat vertex_buffer_color[] = {
        -5.0f,-5.0f,-2.0f,
        -5.0f,-5.0f, 2.0f,
        -5.0f, 5.0f, 2.0f,

        5.0f, 5.0f,-2.0f,
        -5.0f,-5.0f,-2.0f,
        -5.0f, 5.0f,-2.0f,
        
        5.0f,-5.0f, 2.0f,
        -5.0f,-5.0f,-2.0f,
        5.0f,-5.0f,-2.0f,
        
        5.0f, 5.0f,-2.0f,
        5.0f,-5.0f,-2.0f,
        -5.0f,-5.0f,-2.0f,
        
        -5.0f,-5.0f,-2.0f,
        -5.0f, 5.0f, 2.0f,
        -5.0f, 5.0f,-2.0f,
        
        5.0f,-5.0f, 2.0f,
        -5.0f,-5.0f, 2.0f,
        -5.0f,-5.0f,-2.0f,
        
        -5.0f, 5.0f, 2.0f,
        -5.0f,-5.0f, 2.0f,
        5.0f,-5.0f, 2.0f,
        
        5.0f, 5.0f, 2.0f,
        5.0f,-5.0f,-2.0f,
        5.0f, 5.0f,-2.0f,
        
        5.0f,-5.0f,-2.0f,
        5.0f, 5.0f, 2.0f,
        5.0f,-5.0f, 2.0f,
        
        5.0f, 5.0f, 2.0f,
        5.0f, 5.0f,-2.0f,
        -5.0f, 5.0f,-2.0f,
        
        5.0f, 5.0f, 2.0f,
        -5.0f, 5.0f,-2.0f,
        -5.0f, 5.0f, 2.0f,
        
        5.0f, 5.0f, 2.0f,
        -5.0f, 5.0f, 2.0f,
        5.0f,-5.0f, 2.0f
    };

    this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, vertex_buffer_color, GL_FILL);
}

void Fuel::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    //draw3DObject(this->ob1);
}

void Fuel::tick() {
    // this->position.y -= speed;
}

