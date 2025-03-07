#ifndef GAME_H
#define GAME_H
#include <map>

#include "Field.h"
#include "../artifact/Artifact.h"
#include "../player/SimpleSurvivorBot.h"


class Game {
    Field _field;
    std::vector<Artifact> _artifacts;
    std::vector<SimpleSurvivorBot> _players;
    float _artifactSpawnRate;

public:
    Game(int field_w, int field_h, float artifact_spawn_rate, int init_snake_c, int init_snake_l);
    bool tick();
    std::string print();
};



#endif //GAME_H
