#include "main.h"
#include "dashboard.h"
#define N_BLCK 180

Dashboard::Dashboard(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;

    GLfloat vertex_buffer_data[18+18*N_BLCK+36*N_BLCK], vertex_buffer_color[18+18*N_BLCK+36*N_BLCK];
        // 0, 0, 0,
        // 0, -5, 0,
        // 24, -5, 0,

        // 0, 0, 0,
        // 24, -5, 0,
        // 24, 0, 0,
    vertex_buffer_data[0] = vertex_buffer_data[1] = vertex_buffer_data[2] = vertex_buffer_data[3] = vertex_buffer_data[5] = vertex_buffer_data[8] = 0;
    vertex_buffer_data[9] = vertex_buffer_data[10] = vertex_buffer_data[11] = vertex_buffer_data[14] = vertex_buffer_data[17] = vertex_buffer_color[16] = 0;

    vertex_buffer_data[6] = vertex_buffer_data[12] = vertex_buffer_data[15] = 24;
    vertex_buffer_data[4] = vertex_buffer_data[7] = vertex_buffer_data[13] = -5;

    for (int i=0; i<18; ++i)
        vertex_buffer_color[i] = 255.0f;

    double theta = 0, phi = M_PI / N_BLCK, ax, bx, cx, dx, ay, by, cy, dy, radius = 3, thickness = 0.3;

    for (int i=18; i<18*(1 + N_BLCK); i+=18) {
        ax = (radius + thickness) * cos(theta);
        bx = radius * cos(theta);
        cx = (radius + thickness) * cos(theta + phi);
        dx = radius * cos(theta + phi);

        ay = (radius + thickness) * sin(theta);
        by = radius * sin(theta);
        cy = (radius + thickness) * sin(theta + phi);
        dy = radius * sin(theta + phi);

        vertex_buffer_data[i] = ax + 12;
        vertex_buffer_data[i + 1] = ay + -4;
        vertex_buffer_data[i + 2] = 0.0f;

        vertex_buffer_data[3 + i]  = bx + 12;
        vertex_buffer_data[3 + i + 1] = by + -4;
        vertex_buffer_data[3 + i + 2] = 0.0f;

        vertex_buffer_data[6 + i] = dx + 12;
        vertex_buffer_data[6 + i + 1] = dy + -4;
        vertex_buffer_data[6 + i + 2] = 0.0f;

        vertex_buffer_data[9 + i] = ax + 12;
        vertex_buffer_data[9 + i + 1] = ay + -4;
        vertex_buffer_data[9 + i + 2] = 0.0f;

        vertex_buffer_data[9 + 3 + i]  = cx + 12;
        vertex_buffer_data[9 + 3 + i + 1] = cy + -4;
        vertex_buffer_data[9 + 3 + i + 2] = 0.0f;

        vertex_buffer_data[9 + 6 + i] = dx + 12;
        vertex_buffer_data[9 + 6 + i + 1] = dy + -4;
        vertex_buffer_data[9 + 6 + i + 2] = 0.0f;
        


        vertex_buffer_color[i] = 0.0f;
        vertex_buffer_color[i + 1] = 0.0f;
        vertex_buffer_color[i + 2] = 0.0f;

        vertex_buffer_color[3 + i]  = 0.0f;
        vertex_buffer_color[3 + i + 1] = 0.0f;
        vertex_buffer_color[3 + i + 2] = 0.0f;

        vertex_buffer_color[6 + i] = 0.0f;
        vertex_buffer_color[6 + i + 1] = 0.0f;
        vertex_buffer_color[6 + i + 2] = 0.0f;

        vertex_buffer_color[9 + i] = 0.0f;
        vertex_buffer_color[9 + i + 1] = 0.0f;
        vertex_buffer_color[9 + i + 2] = 0.0f;

        vertex_buffer_color[9 + 3 + i]  = 0.0f;
        vertex_buffer_color[9 + 3 + i + 1] = 0.0f;
        vertex_buffer_color[9 + 3 + i + 2] = 0.0f;

        vertex_buffer_color[9 + 6 + i] = 0.0f;
        vertex_buffer_color[9 + 6 + i + 1] = 0.0f;
        vertex_buffer_color[9 + 6 + i + 2] = 0.0f;

        theta += phi;
    }



    theta = 0; phi = M_PI / N_BLCK;

    for (int i=18+18*N_BLCK; i<18*(1 + 2*N_BLCK); i+=18) {
        ax = (radius + thickness) * cos(theta);
        bx = radius * cos(theta);
        cx = (radius + thickness) * cos(theta + phi);
        dx = radius * cos(theta + phi);

        ay = (radius + thickness) * sin(theta);
        by = radius * sin(theta);
        cy = (radius + thickness) * sin(theta + phi);
        dy = radius * sin(theta + phi);

        vertex_buffer_data[i] = ax + 4;
        vertex_buffer_data[i + 1] = ay + -4;
        vertex_buffer_data[i + 2] = 0.0f;

        vertex_buffer_data[3 + i]  = bx + 4;
        vertex_buffer_data[3 + i + 1] = by + -4;
        vertex_buffer_data[3 + i + 2] = 0.0f;

        vertex_buffer_data[6 + i] = dx + 4;
        vertex_buffer_data[6 + i + 1] = dy + -4;
        vertex_buffer_data[6 + i + 2] = 0.0f;

        vertex_buffer_data[9 + i] = ax + 4;
        vertex_buffer_data[9 + i + 1] = ay + -4;
        vertex_buffer_data[9 + i + 2] = 0.0f;

        vertex_buffer_data[9 + 3 + i]  = cx + 4;
        vertex_buffer_data[9 + 3 + i + 1] = cy + -4;
        vertex_buffer_data[9 + 3 + i + 2] = 0.0f;

        vertex_buffer_data[9 + 6 + i] = dx + 4;
        vertex_buffer_data[9 + 6 + i + 1] = dy + -4;
        vertex_buffer_data[9 + 6 + i + 2] = 0.0f;
        


        vertex_buffer_color[i] = 0.0f;
        vertex_buffer_color[i + 1] = 0.0f;
        vertex_buffer_color[i + 2] = 0.0f;

        vertex_buffer_color[3 + i]  = 0.0f;
        vertex_buffer_color[3 + i + 1] = 0.0f;
        vertex_buffer_color[3 + i + 2] = 0.0f;

        vertex_buffer_color[6 + i] = 0.0f;
        vertex_buffer_color[6 + i + 1] = 0.0f;
        vertex_buffer_color[6 + i + 2] = 0.0f;

        vertex_buffer_color[9 + i] = 0.0f;
        vertex_buffer_color[9 + i + 1] = 0.0f;
        vertex_buffer_color[9 + i + 2] = 0.0f;

        vertex_buffer_color[9 + 3 + i]  = 0.0f;
        vertex_buffer_color[9 + 3 + i + 1] = 0.0f;
        vertex_buffer_color[9 + 3 + i + 2] = 0.0f;

        vertex_buffer_color[9 + 6 + i] = 0.0f;
        vertex_buffer_color[9 + 6 + i + 1] = 0.0f;
        vertex_buffer_color[9 + 6 + i + 2] = 0.0f;

        theta += phi;
    }

    theta = 0; phi = M_PI / N_BLCK;

    for (int i=18+36*N_BLCK; i<18*(1 + 3*N_BLCK); i+=18) {
        ax = (radius + thickness) * cos(theta);
        bx = radius * cos(theta);
        cx = (radius + thickness) * cos(theta + phi);
        dx = radius * cos(theta + phi);

        ay = (radius + thickness) * sin(theta);
        by = radius * sin(theta);
        cy = (radius + thickness) * sin(theta + phi);
        dy = radius * sin(theta + phi);

        vertex_buffer_data[i] = ax + 20;
        vertex_buffer_data[i + 1] = ay + -4;
        vertex_buffer_data[i + 2] = 0.0f;

        vertex_buffer_data[3 + i]  = bx + 20;
        vertex_buffer_data[3 + i + 1] = by + -4;
        vertex_buffer_data[3 + i + 2] = 0.0f;

        vertex_buffer_data[6 + i] = dx + 20;
        vertex_buffer_data[6 + i + 1] = dy + -4;
        vertex_buffer_data[6 + i + 2] = 0.0f;

        vertex_buffer_data[9 + i] = ax + 20;
        vertex_buffer_data[9 + i + 1] = ay + -4;
        vertex_buffer_data[9 + i + 2] = 0.0f;

        vertex_buffer_data[9 + 3 + i]  = cx + 20;
        vertex_buffer_data[9 + 3 + i + 1] = cy + -4;
        vertex_buffer_data[9 + 3 + i + 2] = 0.0f;

        vertex_buffer_data[9 + 6 + i] = dx + 20;
        vertex_buffer_data[9 + 6 + i + 1] = dy + -4;
        vertex_buffer_data[9 + 6 + i + 2] = 0.0f;
        


        vertex_buffer_color[i] = 0.0f;
        vertex_buffer_color[i + 1] = 0.0f;
        vertex_buffer_color[i + 2] = 0.0f;

        vertex_buffer_color[3 + i]  = 0.0f;
        vertex_buffer_color[3 + i + 1] = 0.0f;
        vertex_buffer_color[3 + i + 2] = 0.0f;

        vertex_buffer_color[6 + i] = 0.0f;
        vertex_buffer_color[6 + i + 1] = 0.0f;
        vertex_buffer_color[6 + i + 2] = 0.0f;

        vertex_buffer_color[9 + i] = 0.0f;
        vertex_buffer_color[9 + i + 1] = 0.0f;
        vertex_buffer_color[9 + i + 2] = 0.0f;

        vertex_buffer_color[9 + 3 + i]  = 0.0f;
        vertex_buffer_color[9 + 3 + i + 1] = 0.0f;
        vertex_buffer_color[9 + 3 + i + 2] = 0.0f;

        vertex_buffer_color[9 + 6 + i] = 0.0f;
        vertex_buffer_color[9 + 6 + i + 1] = 0.0f;
        vertex_buffer_color[9 + 6 + i + 2] = 0.0f;

        theta += phi;
    }

    // color_t c = {255, 0, 0};

    // GLfloat vertex_buffer_data1 = {
    //     11.5, -4, 0,
    //     12.5, -4, 0,
    //     12, -1.2, 0
    // };

    this->object = create3DObject(GL_TRIANGLES, 6*(1 + 3*N_BLCK), vertex_buffer_data, vertex_buffer_color, GL_FILL);
    // this->needle = create3DObject(GL_TRIANGLES, 6*(1 + N_BLCK), vertex_buffer_data1, c, GL_FILL);
}

void Dashboard::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}
