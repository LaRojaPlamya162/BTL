#include "GameObject.h"
#include "TextureManager.h"
GameObject::GameObject(const char* texturesheet,int x,int y,int _width,int _height)
{
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
    width = _width;
    height = _height;

}
void GameObject::Update()
{

    if(MoveLeft)
        {
            xpos=xpos-PATH_SIZE;
            MoveLeft=false;
        }
    if(MoveRight)
    {
            xpos=xpos+PATH_SIZE;
            MoveRight=false;
    }
    if(MoveUp)
    {
        ypos=ypos-PATH_JUMP;
        MoveUp=false;
    }
    if(MoveDown)
    {
        ypos=ypos+PATH_JUMP;
        MoveDown=false;
    }
    srcRect.x = 0;
    srcRect.w = 160;
    srcRect.h = 240;
    srcRect.y = 0;
    destRect.x = xpos;
    destRect.y = ypos;;
    destRect.w = 160;
    destRect.h = 240;
}
void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
    SDL_RenderPresent(Game::renderer);
}
