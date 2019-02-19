#include "main.h"

#ifndef SCORE_H
#define SCORE_H


class Score {
public:
    Score() {}
    Score(float x, float y, float rot, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    double length, thickness;
private:
    VAO *object;
};

#endif // SCORE_H
