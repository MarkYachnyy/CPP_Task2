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

    if (dx > 0 && direction == Direction::Right ||
        dx < 0 && direction == Direction::Left ||
        dy > 0 && direction == Direction::Down ||
        dy < 0 && direction == Direction::Up) {
        moveHeadForward();
    } else {
        points.insert(points.cbegin(), new Point(head()->x, head()->y));

    }
    if (movesToGrowth > 0) {
        moveTail();
        movesToGrowth--;
    } else {
        movesToGrowth = growthSpeed;
    }
}

void Snake::moveHeadForward() {
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
        points.pop_back();
    }
}

Point* Snake::head() {
    return points.at(0);
}





