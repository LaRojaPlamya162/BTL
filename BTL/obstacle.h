#pragma once
#include "game.h"
class Obstacle
{
public :
    Obstacle(const char* texturesheet,int _width,int _height);
    ~Obstacle();
    void Update();
    void Render();
private:
    int xpos;
    int ypos;
    int XPOS;
    int YPOS;
    int width;
    int height;
    int yVelocity = 50;
    SDL_Texture* obText;
    SDL_Rect srcRect, destRect;
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 800;
};
