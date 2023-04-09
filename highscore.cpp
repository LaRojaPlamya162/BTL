#include <fstream>
#include "highscore.h"
#include "game.h"
using namespace std;
HighscoreManager::HighscoreManager()
{
    ifstream infile("highscore.txt");
    if (!infile)
    {
        cout <<"Initialize error!";
    }
}
bool HighscoreManager::addHighscore(int diem)
{
    int highscore;
    ifstream infile("highscore.txt");
    if(infile)
    {
        infile >> highscore;
        ofstream outfile("highscore.txt");
        if (diem>highscore)
        {
            outfile << diem;
            return true;
        }
        else return false;
    }

}



