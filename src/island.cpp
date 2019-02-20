#include "main.h"
#include "island.h"

Island::Island(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->side = 15;
    this->height = 25;
    this->is_checkpoint = false;
    
    GLfloat vertex_buffer_data[] = {
        
        70.0f, 0.0f, -70.0f,
        70.0f, 0.0f, 70.0f,
        0.0f, 10.0f, 0.0f,

        70.0f, 0.0f, 70.0f,
        -70.0f, 0.0f, 70.0f,
        0.0f, 10.0f, 0.0f,

        -70.0f, 0.0f, 70.0f,
        -70.0f, 0.0f, -70.0f,
        0.0f, 10.0f, 0.0f,

        -70.0f, 0.0f, -70.0f,
        70.0f, 0.0f, -70.0f,
        0.0f, 10.0f, 0.0f,

        -side,-side + height,-side,
        -side,-side + height, side,
        -side, side + height, side,
 
        side, side + height,-side,
        -side,-side + height,-side,
        -side, side + height,-side,
 
        side,-side + height, side,
        -side,-side + height,-side,
        side,-side + height,-side,
 
        side, side + height,-side,
        side,-side + height,-side,
        -side,-side + height,-side,
 
        -side,-side + height,-side,
        -side, side + height, side,
        -side, side + height,-side,
 
        side,-side + height, side,
        -side,-side + height, side,
        -side,-side + height,-side,
 
        -side, side + height, side,
        -side,-side + height, side,
        side,-side + height, side,
 
        side, side + height, side,
        side,-side + height,-side,
        side, side + height,-side,
 
        side,-side + height,-side,
        side, side + height, side,
        side,-side + height, side,
 
        side, side + height, side,
        side, side + height,-side,
        -side, side + height,-side,
 
        side, side + height, side,
        -side, side + height,-side,
        -side, side + height, side,
 
        side, side + height, side,
        -side, side + height, side,
        side,-side + height, side

    };

    GLfloat vertex_buffer_color[] = {
        
        255/255.0f, 228/255.0f, 181/255.0f,
        255/255.0f, 228/255.0f, 181/255.0f,
        1, 228/255.0f, 0.0f,

        255/255.0f, 228/255.0f, 181/255.0f,
        255/255.0f, 228/255.0f, 181/255.0f,
        1, 228/255.0f, 0.0f,

        255/255.0f, 228/255.0f, 181/255.0f,
        255/255.0f, 228/255.0f, 181/255.0f,
        1, 228/255.0f, 0.0f,

        255/255.0f, 228/255.0f, 181/255.0f,
        255/255.0f, 228/255.0f, 181/255.0f,
        1, 228/255.0f, 0.0f,

         -0.0f,-0.0f,-0.0f,
        -0.0f,-0.0f, 0.0f,
        -0.0f, 0.0f, 0.0f,
        0.0f, 0.0f,-0.0f,
        -0.0f,-0.0f,-0.0f,
        -0.0f, 0.0f,-0.0f,
        0.0f,-0.0f, 0.0f,
        -0.0f,-0.0f,-0.0f,
        0.0f,-0.0f,-0.0f,
        0.0f, 0.0f,-0.0f,
        0.0f,-0.0f,-0.0f,
        -0.0f,-0.0f,-0.0f,
        -0.0f,-0.0f,-0.0f,
        -0.0f, 0.0f, 0.0f,
        -0.0f, 0.0f,-0.0f,
        0.0f,-0.0f, 0.0f,
        -0.0f,-0.0f, 0.0f,
        -0.0f,-0.0f,-0.0f,
        -0.0f, 0.0f, 0.0f,
        -0.0f,-0.0f, 0.0f,
        0.0f,-0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f,-0.0f,-0.0f,
        0.0f, 0.0f,-0.0f,
        0.0f,-0.0f,-0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f,-0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f,-0.0f,
        -0.0f, 0.0f,-0.0f,
        0.0f, 0.0f, 0.0f,
        -0.0f, 0.0f,-0.0f,
        -0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        -0.0f, 0.0f, 0.0f,
        0.0f,-0.0f, 0.0f

    };

    this->object = create3DObject(GL_TRIANGLES, 48, vertex_buffer_data, vertex_buffer_color, GL_FILL);

    color_t c = {0, 0, 255};
    GLfloat vertex_buffer_data1[] = {
        -30, 120, 0,
        30, 120, 0,
        0, 60, 0
    };
    this->object1 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data1, c, GL_FILL);
}

void Island::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    Matrices.model *= translate;
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    if (this->is_checkpoint) {
        Matrices.model *= rotate;
        MVP = VP * Matrices.model;
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
        draw3DObject(this->object1);
    }
}

void Island::tick() {
    this->rotation += 5;
}
