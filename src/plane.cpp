#include "plane.h"
#include "main.h"
#define N_TRNG 100

Plane::Plane(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = glm::vec3(0, 0, 0);
    this->radius = 4;
    this->flength = 12;
    this->rlength = 20;
    this->rwlength = 6;
    this->wlength = 15;
    this->tilt = 0.5;
    this->maxtilt = 30;
    this->speed_z = 1;
    this->speed_y = -0.1;
    this->acc_z = 0.003;
    this->fuel = 10;
    this->maxfuel = 10;
    this->maxalt = 500;

    GLfloat vertex_buffer_data[N_TRNG*27+27+18], vertex_buffer_color[N_TRNG*27+27+18];

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

    vertex_buffer_data[N_TRNG*27] = 0.0f;
    vertex_buffer_data[N_TRNG*27+1] = radius;
    vertex_buffer_data[N_TRNG*27+2] = 20.0f;

    vertex_buffer_data[N_TRNG*27+3] = 0.0f;
    vertex_buffer_data[N_TRNG*27+4] = radius;
    vertex_buffer_data[N_TRNG*27+5] = 15.0f;

    vertex_buffer_data[N_TRNG*27+6] = 0.0f;
    vertex_buffer_data[N_TRNG*27+7] = radius+this->rwlength;
    vertex_buffer_data[N_TRNG*27+8] = 20.0f;

    vertex_buffer_data[N_TRNG*27+9] = radius;
    vertex_buffer_data[N_TRNG*27+1+9] = 0;
    vertex_buffer_data[N_TRNG*27+2+9] = 4.0f;

    vertex_buffer_data[N_TRNG*27+3+9] = radius;
    vertex_buffer_data[N_TRNG*27+4+9] = 0;
    vertex_buffer_data[N_TRNG*27+5+9] = 8.0f;

    vertex_buffer_data[N_TRNG*27+6+9] = radius+this->wlength;
    vertex_buffer_data[N_TRNG*27+7+9] = 0;
    vertex_buffer_data[N_TRNG*27+8+9] = 8.0f;

    vertex_buffer_data[N_TRNG*27+9+9] = -radius;
    vertex_buffer_data[N_TRNG*27+1+9+9] = 0;
    vertex_buffer_data[N_TRNG*27+2+9+9] = 4.0f;

    vertex_buffer_data[N_TRNG*27+3+9+9] = -radius;
    vertex_buffer_data[N_TRNG*27+4+9+9] = 0;
    vertex_buffer_data[N_TRNG*27+5+9+9] = 8.0f;

    vertex_buffer_data[N_TRNG*27+6+9+9] = -radius-this->wlength;
    vertex_buffer_data[N_TRNG*27+7+9+9] = 0;
    vertex_buffer_data[N_TRNG*27+8+9+9] = 8.0f;

    vertex_buffer_data[N_TRNG*27+27] = -radius;
    vertex_buffer_data[N_TRNG*27+28] = 0;
    vertex_buffer_data[N_TRNG*27+29] = 4.0f;

    vertex_buffer_data[N_TRNG*27+30] = -radius-this->wlength;
    vertex_buffer_data[N_TRNG*27+31] = 0;
    vertex_buffer_data[N_TRNG*27+32] = 4.0f;

    vertex_buffer_data[N_TRNG*27+33] = -radius-this->wlength;
    vertex_buffer_data[N_TRNG*27+34] = 0;
    vertex_buffer_data[N_TRNG*27+35] = 8.0f;

    vertex_buffer_data[N_TRNG*27+36] = radius;
    vertex_buffer_data[N_TRNG*27+37] = 0;
    vertex_buffer_data[N_TRNG*27+38] = 4.0f;

    vertex_buffer_data[N_TRNG*27+39] = radius+this->wlength;
    vertex_buffer_data[N_TRNG*27+40] = 0;
    vertex_buffer_data[N_TRNG*27+41] = 4.0f;

    vertex_buffer_data[N_TRNG*27+42] = radius+this->wlength;
    vertex_buffer_data[N_TRNG*27+43] = 0;
    vertex_buffer_data[N_TRNG*27+44] = 8.0f;

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

    vertex_buffer_color[N_TRNG*27] = 0.0f;
    vertex_buffer_color[N_TRNG*27+1] = 0.0f;
    vertex_buffer_color[N_TRNG*27+2] = 0.0f;

    vertex_buffer_color[N_TRNG*27+3] = 0.0f;
    vertex_buffer_color[N_TRNG*27+4] = 0.0f;
    vertex_buffer_color[N_TRNG*27+5] = 0.0f;

    vertex_buffer_color[N_TRNG*27+6] = 0.0f;
    vertex_buffer_color[N_TRNG*27+7] = 0.0f;
    vertex_buffer_color[N_TRNG*27+8] = 0.0f;

    vertex_buffer_color[N_TRNG*27+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+1+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+2+9] = 0.0f;

    vertex_buffer_color[N_TRNG*27+3+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+4+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+5+9] = 0.0f;

    vertex_buffer_color[N_TRNG*27+6+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+7+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+8+9] = 0.0f;

    vertex_buffer_color[N_TRNG*27+9+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+1+9+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+2+9+9] = 0.0f;

    vertex_buffer_color[N_TRNG*27+3+9+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+4+9+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+5+9+9] = 0.0f;

    vertex_buffer_color[N_TRNG*27+6+9+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+7+9+9] = 0.0f;
    vertex_buffer_color[N_TRNG*27+8+9+9] = 0.0f;

    vertex_buffer_color[N_TRNG*27+27] = 0.0f;
    vertex_buffer_color[N_TRNG*27+28] = 0.0f;
    vertex_buffer_color[N_TRNG*27+29] = 0.0f;

    vertex_buffer_color[N_TRNG*27+30] = 0.0f;
    vertex_buffer_color[N_TRNG*27+31] = 0.0f;
    vertex_buffer_color[N_TRNG*27+32] = 0.0f;

    vertex_buffer_color[N_TRNG*27+33] = 0.0f;
    vertex_buffer_color[N_TRNG*27+34] = 0.0f;
    vertex_buffer_color[N_TRNG*27+35] = 0.0f;

    vertex_buffer_color[N_TRNG*27+36] = 0.0f;
    vertex_buffer_color[N_TRNG*27+37] = 0.0f;
    vertex_buffer_color[N_TRNG*27+38] = 0.0f;

    vertex_buffer_color[N_TRNG*27+39] = 0.0f;
    vertex_buffer_color[N_TRNG*27+40] = 0.0f;
    vertex_buffer_color[N_TRNG*27+41] = 0.0f;

    vertex_buffer_color[N_TRNG*27+42] = 0.0f;
    vertex_buffer_color[N_TRNG*27+43] = 0.0f;
    vertex_buffer_color[N_TRNG*27+44] = 0.0f;

    this->object = create3DObject(GL_TRIANGLES, N_TRNG*9+15, vertex_buffer_data, vertex_buffer_color, GL_FILL);
    // GLfloat vertex_buffer_data1[] = {
    //     0, 0, -20,
    //     0, 0, -35,
    //     -10, 0, -20,
    // };
    // color_t c = {255, 0, 0};
    // this->ob1 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data1, c, GL_FILL);
}

void Plane::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation.x * M_PI / 180.0f), glm::vec3(1, 0, 0));
    rotate *= glm::rotate((float) (this->rotation.y * M_PI / 180.0f), glm::vec3(0, 1, 0));
    rotate *= glm::rotate((float) (this->rotation.z * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    //draw3DObject(this->ob1);
}

void Plane::tick() {
    this->position.y += speed_y;
    if (this->speed_z > 1.000)
        this->speed_z -= 0.001;
    this->fuel -= 0.002;
}

