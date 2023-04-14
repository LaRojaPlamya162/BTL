#include "game.h"
#include "Menu.h"
#include "textobject.h"
#include "TextureManager.h"
#include "Map.h"
Menu::Menu()
{
}
void Menu::loadMenu(Game* game,Text* text)
{
    //std::cout <<game->menuInit()<<std::endl;
    if (game->running())
    {
        RenderMenu(text);
        handleMenuEvent();
        UpdateMenu(game);
        SDL_RenderPresent(Game::renderer);
    }
}
void Menu::RenderMenu(Text *text)
{
    //Pointer = TextureManager::LoadTexture("pointer.png");
    //PointerSrcRect = {0,0,30,30};
    //TextureManager::Draw(Pointer,PointerSrcRect,PointerDestRect);*/
    Pointer = TextureManager::LoadTexture("pointer.png");
    PointerSrcRect = {0,0,30,30};
    PointerDestRect = {200,300,30,30};
    SDL_Texture* tex = TextureManager::LoadTexture("car.png");
    MenuDestRect = {200,200,400,400};
    MenuSourceRect = {0,0,400,400};
    SDL_Color white = {255,255,255};
    TextureManager::Draw(tex,MenuSourceRect,MenuDestRect);
    text->RenderText("OpenSans-Bold.ttf",30,white,"Exit",300,350);
    text->RenderText("OpenSans-Bold.ttf",30,white,"Start Game",300,450);
    }
void Menu::handleMenuEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        // Xử lý phím mũi tên lên
                        MovingUp = true;
                        MovingDown = false;
                        break;
                    case SDLK_DOWN:
                        // Xử lý phím mũi tên xuống
                        MovingUp = false;
                        MovingDown = true;
                        break;
                    case SDLK_RETURN:
                        // Xử lý phím Enter
                        choose = true;
                        break;
                    default:
                        break;
                }
                /*break;
            default:
                break;*/
        }
}
}
void Menu::UpdateMenu(Game* game)
{
        // Xử lý khi nhấn phím Enter
            if (MovingUp) {
            // Xử lý khi nhấn phím mũi tên lên
            PointerSrcRect = {0,0,30,30};
            PointerDestRect = {200,300,30,30};
            PointerDestRect.y = 350;
            TextureManager::Draw(Pointer, PointerSrcRect, PointerDestRect);
            MovingDown = false;
            if (choose)
            {
            game->isRunning = false;
            game->Menuinit = true;
            choose = false;
            MovingUp=false;
            MovingDown=false;
           std::cout<<game->running()<<" "<<game->menuInit()<<std::endl;
            }
        }
            else if(MovingDown)
        {
            // Xử lý khi nhấn phím mũi tên xuống
            PointerSrcRect = {0,0,30,30};
            PointerDestRect = {200,300,30,30};
            PointerDestRect.y = 450;
            TextureManager::Draw(Pointer, PointerSrcRect, PointerDestRect);
            MovingUp = false;
            //std::cout <<"MovingDown on"<<std::endl;
            if(choose)
            {
            game->isRunning = true;
            game->Menuinit = true;
            choose=false;
            MovingUp=false;
            MovingDown=false;
            std::cout<<game->running()<<" "<<game->menuInit()<<std::endl;
            }
        }
}

