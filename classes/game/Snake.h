//
// Created by marky on 28.02.2025.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <vector>

#include "../geometry/Direction.h"
#include "../geometry/Point.h"

class Snake {

public:
    Snake(Point point, Direction direction, int length, int growthSpeed);
    Direction direction;

    void move();
    Point& head();
    bool containsPoint(Point& point);
private:
    int growthSpeed;
    int movesToGrowth;
    int invisibleMoves;
    std::vector<Point> points;

    void moveHead();
    void moveTail();
};

#endif //SNAKE_H
