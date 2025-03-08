#include "Field.h"

#include <ostream>

Field::Field(const int width, const int height) {
    this->_width = width;
    this->_height = height;
    this->snakes = std::vector<Snake*>();
}

Field::~Field() {
    for (Snake* s: snakes) {
        delete s;
    }
}

int Field::getHeight() const {
    return _height;
}

int Field::getWidth() const {
    return _width;
}




