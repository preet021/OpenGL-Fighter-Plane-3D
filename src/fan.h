#include "main.h"

#ifndef FAN_H
#define FAN_H

class Fan {
public:
    Fan() {}
    Fan(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP, float vx, float vy, float vz);
    void tick();
    double speed, radius;
private:
    VAO *object, *ob1;
};

#endif // FAN_H
