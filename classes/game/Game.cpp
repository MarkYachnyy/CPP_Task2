#include <algorithm>
#include "Game.h"
#include "../player/SimpleSurvivorBot.h"
#include "../util/Utils.h"
#include <string>
#include "../artifact/Invisible.h"
#include "../artifact/Bomb.h"
#include "../artifact/Slower.h"
#include "../util/symbols.h"

Game::Game(int field_w, int field_h, int artifactSpawnRatePercent, int init_snake_c, int init_snake_l):
    Game(field_w, field_h, artifactSpawnRatePercent, init_snake_c, init_snake_l, 20, 10, 5){
}

Game::Game(int field_w, int field_h, int artifactSpawnRatePercent, int init_snake_c, int init_snake_l, int invisibleStrength, int slowerStrength, int bombRadius) : _field(
    field_w, field_h) {
    _artifactSpawnRate = artifactSpawnRatePercent;
    _players = std::vector<Player *>();

    int h = (field_h - init_snake_l) / 2;
    for (int i = 0; i < init_snake_c; ++i) {
        Snake *s = new Snake({i * field_w / init_snake_c, h}, Direction::Up, init_snake_l, 10);
        _field.snakes.emplace_back(s);
    }
    for (Snake *snake: _field.snakes) {
        _players.emplace_back(new SimpleSurvivorBot(snake, &_field, 3));
    }

    _bombRadius = bombRadius;
    _invisibleStrength = invisibleStrength;
    _slowerStrength = slowerStrength;
}


Game::~Game() {
    for (Player *p: _players) {
        delete p;
    }
}


bool Game::tick() {
    for (Player *player: _players) {
        player->turn();
    }
    for (Snake *snake: _field.snakes) {
        snake->move();
    }
    if (randInt(0, 100) < _artifactSpawnRate) {
        createRandomArtifact();
    }
    applyArtifacts();
    countCollisions();
    killPlayers();
    return true;
}

void Game::killPlayers() {
    for (Player *p: _players) {
        if (Snake *s = p->getSnake(); s->dead) {
            delete s;
            _field.snakes.erase(std::find(_field.snakes.begin(), _field.snakes.end(), s));
            delete p;
            _players.erase(std::find(_players.begin(), _players.end(), p));
        }
    }
}


void Game::countCollisions() {
    std::vector<Snake *> snakes_to_kill;
    std::vector<Player *> bots_to_kill;
    for (Player *p: _players) {
        Snake *playersSnake = p->getSnake();
        if (playersSnake->head().x < 0 || playersSnake->head().x >= _field.getWidth() ||
            playersSnake->head().y < 0 || playersSnake->head().y >= _field.getHeight()) {
            playersSnake->dead = true;
        }
        for (Snake *s: _field.snakes) {
            if (s == playersSnake) {
                if (s->containsPoint(s->head()) > 1) {
                    if (s->invisibleMoves <= 0) {
                        playersSnake->dead = true;
                        break;
                    }
                }
                continue;
            }
            if (s->containsPoint(playersSnake->head())) {
                playersSnake->dead = true;
                break;
            }
        }
    }
}

void Game::applyArtifacts() {
    std::vector<Artifact*> to_erase;
    for (Artifact *a: _field.artifacts) {
        bool used = false;
        for (Snake *s: _field.snakes) {
            if (a->getPoint().x == s->head().x && a->getPoint().y == s->head().y) {
                used = true;
                for (int i = a->getPoint().y - a->getRadius(); i < a->getPoint().y + a->getRadius() + 1; ++i) {
                    for (int j = a->getPoint().x - a->getRadius(); j < a->getPoint().x + a->getRadius() + 1; ++j) {
                        Point p(j, i);
                        for (Snake *s1: _field.snakes) {
                            if (s1->containsPoint(p)) {
                                a->use(s1);
                            }
                        }
                    }
                }
            }
        }

        if (used) {
            to_erase.emplace_back(a);
        }
    }
    for (Artifact* a: to_erase) {
        delete a;
        _field.artifacts.erase(std::find(_field.artifacts.begin(), _field.artifacts.end(), a));
    }
}

void Game::createRandomArtifact() {
    Point p(0, 0);
    do {
        p = Point(randInt(0, _field.getWidth()), randInt(0, _field.getHeight()));
    } while (_field.isOccupied(p));
    Artifact *artifact;
    switch (randInt(0, 3)) {
        case 0: {
            artifact = new Invisible(p.x, p.y, _invisibleStrength);
            break;
        }
        case 1: {
            artifact = new Bomb(p.x, p.y, _bombRadius);
            break;
        }
        case 2: {
            artifact = new Slower(p.x, p.y, _slowerStrength);
            break;
        }
        default: {
            break;
        }
    }
    _field.artifacts.push_back(artifact);
}

std::string Game::print() {
    std::string res;
    for (int i = 0; i < _field.getHeight(); ++i) {
        for (int j = 0; j < _field.getWidth(); ++j) {
            std::string c = BG_BLACK;
            for (Snake *snake: _field.snakes) {
                Point p(j, i);
                if (snake->head().x == p.x && snake->head().y == p.y) {
                    c = BG_RED;
                } else if (snake->containsPoint(p)) {
                    if (snake->invisibleMoves > 0) {
                        c = BG_CYAN;
                    } else {
                        c = BG_YELLOW;
                    }
                    break;
                }
            }
            bool artifact = false;
            for (Artifact *a: _field.artifacts) {
                if (a->getPoint().x == j && a->getPoint().y == i) {
                    artifact = true;
                    if (a->getName()=="invisible") {
                        c += CYAN;
                    } else if (a->getName()=="bomb"){
                        c += RED;
                    } else {
                        c += PURPLE;
                    }
                    break;
                }
            }
            c += artifact ? DIAMOND : WHITESPACE;
            c += RESET;
            c += ' ';
            res += c;
        }
        res += "\n";
    }

    return res;
}
