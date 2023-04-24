#pragma once
#include "game.h"
#include "textobject.h"
#include "Map.h"
#include "TextureManager.h"
class Menu
{
public:
    Menu();
    ~Menu();
    void RenderMenu(Text* mText);
    void UpdateMenu();
    bool choose;
    bool MovingUp;
    bool MovingDown;
    bool MenuInit(){return menuInit;};
    bool WindowInit(){return running;};
private:
    SDL_Rect MenuDestRect,MenuSourceRect;
    SDL_Rect PointerSrcRect,PointerDestRect;
    SDL_Texture* Pointer;
    bool menuInit=true;
    bool running=true;
    bool keyPressed=true;
};
