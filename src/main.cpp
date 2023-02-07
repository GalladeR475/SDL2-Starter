#include <SDL2/SDL.h>
#include "include/game.hpp"

Game *gm = nullptr;

int main() {
    gm = new Game("man", 960, 640, false);
    
    while(gm->running()) {
        gm->handle();
        gm->update();
        gm->render();
    }
    delete gm;

    return 0;
}