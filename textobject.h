#pragma once
#include "game.h"
class Text
{
public:
    Text();
    ~Text();
    void RenderText(const char* file,int ptsize,SDL_Color color,std::string s,int x,int y);
private:
TTF_Font* font;
};

