#include "main.h"

#ifndef ENEMY_H
#define ENEMY_H


class Enemy {
public:
    Enemy() {}
    Enemy(float x, float y, float z, float vx, float vy, float vz);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void tick();
    double radius, flength, rlength, speed, ux, uy, uz;
private:
    VAO *object;
};

#endif // ENEMY_H
