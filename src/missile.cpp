#include "main.h"
#include "missile.h"
#define N_TRNG 100

Missile::Missile(float rot, float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = rot;
    this->radius = 2;
    this->flength = 3;
    this->rlength = 7;
    this->speed = 4;

    GLfloat vertex_buffer_data[27*N_TRNG], vertex_buffer_color[27*N_TRNG];

    for (int i=0; i<9*N_TRNG; i+=9) {

        vertex_buffer_data[i] = 0.0f;
        vertex_buffer_data[i+1] = 0.0f;
        vertex_buffer_data[i+2] = -flength;

        vertex_buffer_data[i+3] = radius*cos((i/9)*(2*M_PI/N_TRNG));
        vertex_buffer_data[i+4] = radius*sin((i/9)*(2*M_PI/N_TRNG));
        vertex_buffer_data[i+5] = 0.0f;

        vertex_buffer_data[i+6] = radius*cos((i/9+1)*(2*M_PI/N_TRNG));
        vertex_buffer_data[i+7] = radius*sin((i/9+1)*(2*M_PI/N_TRNG));
        vertex_buffer_data[i+8] = 0.0f;

    }

    for (int i=0; i<18*N_TRNG; i+=18) {

        vertex_buffer_data[9*N_TRNG+i] = radius*cos((i/18)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+i+1] = radius*sin((i/18)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+i+2] = rlength;

        vertex_buffer_data[9*N_TRNG+i+3] = radius*cos((i/18)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+i+4] = radius*sin((i/18)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+i+5] = 0.0f;

        vertex_buffer_data[9*N_TRNG+i+6] = radius*cos((i/18+1)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+i+7] = radius*sin((i/18+1)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+i+8] = 0.0f;

        vertex_buffer_data[9*N_TRNG+9+i] = radius*cos((i/18)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+9+i+1] = radius*sin((i/18)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+9+i+2] = rlength;

        vertex_buffer_data[9*N_TRNG+9+i+3] = radius*cos((i/18+1)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+9+i+4] = radius*sin((i/18+1)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+9+i+5] = rlength;

        vertex_buffer_data[9*N_TRNG+9+i+6] = radius*cos((i/18+1)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+9+i+7] = radius*sin((i/18+1)*(2*M_PI/N_TRNG));
        vertex_buffer_data[9*N_TRNG+9+i+8] = 0.0f;

    }

    for (int i=0; i<9*N_TRNG; i+=9) {

        vertex_buffer_color[i] = 0.0f;
        vertex_buffer_color[i+1] = 0.0f;
        vertex_buffer_color[i+2] = 0.0f;

        vertex_buffer_color[i+3] = 0.0f;
        vertex_buffer_color[i+4] = 0.0f;
        vertex_buffer_color[i+5] = 0.0f;

        vertex_buffer_color[i+6] = 0.0f;
        vertex_buffer_color[i+7] = 0.0f;
        vertex_buffer_color[i+8] = 0.0f;

    }

    for (int i=0; i<18*N_TRNG; i+=18) {

        vertex_buffer_color[9*N_TRNG+i] = 0.5f;
        vertex_buffer_color[9*N_TRNG+i+1] = 0.5f;
        vertex_buffer_color[9*N_TRNG+i+2] = 0.0f;

        vertex_buffer_color[9*N_TRNG+i+3] = 0.5f;
        vertex_buffer_color[9*N_TRNG+i+4] = 0.5f;
        vertex_buffer_color[9*N_TRNG+i+5] = 0.0f;

        vertex_buffer_color[9*N_TRNG+i+6] = 0.5f;
        vertex_buffer_color[9*N_TRNG+i+7] = 0.5f;
        vertex_buffer_color[9*N_TRNG+i+8] = 0.0f;

        vertex_buffer_color[9*N_TRNG+9+i] = 0.5f;
        vertex_buffer_color[9*N_TRNG+9+i+1] = 0.5f;
        vertex_buffer_color[9*N_TRNG+9+i+2] = 0.0f;

        vertex_buffer_color[9*N_TRNG+9+i+3] = 0.5f;
        vertex_buffer_color[9*N_TRNG+9+i+4] = 0.5f;
        vertex_buffer_color[9*N_TRNG+9+i+5] = 0.0f;

        vertex_buffer_color[9*N_TRNG+9+i+6] = 0.5f;
        vertex_buffer_color[9*N_TRNG+9+i+7] = 0.5f;
        vertex_buffer_color[9*N_TRNG+9+i+8] = 0.0f;

    }

    this->object = create3DObject(GL_TRIANGLES, 9*N_TRNG, vertex_buffer_data, vertex_buffer_color, GL_FILL);
}

void Missile::draw(glm::mat4 VP) {
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

void Missile::tick() {

}










