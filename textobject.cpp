//#include <SDL_ttf.h>
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
/*TextObject::TextObject()
{
    text_color_.r = 255;
    text_color_.g = 255;
    text_color_.b = 255;
    texture_ = NULL;
}
TextObject::~TextObject()
{

}
bool TextObject::LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen)
{
    SDL_Surface* text_surface = TTF_RenderText_Solid(font,str_val_.c_str(),text_color_,)
    if (text_surface)
    {
        texture_=SDL_CreateTextureFromSurface(screen,text_surface);
        width_=text_surface->w;
        height_=text_surface->h;
        SDL_FreeSurface(text_surface);

    }
    return texture!=NULL;
}
void TextObject::Free()
{
    if(texture!=NULL)
    {
        SDL_DestroyTexture(texture_);
        texture_=NULL;
    }

}
void TextObject::SetColor(Uint8 red,Uint8 greeen,Uint8 blue)
{
    text_color_.r = red;
    text_color_.g = green;
    text_color_.b = blue;

}
void TextObject::SetColor(int type)
{
    if(type==RED_TEXT)
    {
      SDL_Color color = {255,0,0};
      text_color = color;
    }
    else if(type==WHITE_TEXT)
    {
        SDL_Color color = {255,255,255};
        text_color = color;
    }
    else if(type==BLACK_TEXT)
    {
        SDL_Color color = {0,0,0};
        text_color = color;
    }
}
void TextObject::RenderText(SDL_Renderer* screen,int xp,int yp, SDL_Rect* clip = NULL, double angle =0.0,SDL_Point* center = NULL,SDL_RendererFlip flip = SDL_FLIP_NONE)
{
    SDL_Rect renderQuad = {x,y,width_,height_};
    if (clip!=NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx(screen,texture_,clip,&RenderQuad,angle,center,flip);

}*/
