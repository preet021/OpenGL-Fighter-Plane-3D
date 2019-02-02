#include "main.h"

#ifndef DASHBOARD_H
#define DASHBOARD_H

class Dashboard {
public:
    Dashboard() {}
    Dashboard(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void tick();
private:
    VAO *object;
};

#endif // DASHBOARD_H
