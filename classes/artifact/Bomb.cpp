#include "Bomb.h"

Bomb::Bomb(int x, int y, int radius): _point(x, y) {
    this->_radius = radius;
}

void Bomb::use(Snake *snake) {
    snake->dead = true;
}

Point Bomb::getPoint() {
    return _point;
}

int Bomb::getRadius() {
    return _radius;
}

std::string Bomb::getName() {
    return "bomb";
}




