#include "Point.h"
#include "Snake.h"
#include "Utils.cpp"

#include "Direction.h"

Snake::Snake(Point& point, Direction direction, int length, int growthSpeed) {
    this->points = std::vector<Point*>();
    this->direction = direction;
    this->growthSpeed = growthSpeed;
    this->invisibleMoves=0;
    this->movesToGrowth = growthSpeed;

    auto* tail = new Point(point.x, point.y);
    switch (direction) {
        case Direction::Up: {
            tail->y += length;
            break;
        }
        case Direction::Right: {
            tail->x -= length;
            break;
        }case Direction::Down: {
            tail->y -= length;
            break;
        }case Direction::Left: {
            tail->x += length;
            break;
        }
    }
    points.push_back(&point);
    points.push_back(tail);
}

void Snake::move() {
    int dx = points.at(0)->x - points.at(1)->x;
    int dy = points.at(0)->y - points.at(1)->y;

    if (!(dx > 0 && direction == Direction::Right ||
        dx < 0 && direction == Direction::Left ||
        dy > 0 && direction == Direction::Down ||
        dy < 0 && direction == Direction::Up)) {
        points.insert(points.cbegin(), new Point(head()->x, head()->y));
    }
    moveHead();
    if (movesToGrowth > 0) {
        moveTail();
        movesToGrowth--;
    } else {
        movesToGrowth = growthSpeed;
    }
}

void Snake::moveHead() {
    Point* inc = getIncrementPoint(direction);
    head()->x += inc->x;
    head()->y += inc->y;
    delete inc;
}

void Snake::moveTail() {
    Point* tail = points.at(points.size() - 1);
    Point* tail1 = points.at(points.size() - 2);
    int dx = normalizedInt(tail1->x - tail->x);
    int dy = normalizedInt(tail1->y - tail->y);
    tail->x += dx;
    tail->y += dy;
    if (tail->x == tail1->x && tail->y == tail1->y) {
        delete points.at(points.size() - 1);
        points.pop_back();
    }
}

bool Snake::containsPoint(int x, int y) {
    for (int i = 0; i < points.size() - 1; ++i) {
        Point* p1 = points.at(i);
        Point* p2 = points.at(i+1);
        if (x >= std::min(p1->x, p2->x) && x <= std::max(p1->x, p2->x) ||
            y >= std::min(p1->y, p2->y) && y <= std::max(p1->y, p2->y)){
            return true;
        }
    }
    return false;
}


Point* Snake::head() {
    return points.at(0);
}





