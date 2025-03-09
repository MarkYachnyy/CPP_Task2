#include <iostream>
#include <thread>
#include <cstdlib>
#include <Windows.h>

#include "classes/game/Field.h"
#include "classes/game/Game.h"


int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    Game game(10, 10, 10, 2, 3, 20,10,3);
    for (int i = 0; i < 1000;i++) {
        game.tick();
        std::cout << "\033[H\033[2J";
        std::cout << game.print() << std::endl;
        std::flush(std::cout);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

}

