#pragma once
#include "game.h"
class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    void Draw(int WINDOW_HEIGHT,int WINDOW_WIDTH);
    void LoadBackground(const char* filename);
private:
    SDL_Rect StartRect,DestRect;
};

