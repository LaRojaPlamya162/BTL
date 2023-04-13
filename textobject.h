#pragma once
#include "game.h"
#include "GameObject.h"
class Text
{
public:
    Text();
    ~Text();
    void RenderText(const char* file,int ptsize,SDL_Color color,std::string s,int x,int y);
    void EndGame(int diem,int hiscore,const char* filename,SDL_Color color,GameObject* cityzen1,GameObject* cityzen2,Game* GAME);
private:
TTF_Font* font;
};

