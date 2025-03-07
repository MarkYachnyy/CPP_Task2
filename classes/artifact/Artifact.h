//
// Created by marky on 28.02.2025.
//

#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "../game/Snake.h"

class Artifact {
public:
    Point point;
    int radius;
    void effect(Snake& snake);
};

#endif //ARTIFACT_H
