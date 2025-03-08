
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "../geometry/Direction.h"
#include "../geometry/Point.h"

class Snake {

public:
    Snake(Point point, Direction direction, int length, int growthSpeed);

    Direction direction;
    bool dead;
    int invisibleMoves;
    int growthSpeed;

    void move();
    Point& head();
    bool containsPoint(Point& point);
private:
    int movesToGrowth;
    std::vector<Point> points;

    void moveHead();
    void moveTail();
};

#endif //SNAKE_H
