#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "textobject.h"
//#include "audio.h"
#include "highscore.h"
#include "Map.h"
#include "Menu.h"
GameObject* player;
GameObject* obstacle;
Text* text;
TextureManager* border;
SDL_Renderer* Game::renderer = nullptr;
Map* map;
//Audio* audio;
Menu* MenuPointer;
HighscoreManager* highscoremanager ;
SDL_Color yellow = {255,255,0};
SDL_Color white = {255,255,255};
SDL_Color red = {255,0,0};
Game::Game()
{}
Game::~Game()
{}
void Game::init(const char *title,int xpos,int ypos,int width,int height,bool fullscreen)
    {
        int flags=0;
        if(fullscreen)
        {
            flags=SDL_WINDOW_FULLSCREEN;
        }
        if (SDL_Init(SDL_INIT_EVERYTHING)==0)
        {
            //std::cout<<"Subsystem Intialised!..."<<std::endl;
            window=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
            if (window)
            {
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                //std::cout<<"Window created"<<std::endl;
            }
        renderer = SDL_CreateRenderer(window,-1,0);
        //if (renderer)
        {
            //std::cout<<"Renderer created"<<std::endl;
        }
        isRunning = true;
        Menuinit=true;
        }
        player =  new GameObject("Car.png",668,630);
        obstacle = new GameObject("ObstacleCar.png",NULL,NULL);
        map = new Map();
        text = new Text();
        //audio = new Audio();
        highscoremanager = new HighscoreManager();
        MenuPointer = new Menu();
    }
void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        {
            isRunning=false;
            break;
        }
    case SDL_KEYDOWN:
        keyPressed=true;
        switch(event.key.keysym.sym)
        {
                case SDLK_UP:
                    player->MoveUp = true;
                    player->MoveDown = false;
                    player->MoveLeft = false;
                    player->MoveRight = false;
                    MenuPointer->MovingDown=false;
                    MenuPointer->MovingUp=true;
                    MovingDown=false;
                    MovingUp=true;
                    break;
                case SDLK_DOWN:
                    player->MoveUp = false;
                    player->MoveDown = true;
                    player->MoveLeft = false;
                    player->MoveRight = false;
                    MenuPointer->MovingDown=true;
                    MenuPointer->MovingUp=false;
                    MovingDown=true;
                    MovingUp=false;
                    break;
                case SDLK_LEFT:
                    player->MoveUp = false;
                    player->MoveDown = false;
                    player->MoveLeft = true;
                    player->MoveRight = false;
                    break;
                case SDLK_RIGHT:
                    player->MoveUp = false;
                    player->MoveDown= false;
                    player->MoveLeft = false;
                    player->MoveRight = true;
                    break;
                case SDLK_RETURN:
                    MenuPointer->choose = true;
                    choose=true;
                    break;
                default:
                    break;
        }
    }
    if(player->MoveDown==true||player->MoveUp==true||player->MoveRight==true||player->MoveLeft==true)dem++;
}

void Game::update()
{
    obstacle->ObstacleUpdate(player,diem);
    player->PlayerUpdate();
    if(dem>0)diem++;
}
void Game::MenuRender()

{
    SDL_RenderClear(Game::renderer);
    map->DrawMap();
    border->Appear(WINDOW_HEIGHT,WINDOW_WIDTH);
    Pointer = TextureManager::LoadTexture("pointer.png");
    PointerSrcRect = {0,0,30,30};
    PointerDestRect = {500,300,30,30};
    text->RenderText("OpenSans-Bold.ttf",30,yellow,"Exit",300,350);
    text->RenderText("OpenSans-Bold.ttf",30,yellow,"Start Game",300,450);
    if(keyPressed==true)
    {
        if(MovingUp==true)
        {
            PointerDestRect.y = 350;
            TextureManager::Draw(Pointer, PointerSrcRect, PointerDestRect);
            if (choose==true)
            {
            isRunning=false;
            Menuinit=false;
            MovingDown = NULL;
            MovingUp = NULL;
            choose = NULL;
            keyPressed= NULL;
            exit(0);
            }
        }
    if(MovingDown==true)
        {
            PointerDestRect.y = 450;
            TextureManager::Draw(Pointer, PointerSrcRect, PointerDestRect);
            if(choose==true)
            {
            isRunning=true;
            Menuinit=false;
            MovingDown = NULL;
            MovingUp = NULL;
            choose = NULL;
            keyPressed= NULL;
            }
        }
}
SDL_RenderPresent(Game::renderer);
}
void Game::render()
{
    std::string DIEM = std::to_string(diem);
    SDL_RenderClear(Game::renderer);
    map ->DrawMap();
    player->PlayerRender();
    obstacle->ObstacleRender();
    border ->Appear(WINDOW_HEIGHT,WINDOW_WIDTH);
    text->RenderText("OpenSans-Regular.ttf",50,red,DIEM,360,0);
    text->EndGame(diem,highscoremanager->addHighscore(diem),"OpenSans-Bold.ttf",red,player,obstacle);
    if(text->Finish()==true) Menuinit=true;//isRunning=false;
    else Menuinit=false;//isRunning=true;
    SDL_RenderPresent(Game::renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Game::renderer);
    SDL_Quit();
    std::cout <<"Game Cleared"<<std::endl;
}
void Game::Restart()
{
    if(text->Finish()==true)
    {
        player =  new GameObject("Car.png",668,630);
        obstacle = new GameObject("ObstacleCar.png",NULL,NULL);
        map = new Map();
        text = new Text();
        //audio = new Audio();
        highscoremanager = new HighscoreManager();
        //MenuPointer = new Menu();
        diem=0;
        dem=0;
        text->finish=false;
    }
}


