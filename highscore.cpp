#include <fstream>
#include "highscore.h"
#include "game.h"
#include "GameObject.h"
using namespace std;
SDL_Color CoLor = {255,255,255};
HighscoreManager::HighscoreManager()
{
    ifstream infile("highscore.txt");
    if (!infile)
    {
        cout <<"Initialize error!";
    }
}
int HighscoreManager::addHighscore(int diem)
{
    ifstream infile("highscore.txt");
    if(infile)
    {
        infile >> highscore;
        ofstream outfile("highscore.txt");
            if (diem>highscore)
            {
                outfile << diem;
            }
            else
            {
                outfile << highscore;
            }
    }
    return highscore;
}




