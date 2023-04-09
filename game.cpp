#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "textobject.h"
#include "audio.h"
#include "highscore.h"
#include "Map.h"
GameObject* player;
GameObject* obstacle;
Text* text;
TextureManager* border;
SDL_Renderer* Game::renderer = nullptr;
Map* map;
Audio* audio;
HighscoreManager* highscoremanager ;
SDL_Color color = {255,255,255};
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
            std::cout<<"Subsystem Intialised!..."<<std::endl;
            window=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
            if (window)
            {
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                std::cout<<"Window created"<<std::endl;
            }
        renderer = SDL_CreateRenderer(window,-1,0);
        if (renderer)
        {
            std::cout<<"Renderer created"<<std::endl;
        }
        isRunning = true;
        }

        /*if (TTF_Init()==-1)
        {
            text->success = false;
        }
        else
        {
            text->success = true;
        }
        if (text->success = false)
        {
            std::cout <<"Intialize fonts failed"<<std::endl;
        }
        else
        {
            std::cout <<"Intialize completed"<<std::endl;
        }*/
        player =  new GameObject("Car.png",WINDOW_WIDTH,560);
        obstacle = new GameObject("ObstacleCar.png",NULL,NULL);
        map = new Map();
        text = new Text();
        audio = new Audio();
        //highscoremanager = new HighscoreManager();

    }
void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        {
            isRunning = false;
            break;
        }
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
                case SDLK_UP:
                    player->MoveUp = true;
                    player->MoveDown = false;
                    player->MoveLeft = false;
                    player->MoveRight = false;
                    break;
                case SDLK_DOWN:
                    player->MoveUp = false;
                    player->MoveDown = true;
                    player->MoveLeft = false;
                    player->MoveRight = false;
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
                default:
                    break;
        }
    }
}

void Game::update()
{
    obstacle->ObstacleUpdate();
    player->PlayerUpdate();
    diem++;
    if (player->CheckCollision(player->PlayerGetRect(),obstacle->ObstacleGetRect()))
    {
        SDL_DestroyWindow(window);
    }
    /*if(highscoremanager->addHighscore(diem)&&!isRunning)
    {
        //std::cout << diem;
    }
*/
}
void Game::render()
{

    std::string DIEM = std::to_string(diem);
    SDL_RenderClear(Game::renderer);
    map ->DrawMap();
    player->PlayerRender();
    obstacle->ObstacleRender();
    border ->Appear(WINDOW_HEIGHT,WINDOW_WIDTH);
    text->RenderText("OpenSans-Bold.ttf",50,color,DIEM,360,0);
    //audio->OpenAudio("GameSound.wav");
    SDL_RenderPresent(Game::renderer);
    }

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Game::renderer);
    SDL_Quit();
    std::cout <<"Game Cleared"<<std::endl;
}
