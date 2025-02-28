//
// Created by marky on 28.02.2025.
//

#ifndef FIELD_H
#define FIELD_H
#include <string>
#include <vector>

#include "Snake.h"
#include "artifact/Artifact.h"

class Field {
private:
    int width, height;
public:
    Field(int width, int height);
    std::vector<Snake*> snakes;
    std::vector<Artifact*> artifacts;
    std::string draw();
    void step();
};

#endif //FIELD_H
