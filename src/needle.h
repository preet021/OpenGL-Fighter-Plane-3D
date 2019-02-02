#include "main.h"

#ifndef NEEDLE_H
#define NEEDLE_H


class Needle {
public:
    Needle() {}
    Needle(float x, float y, float z, color_t c);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
private:
    VAO *object;
};

#endif // NEEDLE_H
