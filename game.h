#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <bits/stdc++.h>
class Game
{
    public:
    Game();
    ~Game();
    void init(const char *title,int xpos,int ypos,int width,int height,bool fullscreen);
    void handleEvents();
    void update();
    void MenuRender();
    void render();
    void clean();
    void Restart();
    bool running(){return isRunning;};
    bool menuInit(){return Menuinit;};
    //void RUNNING();
    static SDL_Renderer* renderer;
    SDL_Window *window;
    int diem=0;
    bool isRunning;
    bool Menuinit;
    bool MovingUp=false;
    bool MovingDown=false;
    bool choose=false;
    int dem=0;
    bool keyPressed=false;
    private:
    //SDL_Window *window;
    SDL_Texture* gTexture;
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 800;
    const int CELL_SIZE = 40;
    SDL_Rect MenuDestRect,MenuSourceRect;
    SDL_Rect PointerSrcRect,PointerDestRect;
    SDL_Texture* Pointer;
};

#endif // GAME_H
