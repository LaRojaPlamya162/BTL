#include "game.h"
#include "textobject.h"
Text::Text()
{
}
void Text::RenderText(const char* file,int ptsize,SDL_Color color,std::string s,int x,int y)
{
    font = TTF_OpenFont(file,ptsize);
    SDL_Surface* text;
    text = TTF_RenderText_Solid(font,s.c_str(),color);
    SDL_Texture* gText = SDL_CreateTextureFromSurface(Game::renderer,text);
    SDL_Rect Destination;
    Destination.x = x;
    Destination.y = y;
    Destination.w = text->w;
    Destination.h = text->h;
    SDL_RenderCopy(Game::renderer,gText,NULL,&Destination);
    SDL_DestroyTexture(gText);
    SDL_FreeSurface(text);
}
void Text::EndGame(int diem,int highscore,const char* filename,SDL_Color color,GameObject* cityzen1,GameObject* cityzen2)
{
    std::string DIEM = std::to_string(diem);
    if (diem>highscore&&cityzen1->CheckCollision(cityzen1->PlayerGetRect(),cityzen2->ObstacleGetRect()))
    {
        SDL_Delay(2000);
        RenderText(filename,50,color,"New Record",250,350);
        RenderText(filename,40,color,DIEM,350,500);
        SDL_RenderPresent(Game::renderer);
        SDL_Delay(5000);
        finish=true;
    }
    else if (diem<=highscore&&cityzen1->CheckCollision(cityzen1->PlayerGetRect(),cityzen2->ObstacleGetRect()))
    {
        SDL_Delay(2000);
        RenderText(filename,50,color,"Your Score",250,350);
        RenderText(filename,40,color,DIEM,350,500);
        SDL_RenderPresent(Game::renderer);
        SDL_Delay(5000);
        finish=true;

    }
}

