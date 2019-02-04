#include "main.h"

#ifndef FUEL_H
#define FUEL_H


class Fuel {
public:
    Fuel() {}
    Fuel(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void tick();
    double side;
private:
    VAO *object, *ob1;
};

#endif // FUEL_H
