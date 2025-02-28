#include "Field.h"

#include <ostream>

Field::Field(const int width, const int height) {
    this->width = width;
    this->height = height;
}

std::string Field::draw() {
    std::string res;
    for (int i = 0; i < this->height; ++i) {
        for (int j=0; j < this->width; ++j) {
            res+="■";
        }
        res += '\n';
    }
    return res;
}

void Field::step() {

}




