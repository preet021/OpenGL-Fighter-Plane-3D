#include "main.h"

#ifndef FISH_H
#define FISH_H


class Fish {
public:
    Fish() {}
    Fish(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    double side;
private:
    VAO *object;
};

#endif // FISH_H
