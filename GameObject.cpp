#include "GameObject.h"
#include "TextureManager.h"
#include <ctime>
#include <cstdlib>
int ToaDo[5]={28,188,348,508,668};
GameObject::GameObject(const char *texturesheet,int x,int y)
{
objTexture = TextureManager::LoadTexture(texturesheet);
xpos = x;
ypos = y;
ObsDestRect = {28,0,124,180};
ObjDestRect = {0,0,124,560};
}
GameObject::~GameObject()
{
    delete objTexture;
}
void GameObject::PlayerUpdate()
{
    //SDL_RenderClear(Game::renderer);
    if(MoveLeft)
        {
            xpos=xpos-160;
            MoveLeft=false;
            SDL_Delay(10);
            if (xpos<0)
            {
                xpos = xpos + 160;
            }
        }
    else if(MoveRight)
    {
            xpos=xpos+160;
            MoveRight=false;
            SDL_Delay(10);
            if (xpos>WINDOW_WIDTH-CAR_WIDTH)
            {
                xpos = xpos - 160;
            }
    }
    if(MoveUp)
    {
        ypos=ypos-10;
        MoveUp=false;
        SDL_Delay(10);
        if (ypos<0)
        {
            ypos = ypos + 10;
        }
    }
    else if(MoveDown)
    {
        ypos=ypos+10;
        MoveDown=false;
        SDL_Delay(10);
        if (ypos >WINDOW_HEIGHT-CAR_LENGTH)
        {
            ypos = ypos-10;
        }
    }
    ObjSrcRect.x = 0;
    ObjSrcRect.y = 0;
    ObjSrcRect.w = CAR_WIDTH;
    ObjSrcRect.h = CAR_LENGTH;
    ObjDestRect.x = xpos;
    ObjDestRect.y = ypos;
    ObjDestRect.w = CAR_WIDTH;
    ObjDestRect.h = CAR_LENGTH;
}
void GameObject::ObstacleUpdate(GameObject* Player, int diem)
{
    if(Player->MoveDown==true||Player->MoveUp==true||Player->MoveRight==true||Player->MoveLeft==true)dem++;
    if(dem>0)
    {
    srand(time(0));
    SDL_Delay(10);
    ObsSrcRect = {0,0,124,170};
    ObsDestRect.y = ObsDestRect.y+yVelocity;
    if(diem>2000)
    {
    if(DIEM>0)
    {
      DIEM--;
    }
    if(DIEM==0)
    {
        int Ran_Num1 = rand()% 5;
        ObsDestRect.x= ToaDo[Ran_Num1];
        DIEM=DEM;
        DEM=DEM-5;
    }
    if(DEM<100)
    {
        DEM=100;
    }
    }
    if (ObsDestRect.y-170>=WINDOW_HEIGHT)
    {
        int Ran_Num2 = rand()% 5;
        ObsDestRect.x = ToaDo[Ran_Num2];
        yVelocity++;
        ObsDestRect.y=0;
    }
    if (yVelocity>maxVelocity)
    {
        yVelocity = maxVelocity;
    }
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

bool GameObject::CheckCollision(SDL_Rect Object1,SDL_Rect Object2)
{
    if((Object1.x==Object2.x&&Object1.y>=Object2.y&&Object1.y<=Object2.y+170)||(Object1.x==Object2.x&&Object1.y+170<=Object2.y+170&&Object1.y+170>=Object2.y))
    {
        finish = true;
    }
    else finish = false;
    return finish;
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
bool GameObject::Finish()
{
    return CheckCollision(PlayerGetRect(),ObstacleGetRect());
}








