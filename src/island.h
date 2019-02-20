#include "main.h"

#ifndef ISLAND_H
#define ISLAND_H

class Island {
public:
    Island() {}
    Island(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void tick();
    bool is_checkpoint;
    double height, side;
private:
    VAO *object, *object1;
};

#endif // ISLAND_H
