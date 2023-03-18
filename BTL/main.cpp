#include "game.h"
Game *game =nullptr;
int main(int argc,char *argv[])
{
    game = new Game();
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;
    static const int WINDOW_HEIGHT = 800;
    static const int WINDOW_WIDTH = 800;
    //const int CELL_SIZE = 40;
    game ->init("SDL Tutorial",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,false);
    while (game->running())
    {
        frameStart = SDL_GetTicks();
        game -> handleEvents();
        game ->update();
        game ->render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}

