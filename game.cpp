#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
//#include "obstacle.h"
#include "Map.h"
GameObject* player;
GameObject* obstacle;
//Obstacle* obstacle;
//SDL_Texture* texture;
//GameObject* enemy;
TextureManager* border;
TextureManager* background;
SDL_Renderer* Game::renderer = nullptr;
Map* map;
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
        background = new TextureManager();
        //enemy = new GameObject("foo.png",50,50);
        player =  new GameObject("Car.png",WINDOW_WIDTH,560);
        obstacle = new GameObject("ObstacleCar.png",NULL,NULL);
        //obstacle = new GameObject("car.png","ObstacleCar.png",WINDOW_WIDTH*2/5,560);
        //border = new TextureManager();
        map = new Map();
        //playerTex = TextureManager::LoadTexture("pikachu.png",renderer);
        /*else
        {
            isRunning = false;
        }*/
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
    SDL_Rect Player = player->PlayerGetRect();
    SDL_Rect ObStacle = obstacle->ObstacleGetRect();
    if (player->Collision(Player,ObStacle))
    {
        SDL_DestroyWindow(window);
    }
    //Obstacle->ObstacleUpdate();
    //enemy -> Update();

}
void Game::render()
{
    //SDL_RenderCopy(renderer,playerTex,NULL,NULL);
    //SDL_RenderClear(Game::renderer);
    SDL_RenderClear(Game::renderer);
    map ->DrawMap();
    player->PlayerRender();
    obstacle->ObstacleRender();
    border ->Appear(WINDOW_HEIGHT,WINDOW_WIDTH);
    SDL_RenderPresent(Game::renderer);
    }

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Game::renderer);
    SDL_Quit();
    std::cout <<"Game Cleared"<<std::endl;
}
