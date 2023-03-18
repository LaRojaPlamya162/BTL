#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
class Game
{
    public:
    Game();
    ~Game();
    void init(const char *title,int xpos,int ypos,int width,int height,bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running(){return isRunning;};
    static SDL_Renderer* renderer;
    //int dem=0;
    private:
    int cnt=0;
    bool isRunning;
    SDL_Window *window;
    SDL_Texture* gTexture;
    //SDL_Renderer *renderer;
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 800;
    const int CELL_SIZE = 40;

};

#endif // GAME_H
