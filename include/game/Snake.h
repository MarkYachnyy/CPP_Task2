
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Direction.h"
#include "../geometry/Point.h"

class Snake {

public:
    Snake(std::vector<Point> points, Direction direction, int growthSpeed, int movesLeft);
    Snake(std::vector<Point> points, Direction direction, int growthSpeed);
    Snake(Point point, Direction direction, int length, int growthSpeed);

    bool operator==(const Snake &) const = default;

    Direction direction;
    bool dead;
    int invisibleMoves;
    int growthSpeed;

    void move();
    Point& head();
    int containsPoint(Point& point);
private:
    int movesToGrowth;
    std::vector<Point> _points;

    void moveHead();
    void moveTail();
};

#endif //SNAKE_H
