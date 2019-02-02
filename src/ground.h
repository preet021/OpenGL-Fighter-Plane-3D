#include "main.h"

#ifndef GROUND_H
#define GROUND_H

class Ground {
public:
    Ground() {}
    Ground(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void tick();
    double deep;
private:
    VAO *object, *ob1;
};

#endif // GROUND_H
