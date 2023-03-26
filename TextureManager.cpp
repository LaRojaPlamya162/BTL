#pragma once
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texturesheet)
{
    SDL_Surface* tempSurface = IMG_Load(texturesheet);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer,tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}

void TextureManager::Appear(int WINDOW_HEIGHT,int WINDOW_WIDTH)
{
    for (int i=0;i<=WINDOW_WIDTH;i+=WINDOW_WIDTH/5)
    {
        SDL_RenderDrawLine(Game::renderer,i,0,i,WINDOW_HEIGHT);
    }
}
void TextureManager::Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer,tex,&src,&dest);
}
void TextureManager::LoadImageFile(const char* filename,int _x,int _y,int _width,int _height)
{
    SDL_Texture* text = TextureManager::LoadTexture(filename);
    StartRect.x = _x;
    StartRect.y = _y;
    StartRect.w = _width;
    StartRect.h = _height;
    DestRect.x =StartRect.x;
    DestRect.y =StartRect.y;
    DestRect.w =StartRect.w;
    DestRect.h =StartRect.h;
    SDL_RenderCopy(Game::renderer,text,&StartRect,&DestRect);
    //SDL_RenderPresent(Game::renderer);
}
//void TextureManager::DestroyRenderer(SDL_RenderClear)
