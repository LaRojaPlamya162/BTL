#pragma once
#include "game.h"
#include "textobject.h"
#include "GameObject.h"
#include "Map.h"
class Menu
{
public:
    Menu();
    ~Menu();
    void loadMenu(Game* game,Text* text);
    void RenderMenu(Text* text);
    void handleMenuEvent();
    void UpdateMenu(Game *game);
private:
    SDL_Rect MenuDestRect,MenuSourceRect;
    SDL_Rect PointerSrcRect,PointerDestRect;
    SDL_Texture* Pointer;
    bool choose;
    bool MovingUp;
    bool MovingDown;

};
