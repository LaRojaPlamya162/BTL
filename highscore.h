#pragma once
#include <vector>
#include "game.h"
struct highscore
{
    std::string name;
    int diem;
    highscore(std::string _name,int _diem)
    {
        name = _name;
        diem = _diem;
    }
};
class HighscoreManager {
public:
    // Hàm khởi tạo đọc file highscore
    HighscoreManager();

    // Hàm thêm highscore mới
    bool addHighscore(int diem);

private:
};

