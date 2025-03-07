//
// Created by marky on 03.03.2025.
//

#include "Game.h"

#include <iostream>

#include "../player/SimpleSurvivorBot.h"

Game::Game(int field_w, int field_h, float artifact_spawn_rate, int init_snake_c, int init_snake_l): _field(field_w, field_h) {
    _artifactSpawnRate = artifact_spawn_rate;
    _artifacts = std::vector<Artifact>();
    _players = std::vector<SimpleSurvivorBot>();

    int h = (field_h - init_snake_l) / 2;

    for (int i = 0; i < init_snake_c; ++i) {
        Snake s({i * field_w / init_snake_c, h}, Direction::Up, init_snake_l, 100);
        _field.snakes.emplace_back(s);
    }

    for (Snake& snake: _field.snakes) {
        _players.emplace_back(SimpleSurvivorBot(snake, _field, 3));
    }
}

bool Game::tick() {
    for (SimpleSurvivorBot& player: _players) {
        player.turn();
    }
    for (Snake& snake: _field.snakes) {
        snake.move();
    }
    return true;
}

std::string Game::print() {
    std::string res;
    for (int i = 0; i < _field.getHeight(); ++i) {
        for (int j = 0; j < _field.getWidth(); ++j) {
            std::string c = "■";
            for (Snake& snake: _field.snakes) {
                Point p(j, i);
                if (snake.containsPoint(p)) {
                    c = "\u001B[33m■\u001B[0m";
                    break;
                }
            }
            res += c;
        }
        res += '\n';
    }

    return res;
}


