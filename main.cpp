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
    while(game->menuInit()==false)
    {
        //frameStart = SDL_GetTicks();
        //game -> handleEvents();
        //game ->update();
        //std::cout << game->Menuinit<<std::endl;
        game->MenuRender();
        //std::cout << game->Menuinit<<std::endl;
        //game ->render();
        //frameTime = SDL_GetTicks() - frameStart;
        //if (frameDelay > frameTime)
        //{
            //SDL_Delay(frameDelay - frameTime);
        //std::cout <<"Loops"<<std::endl;
        //break;
    }
    while(game->menuInit()==true)
    {
        game -> handleEvents();
        game ->update();
        //game->MenuRender();
        game ->render();
    }
    }
       return 0;
    }



