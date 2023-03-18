#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
//#include "Map.h"
GameObject* player;
//SDL_Texture* texture;
//GameObject* enemy;
TextureManager* border;
TextureManager* background;
SDL_Renderer* Game::renderer = nullptr;

//Map* map;
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
        player = new GameObject("car.png",WINDOW_WIDTH*2/5,560,WINDOW_WIDTH/5,240);
        background = new TextureManager();
        //enemy = new GameObject("foo.png",50,50);
        border = new TextureManager();
        //map = new Map();
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
    /*cnt++;
    destR.h = 64;
    destR.w = 64;
    destR.x = cnt;
    std::cout<<cnt<<std::endl;*/
    //SDL_RenderCopy(Game::renderer,gTexture,
    player -> Update();
    background->LoadBackground("road.png");
    //enemy -> Update();

}
void Game::render()
{
    //SDL_RenderCopy(renderer,playerTex,NULL,NULL);
    //map ->DrawMap();
    //SDL_RenderClear(Game::renderer);
    SDL_RenderClear(Game::renderer);
    background->LoadBackground("road.png");
    border ->Draw(WINDOW_HEIGHT,WINDOW_WIDTH);
    //background->LoadBackground("road.png");
    player -> Render();
    //enemy -> Render();
    /*int ROW_NUMS = WINDOW_HEIGHT / CELL_SIZE;
    int COL_NUMS = WINDOW_WIDTH / CELL_SIZE;
    for (int i=1;i<=ROW_NUMS;i++)
    {
        for (int j=1;j<=COL_NUMS;j++)
        {
            int x=i*CELL_SIZE;
            int y=j*CELL_SIZE;
            SDL_RenderDrawPoint(renderer,x,y);
            SDL_RenderPresent(renderer);
        }
    }*/

}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Game::renderer);
    SDL_Quit();
    std::cout <<"Game Cleared"<<std::endl;
}
