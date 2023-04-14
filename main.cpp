#include "game.h"
#include "SDL_ttf.h"
Game *game =nullptr;
int main(int argc,char *argv[])
{
    game = new Game();
    TTF_Init();
    //Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    //const int FPS = 60;
    //const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;
    static const int WINDOW_HEIGHT = 800;
    static const int WINDOW_WIDTH = 800;
    game ->init("Obstacle",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,false);
    while(game->running()==true)
    {
    while(game->menuInit()==true)
    {
        game->MenuRender();
    }
    while(game->menuInit()==false)
    {
        game -> handleEvents();
        game ->update();
        game ->render();
    }
    }
       return 0;
    }



