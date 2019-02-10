#include "main.h"

#ifndef BOMB_H
#define BOMB_H


class Bomb {
public:
    Bomb() {}
    Bomb(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void tick();
    double radius, flength, rlength, speed;
private:
    VAO *object, *ob1;
};

#endif // BOMB_H
