#include "GameObject.h"
#include "TextureManager.h"
#include <ctime>
#include <cstdlib>
int ToaDo[5]={0,160,320,480,640};
GameObject::GameObject(const char *texturesheet,int x,int y)
{
objTexture = TextureManager::LoadTexture(texturesheet);
xpos = x;
ypos = y;
ObsDestRect = {0,0,160,240};
ObjDestRect = {0,0,160,560};
}
void GameObject::PlayerUpdate()
{
    //SDL_RenderClear(Game::renderer);
    if(MoveLeft)
        {
            xpos=xpos-PATH_SIZE;
            MoveLeft=false;
            SDL_Delay(10);
            if (xpos<0)
            {
                xpos = xpos + PATH_SIZE;
            }
        }
    else if(MoveRight)
    {
            xpos=xpos+PATH_SIZE;
            MoveRight=false;
            SDL_Delay(10);
            if (xpos>WINDOW_WIDTH-CAR_WIDTH)
            {
                xpos = xpos - PATH_SIZE;
            }
    }
    if(MoveUp)
    {
        ypos=ypos-PATH_JUMP;
        MoveUp=false;
        SDL_Delay(10);
        if (ypos<0)
        {
            ypos = ypos + PATH_JUMP;
        }
    }
    else if(MoveDown)
    {
        ypos=ypos+PATH_JUMP;
        MoveDown=false;
        SDL_Delay(10);
        if (ypos >WINDOW_HEIGHT-CAR_WIDTH)
        {
            ypos = ypos - PATH_JUMP;
        }
    }
    ObjSrcRect.x = 0;
    ObjSrcRect.w = CAR_WIDTH;
    ObjSrcRect.h = CAR_LENGTH;
    ObjSrcRect.y = 0;
    ObjDestRect.x = xpos;
    ObjDestRect.y = ypos;;
    ObjDestRect.w = CAR_WIDTH;
    ObjDestRect.h = CAR_LENGTH;
}
void GameObject::ObstacleUpdate()
{
    srand(time(0));
    ObsSrcRect = {0,0,160,240};
    SDL_Delay(10);
    ObsDestRect.y = ObsDestRect.y+yVelocity;
     if (ObsDestRect.y -160>=WINDOW_HEIGHT&&yVelocity<=maxVelocity)
    {
        int Ran_Num = rand()% 5;
        ObsDestRect.x = ToaDo[Ran_Num];
        yVelocity++;
        ObsDestRect.y=0;
    }
    if (yVelocity>maxVelocity)
    {
        yVelocity = maxVelocity;
    }
}

void GameObject::PlayerRender()
{
    SDL_RenderCopy(Game::renderer,objTexture,&ObjSrcRect,&ObjDestRect);
    //SDL_RenderPresent(Game::renderer);
}
void GameObject::ObstacleRender()
{
    SDL_RenderCopy(Game::renderer,objTexture,&ObsSrcRect,&ObsDestRect);
}

bool GameObject::Collision(SDL_Rect Object1,SDL_Rect Object2)
{
    if (Object1.x==Object2.x&&Object1.y==Object2.y+240)
    {
        return true;
    }
    else return false;
}
SDL_Rect GameObject::PlayerGetRect()
{
    SDL_Rect rect;
    rect.x = ObjDestRect.x;
    rect.y = ObjDestRect.y;
    rect.w = ObjDestRect.w;
    rect.h = ObjDestRect.h;
    return rect;
}
SDL_Rect GameObject::ObstacleGetRect()
{
    SDL_Rect rect;
    rect.x = ObsDestRect.x;
    rect.y = ObsDestRect.y;
    rect.w = ObsDestRect.w;
    rect.h = ObsDestRect.h;
    return rect;
}





