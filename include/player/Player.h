#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include "../game/Field.h"
#include "../../include/game/Snake.h"

class Player {
public:
    Player() = default;
    virtual ~Player() = default;
    virtual Field* getField(){return nullptr;}
    virtual Snake* getSnake(){return nullptr;}
    virtual void turn(){}
};

#endif //PLAYER_H
