#include "main.h"
#include "ring.h"
#define N_BLCK 100

Ring::Ring(float x, float y, float z) {

    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->radius = 10;

    GLfloat vertex_buffer_data[18*N_BLCK];

    double theta = 0, phi = 2 * M_PI / N_BLCK, ax, bx, cx, dx, ay, by, cy, dy, thickness = 1;

    for (int i=0; i<18*N_BLCK; i+=18) {
        ax = (radius + thickness) * cos(theta);
        bx = radius * cos(theta);
        cx = (radius + thickness) * cos(theta + phi);
        dx = radius * cos(theta + phi);

        ay = (radius + thickness) * sin(theta);
        by = radius * sin(theta);
        cy = (radius + thickness) * sin(theta + phi);
        dy = radius * sin(theta + phi);

        vertex_buffer_data[i] = ax;
        vertex_buffer_data[i + 1] = ay;
        vertex_buffer_data[i + 2] = 0.0f;

        vertex_buffer_data[3 + i]  = bx;
        vertex_buffer_data[3 + i + 1] = by;
        vertex_buffer_data[3 + i + 2] = 0.0f;

        vertex_buffer_data[6 + i] = dx;
        vertex_buffer_data[6 + i + 1] = dy;
        vertex_buffer_data[6 + i + 2] = 0.0f;

        vertex_buffer_data[9 + i] = ax;
        vertex_buffer_data[9 + i + 1] = ay;
        vertex_buffer_data[9 + i + 2] = 0.0f;

        vertex_buffer_data[9 + 3 + i]  = cx;
        vertex_buffer_data[9 + 3 + i + 1] = cy;
        vertex_buffer_data[9 + 3 + i + 2] = 0.0f;

        vertex_buffer_data[9 + 6 + i] = dx;
        vertex_buffer_data[9 + 6 + i + 1] = dy;
        vertex_buffer_data[9 + 6 + i + 2] = 0.0f;
        
        theta += phi;
    }
    
    color_t c = {0, 0, 0};

    this->object = create3DObject(GL_TRIANGLES, 6*N_BLCK, vertex_buffer_data, c, GL_FILL);
}

void Ring::draw(glm::mat4 VP) {
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

void Ring::tick() {
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

