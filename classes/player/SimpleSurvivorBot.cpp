
#include "SimpleSurvivorBot.h"

#include <iostream>

#include "../geometry/Utils.h"

SimpleSurvivorBot::SimpleSurvivorBot(Snake *_snake, Field *field, int visionRange): _snake(_snake), _field(field), _visionRange(visionRange) {

}

SimpleSurvivorBot::~SimpleSurvivorBot() = default;


Snake* SimpleSurvivorBot::getSnake() {
    return _snake;
}

Field *SimpleSurvivorBot::getField() {
    return _field;
}


void SimpleSurvivorBot::turn() {
    if (freeSpace(_snake->direction) == _visionRange) {
        if (randInt(0, 10) > 8) {
            Direction dir = randInt(0, 2) > 0 ? clockWise(_snake->direction) : counterClockWise(_snake->direction);
            if (freeSpace(dir) == _visionRange) {
                _snake->direction = dir;
            } else {
                dir = clockWise(clockWise(dir));
                if (freeSpace(dir) == _visionRange) {
                    _snake->direction = dir;
                }
            }
        }
        return;
    }
    Direction dir_left = counterClockWise(_snake->direction);
    Direction dir_right = clockWise(_snake->direction);
    int s_left = freeSpace(dir_left);
    int s_right = freeSpace(dir_right);
    if (s_right > s_left) {
        _snake->direction = dir_right;
    } else if (s_left > s_right){
        _snake->direction = dir_left;
    } else {
        _snake->direction = randInt(0, 2) > 0 ? dir_left : dir_right;
    }
}

int SimpleSurvivorBot::freeSpace(Direction direction) {
    Point p(_snake->head().x, _snake->head().y);
    Point inc = getIncrementPoint(direction);
    p.x += inc.x;
    p.y += inc.y;
    int res = 0;
    int i = _visionRange;
    while (i > 0 && !(isAnObstacle(p) || _snake->containsPoint(p))) {
        --i;
        res++;
        p.x += inc.x;
        p.y += inc.y;
    }
    return res;
}

bool SimpleSurvivorBot::isAnObstacle(Point &p) {
    if (p.x < 0 || p.x >= _field->getWidth()) {
        return true;
    }
    if (p.y < 0 || p.y >= _field->getHeight()) {
        return true;
    }
    for (Snake* _snake: _field->snakes) {
        if (_snake->containsPoint(p)) {
            return true;
        }
    }
    return false;
}



