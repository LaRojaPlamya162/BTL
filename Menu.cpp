#include "game.h"
#include "Menu.h"
#include "textobject.h"
#include "TextureManager.h"
Menu::Menu()
{
    Pointer = TextureManager::LoadTexture("pointer.png");
}
void Menu::RenderMenu(Text *mText)
{
    SDL_RenderClear(Game::renderer);
    PointerSrcRect = {0,0,30,30};
    PointerDestRect = {200,300,30,30};
    MenuDestRect = {200,200,400,400};
    MenuSourceRect = {0,0,400,400};
    SDL_Color white = {255,255,255};
    mText->RenderText("OpenSans-Bold.ttf",30,white,"Exit",300,350);
    mText->RenderText("OpenSans-Bold.ttf",30,white,"Start Game",300,450);
    }
/*void Menu::handleMenuEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                keyPressed=true;
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        // Xử lý phím mũi tên lên
                        MovingUp = true;
                        MovingDown = false;
                        break;
                    case SDLK_DOWN:
                        // Xử lý phím mũi tên xuống
                        MovingDown = true;
                        MovingUp = false;
                        break;
                    case SDLK_RETURN:
                        // Xử lý phím Enter
                        choose = true;
                        break;
                    default:
                        break;
                }
}
}
}*/
void Menu::UpdateMenu()
{
            {
            if (MovingUp==true){
            // Xử lý khi nhấn phím mũi tên lên
            PointerDestRect.y = 350;
            TextureManager::Draw(Pointer, PointerSrcRect, PointerDestRect);
            if (choose==true)
            {
            running = false;
            menuInit = false;
            MovingDown = NULL;
            MovingUp = true;
            choose = NULL;
            exit(0);
            }
        }
            if(MovingDown==true)
        {
            // Xử lý khi nhấn phím mũi tên xuống
            PointerDestRect.y = 450;
            TextureManager::Draw(Pointer, PointerSrcRect, PointerDestRect);
            if(choose==true)
            {
            running = true;
            menuInit = false;
            MovingDown = true;
            MovingUp = NULL;
            choose = NULL;
            keyPressed=false;
            }
        }
}
}

