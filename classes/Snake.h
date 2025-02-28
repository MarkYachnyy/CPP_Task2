//
// Created by marky on 28.02.2025.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <vector>

#include "Direction.h"
#include "Point.h"

class Snake {

public:
    Snake(Point& point, Direction direction, int length, int growthSpeed);
    std::vector<Point*> points;
    Direction direction;
    void move();
    Point* head();
private:
    int growthSpeed;
    int movesToGrowth;
    int invisibleMoves;
    void moveHeadForward();
    void moveTail();
};

#endif //SNAKE_H
