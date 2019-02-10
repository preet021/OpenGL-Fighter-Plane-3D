#include "main.h"

#ifndef MISSILE_H
#define MISSILE_H


class Missile {
public:
    Missile() {}
    Missile(float rot, float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void tick();
    double radius, flength, rlength, speed;
private:
    VAO *object, *ob1;
};

#endif // MISSILE_H
