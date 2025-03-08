//
// Created by marky on 28.02.2025.
//

#ifndef FIELD_H
#define FIELD_H
#include <vector>

#include "Snake.h"
#include "../artifact/Artifact.cpp"

class Field {
    int _width, _height;
public:
    Field(int width, int height);
    ~Field();

    int getWidth() const;
    int getHeight() const;
    bool isOccupied(Point& p);

    std::vector<Artifact*> artifacts;
    std::vector<Snake*> snakes;

};

#endif //FIELD_H
