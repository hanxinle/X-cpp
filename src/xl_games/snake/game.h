#pragma once
#include "food.hpp"
#include "snake.h"
#include <memory>
class Game {
public:
    Game();
    virtual ~Game() {}

    // 绘制游戏区域.
    void DrawGameArea();
    void DrawGameInfo();

    void Run();
    bool CheckFailed();

public:
    // 用于绘制游戏区域和信息区域.
    static const int KLEFT;
    static const int KUP;
    static const int KWIDTH;
    static const int KHEIGHT;

private:
    unsigned int score_;
    unsigned int level_;
    Snake *snake_;
    Food *food_;
};
