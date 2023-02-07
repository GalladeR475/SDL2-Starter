#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#define LOG(x) std::cout << x << std::endl


class Game {
    private:
        bool is_running;
        int flags = 0;
        int count = 0;
        SDL_Window *win;
        SDL_Renderer *ren;
    public:
        Game(const char *title, int w, int h, bool f);
        ~Game();
        bool running();
        void handle();
        void update();
        void render();

};

#endif