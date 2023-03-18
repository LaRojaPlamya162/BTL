#pragma once
#include "game.h"
class GameObject
{
public :
    GameObject(const char* texturesheet,int x,int y,int _width,int _height);
    ~GameObject();
    void Update();
    void Render();
    bool MoveLeft = false;
    bool MoveRight = false;
    bool MoveUp = false;
    bool MoveDown = false;
private:
    int xpos;
    int ypos;
    int XPOS;
    int YPOS;
    int width;
    int height;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 800;
    const int PATH_SIZE = 160;
    const int PATH_JUMP = 120;
};
