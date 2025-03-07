//
// Created by marky on 03.03.2025.
//

#ifndef SIMPLESURVIVORBOT_H
#define SIMPLESURVIVORBOT_H
#include "../game/Snake.h"
#include "../game/Field.h"


class SimpleSurvivorBot{
    int _visionRange;
    Snake& _snake;
    Field& _field;

    int freeSpace(Direction direction);
    bool isAnObstacle(Point& p);
public:
    void turn();
    SimpleSurvivorBot(Snake& snake, Field& field, int visionRange);
};


#endif //SIMPLESURVIVORBOT_H
