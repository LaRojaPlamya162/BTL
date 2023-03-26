#pragma once
#include "game.h"
class Obstacle
{
public :
    Obstacle(const char* texturesheet);
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
    float yVelocity = 1;
    SDL_Texture* obText;
    SDL_Rect ObsSrcRect,ObsDestRect;
    const int maxVelocity = 5;
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 800;
};
