#include "main.h"
#include "ground.h"
#define N_TRNG 100
#define INF 99999

Ground::Ground(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->deep = 0;
    this->gmax = INF;


    GLfloat vertex_buffer_data[] = {
        INF, -deep, INF,
        INF, -deep, -INF,
        -INF, -deep, -INF,
        INF, -deep, INF,
        -INF, -deep, -INF,
        -INF, -deep, INF
    };

    color_t c = {32,178,170};
    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, c, GL_FILL);
}

void Ground::draw(glm::mat4 VP) {
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

void Ground::tick() {
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

