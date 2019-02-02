#include "main.h"
#include "fan.h"

Fan::Fan(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->speed = 20;
    this->radius = 10;

    GLfloat vertex_buffer_data[] = {
        0, radius, 0,
        1, 0, 0,
        -1, 0, 0,
        0, -radius, 0,
        1, 0, 0,
        -1, 0, 0,
    };

    color_t b = {0, 0, 0};

    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, b, GL_FILL);
}

void Fan::draw(glm::mat4 VP, float vx, float vy, float vz) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(vx/sqrt(vx*vx+vy*vy+vz*vz), vy/sqrt(vx*vx+vy*vy+vz*vz), vz/sqrt(vx*vx+vy*vy+vz*vz)));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    //draw3DObject(this->ob1);
}

void Fan::tick() {
    this->rotation += speed;
    if (this->rotation > 360)
        this->rotation -= 360;
}

