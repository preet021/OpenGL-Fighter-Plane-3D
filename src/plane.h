#include "main.h"

#ifndef PLANE_H
#define PLANE_H


class Plane {
public:
    Plane() {}
    Plane(float x, float y, float z);
    glm::vec3 position, rotation;
    void draw(glm::mat4 VP);
    void tick();
    double frotation, fspeed, radius, flength, rlength, wlength, rwlength, tilt, maxtilt, speed_z, fan_speed, fan_rotation, speed_y, acc_z, fuel, maxfuel, maxalt;
private:
    VAO *object, *object1;
};

#endif // PLANE_H
