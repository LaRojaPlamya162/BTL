#pragma once
#include "game.h"
class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* texturesheet);
    static void Draw(SDL_Texture *tex,SDL_Rect src,SDL_Rect dest);
    void LoadImageFile(const char* filename,int _x,int _y,int _width,int _height);
    void Appear(int WINDOW_HEIGHT,int WINDOW_WIDTH);
private:
    SDL_Rect StartRect,DestRect;
};

