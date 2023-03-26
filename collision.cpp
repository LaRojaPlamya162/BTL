#include "game.h"
#include "collision.h"
#include "obstacle.h"
#include "GameObject.h"
#include "TextureManager.h"
collision::collision(SDL_Rect Object1,SDL_Rect Object2)
{
    ObjText = TextureManager::LoadTexture("car.png");
    if (Object1.x+240 ==Object2.x&&Object1.y==Object2.y)
    {
        BombDestRect.x = Object2.x;
        BombDestRect.y = Object2.y;
        BombDestRect.w = Object2.w;
        BombDestRect.h = Object2.h;
    }
}
bool


