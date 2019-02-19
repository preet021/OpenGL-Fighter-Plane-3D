#include "main.h"
#include "parachute.h"
#define N_TRNG 100

Parachute::Parachute(float x, float y, float z) {
    
    this->position = glm::vec3(x, y, z);
    this->rotation = 30;
    this->speed = -0.2;

    float radius = 15, rlength = 12, phi = 2*M_PI/(3*N_TRNG), theta = 0;

    GLfloat vertex_buffer_color[18*N_TRNG], vertex_buffer_data[18*N_TRNG]; 

    GLfloat vertex_buffer_data1[] = {

        -2.0f, -3.0f, 0.0f+10.0f,
        -2.0f, -3.0f, 1.0f+10.0f,
        -radius*sin(M_PI/3), radius*cos(M_PI/3), 0.0f+10.0f,

        2.0f, -3.0f, 0.0f+10.0f,
        2.0f, -3.0f, 1.0f+10.0f,
        radius*sin(M_PI/3), radius*cos(M_PI/3), 0.0f+10.0f,

        -2.0f,-2.0f-5.0f,-2.0f+10.0f,
        -2.0f,-2.0f-5.0f, 2.0f+10.0f,
        -2.0f, 2.0f-5.0f, 2.0f+10.0f,

        2.0f, 2.0f-5.0f,-2.0f+10.0f,
        -2.0f,-2.0f-5.0f,-2.0f+10.0f,
        -2.0f, 2.0f-5.0f,-2.0f+10.0f,
        
        2.0f,-2.0f-5.0f, 2.0f+10.0f,
        -2.0f,-2.0f-5.0f,-2.0f+10.0f,
        2.0f,-2.0f-5.0f,-2.0f+10.0f,
        
        2.0f, 2.0f-5.0f,-2.0f+10.0f,
        2.0f,-2.0f-5.0f,-2.0f+10.0f,
        -2.0f,-2.0f-5.0f,-2.0f+10.0f,
        
        -2.0f,-2.0f-5.0f,-2.0f+10.0f,
        -2.0f, 2.0f-5.0f, 2.0f+10.0f,
        -2.0f, 2.0f-5.0f,-2.0f+10.0f,
        
        2.0f,-2.0f-5.0f, 2.0f+10.0f,
        -2.0f,-2.0f-5.0f, 2.0f+10.0f,
        -2.0f,-2.0f-5.0f,-2.0f+10.0f,
        
        -2.0f, 2.0f-5.0f, 2.0f+10.0f,
        -2.0f,-2.0f-5.0f, 2.0f+10.0f,
        2.0f,-2.0f-5.0f, 2.0f+10.0f,
        
        2.0f, 2.0f-5.0f, 2.0f+10.0f,
        2.0f,-2.0f-5.0f,-2.0f+10.0f,
        2.0f, 2.0f-5.0f,-2.0f+10.0f,
        
        2.0f,-2.0f-5.0f,-2.0f+10.0f,
        2.0f, 2.0f-5.0f, 2.0f+10.0f,
        2.0f,-2.0f-5.0f, 2.0f+10.0f,
        
        2.0f, 2.0f-5.0f, 2.0f+10.0f,
        2.0f, 2.0f-5.0f,-2.0f+10.0f,
        -2.0f, 2.0f-5.0f,-2.0f+10.0f,
        
        2.0f, 2.0f-5.0f, 2.0f+10.0f,
        -2.0f, 2.0f-5.0f,-2.0f+10.0f,
        -2.0f, 2.0f-5.0f, 2.0f+10.0f,
        
        2.0f, 2.0f-5.0f, 2.0f+10.0f,
        -2.0f, 2.0f-5.0f, 2.0f+10.0f,
        2.0f,-2.0f-5.0f, 2.0f+10.0f

    };


    for (int i=0; i<18*N_TRNG; i+=18) {

        vertex_buffer_data[i] = radius*cos(theta);
        vertex_buffer_data[i+1] = radius*sin(theta);
        vertex_buffer_data[i+2] = rlength;

        vertex_buffer_data[i+3] = radius*cos(theta);
        vertex_buffer_data[i+4] = radius*sin(theta);
        vertex_buffer_data[i+5] = 0.0f;

        vertex_buffer_data[i+6] = radius*cos(theta+phi);
        vertex_buffer_data[i+7] = radius*sin(theta+phi);
        vertex_buffer_data[i+8] = 0.0f;

        vertex_buffer_data[9+i] = radius*cos(theta);
        vertex_buffer_data[9+i+1] = radius*sin(theta);
        vertex_buffer_data[9+i+2] = rlength;

        vertex_buffer_data[9+i+3] = radius*cos(theta+phi);
        vertex_buffer_data[9+i+4] = radius*sin(theta+phi);
        vertex_buffer_data[9+i+5] = rlength;

        vertex_buffer_data[9+i+6] = radius*cos(theta+phi);
        vertex_buffer_data[9+i+7] = radius*sin(theta+phi);
        vertex_buffer_data[9+i+8] = 0.0f;

        theta += phi;

    }

    for (int i=0; i<18*N_TRNG; i+=18) {

        vertex_buffer_color[i] = 0.45f;
        vertex_buffer_color[i+1] = 0.45f;
        vertex_buffer_color[i+2] = 0.0f;

        vertex_buffer_color[i+3] = 0.45f;
        vertex_buffer_color[i+4] = 0.45f;
        vertex_buffer_color[i+5] = 0.0f;

        vertex_buffer_color[i+6] = 0.45f;
        vertex_buffer_color[i+7] = 0.45f;
        vertex_buffer_color[i+8] = 0.0f;

        vertex_buffer_color[9+i] = 0.45f;
        vertex_buffer_color[9+i+1] = 0.45f;
        vertex_buffer_color[9+i+2] = 0.0f;

        vertex_buffer_color[9+i+3] = 0.45f;
        vertex_buffer_color[9+i+4] = 0.45f;
        vertex_buffer_color[9+i+5] = 0.0f;

        vertex_buffer_color[9+i+6] = 0.45f;
        vertex_buffer_color[9+i+7] = 0.45f;
        vertex_buffer_color[9+i+8] = 0.0f;

    }

    color_t c = {47, 79, 79};

    this->object = create3DObject(GL_TRIANGLES, 6*N_TRNG, vertex_buffer_data, vertex_buffer_color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data1, c, GL_FILL);
}

void Parachute::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);

    Matrices.model *= (rotate);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Parachute::tick() {
    this->position.y += speed;
}
