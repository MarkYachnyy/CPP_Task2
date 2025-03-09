#ifndef GAME_H
#define GAME_H
#include <string>

#include "Field.h"
#include "../player/SimpleSurvivorBot.h"


class Game {
    Field _field;
    std::vector<Player*> _players;
    int _artifactSpawnRate;
    void countCollisions();
    void killPlayers();
    void applyArtifacts();
    void createRandomArtifact();

    int _invisibleStrength;
    int _slowerStrength;
    int _bombRadius;

public:
    Game(int field_w, int field_h, int artifactSpawnRatePercent,  int init_snake_c, int init_snake_l);
    Game(int field_w, int field_h, int artifactSpawnRatePercent, int init_snake_c, int init_snake_l, int invisibleStrength, int slowerStrength, int bombRadius);
    ~Game();
    bool tick();
    std::string print();
};



#endif //GAME_H
