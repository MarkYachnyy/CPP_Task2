#include "Invisible.h"

Invisible::Invisible(int x, int y): _point(x, y) {
}

void Invisible::use(Snake *snake) {
    snake->invisibleMoves = 20;
}

Point Invisible::getPoint() {
    return _point;
}

int Invisible::getRadius() {
    return 0;
}

std::string Invisible::getName() {
    return "invisible";
}




