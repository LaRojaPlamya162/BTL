
#pragma once
#include "game.h"
#include "obstacle.h"
#include "GameObject.h"
class collision
{
public:
collision(SDL_Rect Object1,SDL_Rect Object2);
~collision();
private:
SDL_Rect BombDestRect;
const SDL_Rect BombSrcRect = {0,0,160,240};
const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 800;
SDL_Texture* ObjText;
};
