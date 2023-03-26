#pragma once
#include "game.h"
class GameObject
{
public :
    GameObject(const char* texturesheet,int x,int y);
    ~GameObject();
    void PlayerUpdate();
    void ObstacleUpdate();
    void PlayerRender();
    void ObstacleRender();
    bool Collision(SDL_Rect Object1,SDL_Rect Object2);
    SDL_Rect PlayerGetRect();
    SDL_Rect ObstacleGetRect();
    bool MoveLeft = false;
    bool MoveRight = false;
    bool MoveUp = false;
    bool MoveDown = false;
    SDL_Rect ObjSrcRect,ObjDestRect;
    SDL_Rect ObsSrcRect,ObsDestRect;
    SDL_Texture* objTexture;
    SDL_Texture* obsTexture;
private:
    int xpos;
    int ypos;
    int XPOS;
    int YPOS;
    int width;
    int height;
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 800;
    const int PATH_SIZE = 160;
    const int PATH_JUMP = 120;
    const int CAR_WIDTH = 160;
    const int CAR_LENGTH = 240;
    SDL_Texture* m_texture;
    int yVelocity = 1;
    const int maxVelocity = 5;
};


