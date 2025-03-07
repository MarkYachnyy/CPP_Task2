//
// Created by marky on 28.02.2025.
//

#ifndef FIELD_H
#define FIELD_H
#include <string>
#include <vector>

#include "Snake.h"

class Field {
    int _width, _height;
public:
    Field(int width, int height);

    int getWidth() const;
    int getHeight() const;

    std::vector<Snake> snakes;

};

#endif //FIELD_H
