#ifndef INVISIBLE_H
#define INVISIBLE_H
#include "Artifact.cpp"
#include "../geometry/Point.h"


class Invisible: public Artifact {
    Point _point;
public:
    Invisible(int x, int y);
    ~Invisible() = default;

    void use(Snake* snake) override;
    Point getPoint() override;
    int getRadius() override;
    std::string getName() override;
};
#endif
