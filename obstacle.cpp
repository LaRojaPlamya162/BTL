#include "TextureManager.h"
#include "obstacle.h"
#include <cstdlib>
#include <ctime>
int xToaDo[5] = {0,160,320,480,640};
Obstacle::Obstacle(const char* texturesheet)
{
    srand(time(0));
    obText = TextureManager::LoadTexture(texturesheet);
    ObsSrcRect = {0,0,160,240};
    int Ran_Num = rand()% 5;
    ObsDestRect.x = xToaDo[Ran_Num];
    ObsDestRect.y = 0;
    ObsDestRect.w = ObsSrcRect.w;
    ObsDestRect.h = ObsSrcRect.h;
}
void Obstacle::Update()
{
    ObsDestRect.y =ObsDestRect.y+yVelocity;
    SDL_Delay(10);
     if (ObsDestRect.y -160>=WINDOW_HEIGHT&&yVelocity<=maxVelocity)
    {
        ObsDestRect.y = 0;
        int Ran_Num = rand()% 5;
        ObsDestRect.x = xToaDo[Ran_Num];
        yVelocity++;
    }
    if (yVelocity>maxVelocity)
    {
        yVelocity = maxVelocity;
    }

}
void Obstacle::Render()
{
    SDL_RenderCopy(Game::renderer,obText,&ObsSrcRect,&ObsDestRect);
    //SDL_RenderClear(Game::renderer);
}
