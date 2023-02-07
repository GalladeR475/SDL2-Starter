#include "include/game.hpp"

Game::Game(const char *title, int w, int h, bool f) {
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        LOG("Initialization has started...");
        if(f) { flags = SDL_WINDOW_FULLSCREEN; }
        win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);

        if(win) { LOG("Window created..."); }
        
        ren = SDL_CreateRenderer(win, -1, 0);
        
        if(ren) { 
            SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
            LOG("Renderer created..."); }

        is_running = true;
    } else {
        LOG("Initialization has failed..." << SDL_GetError());
        is_running = false;
    }
}
Game::~Game() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
    LOG("Finalization complete...");
    LOG("Exited successfully...");
}

bool Game::running() { return is_running; }

void Game::handle() {
    SDL_Event eve;
    SDL_PollEvent(&eve);

    switch(eve.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        default:
            break;
    }

}
void Game::update() {
    count++;
    LOG(count);
}

void Game::render() {
    SDL_RenderClear(ren);
    // Rendering stuff here
    SDL_RenderPresent(ren);
}

