#include "../../include/geometry/Point.h"
#include "../../include/game/Snake.h"

#include <iostream>
#include "../../include/util/Utils.h"
#include "../../include/geometry/Direction.h"

Snake::Snake(std::vector<Point> points, Direction direction, int growthSpeed) : Snake(points, direction, growthSpeed, growthSpeed) {

}

Snake::Snake(std::vector<Point> points, Direction direction, int growthSpeed, int movesLeft) {
    this->_points = points;
    this->direction = direction;
    this->growthSpeed = growthSpeed;
    this->invisibleMoves=0;
    this->movesToGrowth = movesLeft;
    this->dead = false;
}



Snake::Snake(Point point, Direction direction, int length, int growthSpeed) {
    this->_points = std::vector<Point>();
    this->direction = direction;
    this->growthSpeed = growthSpeed;
    this->invisibleMoves=0;
    this->movesToGrowth = growthSpeed;
    this->dead = false;

    Point tail(point.x, point.y);
    Point inc = getIncrementPoint(direction);
    tail.x -= inc.x * (length - 1);
    tail.y -= inc.y * (length - 1);
    _points.push_back(point);
    _points.push_back(tail);
}

void Snake::move() {
    int dx = _points.at(0).x - _points.at(1).x;
    int dy = _points.at(0).y - _points.at(1).y;


    if (!(dx > 0 && direction == Direction::Right ||
        dx < 0 && direction == Direction::Left ||
        dy > 0 && direction == Direction::Down ||
        dy < 0 && direction == Direction::Up)) {
        _points.insert(_points.cbegin(), Point(head().x, head().y));
    }
    moveHead();
    if (movesToGrowth > 0) {
        moveTail();
        movesToGrowth--;
    } else {
        movesToGrowth = growthSpeed;
    }
    if (invisibleMoves > 0) {
        invisibleMoves--;
    }
}

void Snake::moveHead() {
    Point inc = getIncrementPoint(direction);
    this->head().x+=inc.x;
    this->head().y+=inc.y;
}

void Snake::moveTail() {
    Point& tail = _points.at(_points.size() - 1);
    Point& tail1 = _points.at(_points.size() - 2);
    int dx = normalizedInt(tail1.x - tail.x);
    int dy = normalizedInt(tail1.y - tail.y);
    tail.x += dx;
    tail.y += dy;
    if (tail.x == tail1.x && tail.y == tail1.y) {
        _points.pop_back();
    }
}

int Snake::containsPoint(Point& p) {
    int x = p.x;
    int y = p.y;
    int res = 0;
    for (int i = 0; i < _points.size() - 1; ++i) {
        Point p1 = _points.at(i);
        Point p2 = _points.at(i+1);
        if (x >= std::min(p1.x, p2.x) && x <= std::max(p1.x, p2.x) && y == p1.y && y == p2.y||
            y >= std::min(p1.y, p2.y) && y <= std::max(p1.y, p2.y) && x == p1.x && x == p2.x){
            res++;
        }
    }
    return res;
}


Point& Snake::head() {
    return _points.at(0);
}





