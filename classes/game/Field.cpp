#include "Field.h"

#include <ostream>

Field::Field(const int width, const int height) {
    this->_width = width;
    this->_height = height;
    this->snakes = std::vector<Snake*>();
    this->artifacts = std::vector<Artifact*>();
}

Field::~Field() {
    for (Snake* s: snakes) {
        delete s;
    }
    for (Artifact* a: artifacts) {
        delete a;
    }
}

int Field::getHeight() const {
    return _height;
}

int Field::getWidth() const {
    return _width;
}

bool Field::isOccupied(Point &p) {
    for (Snake* s: snakes) {
        if (s->containsPoint(p)) {
            return true;
        }
    }
    for (Artifact* a: artifacts) {
        if (a->getPoint().x == p.x && a->getPoint().y == p.y) {
            return true;
        }
    }
    return false;
}





