#ifndef GAME_H
#define GAME_H
#include <string>

#include "Field.h"
#include "../player/SimpleSurvivorBot.h"


class Game {
    Field _field;
    std::vector<Player*> _players;
    float _artifactSpawnRate;
    void countCollisionsAndKill();
    void applyArtifacts();

public:
    Game(int field_w, int field_h, float artifact_spawn_rate, int init_snake_c, int init_snake_l);
    ~Game();
    bool tick();
    std::string print();
};



#endif //GAME_H
