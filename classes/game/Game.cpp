#include <algorithm>
#include "Game.h"
#include "../player/SimpleSurvivorBot.h"

Game::Game(int field_w, int field_h, float artifact_spawn_rate, int init_snake_c, int init_snake_l): _field(field_w, field_h) {
    _artifactSpawnRate = artifact_spawn_rate;
    _artifacts = std::vector<Artifact*>();
    _players = std::vector<Player*>();

    int h = (field_h - init_snake_l) / 2;

    for (int i = 0; i < init_snake_c; ++i) {
        Snake* s = new Snake({i * field_w / init_snake_c, h}, Direction::Up, init_snake_l, 100);
        _field.snakes.emplace_back(s);
    }

    for (Snake* snake: _field.snakes) {
        _players.emplace_back(new SimpleSurvivorBot(snake, &_field, 3));
    }
}

Game::~Game() {
    for (Player* p: _players) {
        delete p;
    }
}


bool Game::tick() {
    for (Player* player: _players) {
        player->turn();
    }
    for (Snake* snake: _field.snakes) {
        snake->move();
    }
    countCollisionsAndKill();
    return true;
}

void Game::countCollisionsAndKill() {
    std::vector<Snake*> snakes_to_kill;
    std::vector<Player*> bots_to_kill;
    for (Player* p: _players) {
        if (p->getSnake()->head().x < 0 || p->getSnake()->head().x >= _field.getWidth() ||
            p->getSnake()->head().y < 0 || p->getSnake()->head().y >= _field.getHeight()) {
            snakes_to_kill.emplace_back(p->getSnake());
            bots_to_kill.emplace_back(p);
        }
        for (Snake* s: _field.snakes) {
            if (s == p->getSnake()) {
                continue;
            }
            if (s->containsPoint(p->getSnake()->head())) {
                snakes_to_kill.emplace_back(p->getSnake());
                bots_to_kill.emplace_back(p);
            }
        }
    }

    for (Snake* s: snakes_to_kill) {
        delete s;
        _field.snakes.erase(std::find(_field.snakes.begin(), _field.snakes.end(), s));
    }
    for (Player* p: bots_to_kill) {
        delete p;
        _players.erase(std::find(_players.begin(), _players.end(), p));
    }
}


std::string Game::print() {
    std::string res;
    for (int i = 0; i < _field.getHeight(); ++i) {
        for (int j = 0; j < _field.getWidth(); ++j) {
            std::string c = "■";
            for (Snake* snake: _field.snakes) {
                Point p(j, i);
                if (snake->head().x == p.x && snake->head().y == p.y) {
                    c="\u001B[31m■\u001B[0m";
                } else if (snake->containsPoint(p)) {
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


