#include "TextureManager.h"
#include "obstacle.h"
#include <cstdlib>
#include <ctime>
int xToaDo[5] = {0,160,320,480,640};
Obstacle::Obstacle(const char* texturesheet,int _width,int _height)
{
    srand(time(0));
    obText = TextureManager::LoadTexture(texturesheet);
    width = _width;
    height = _height;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 160;
    srcRect.h = 240;
    int Ran_Num = rand()% 5;
    destRect.x = xToaDo[Ran_Num];
    destRect.y = 0;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}
void Obstacle::Update()
{
    destRect.y =destRect.y+yVelocity;
     if (destRect.y -160>=WINDOW_HEIGHT)
    {
        destRect.y = 0;
        int Ran_Num = rand()% 5;
        destRect.x = xToaDo[Ran_Num];
    }
}
void Obstacle::Render()
{
    SDL_RenderCopy(Game::renderer,obText,&srcRect,&destRect);
    //SDL_RenderClear(Game::renderer);
}
