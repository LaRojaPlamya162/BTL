#pragma once
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer,tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}

void TextureManager::Draw(int WINDOW_HEIGHT,int WINDOW_WIDTH)
{
    for (int i=0;i<=WINDOW_WIDTH;i+=WINDOW_WIDTH/5)
    {
        SDL_RenderDrawLine(Game::renderer,i,0,i,WINDOW_HEIGHT);
        SDL_RenderPresent(Game::renderer);
    }
}
void TextureManager::LoadBackground(const char* filename)
{
    SDL_Texture* text = TextureManager::LoadTexture(filename);
    StartRect.x = 0;
    StartRect.y = 0;
    StartRect.w = 820;
    StartRect.h = 820;
    DestRect.x =StartRect.x;
    DestRect.y =StartRect.y;
    DestRect.w =StartRect.w;
    DestRect.h =StartRect.h;
    SDL_RenderCopy(Game::renderer,text,&StartRect,&DestRect);
    SDL_RenderPresent(Game::renderer);
}
//void TextureManager::DestroyRenderer(SDL_RenderClear)
