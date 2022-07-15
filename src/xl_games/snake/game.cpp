#include "game.h"
#include <conio.h>
#include <windows.h>
using namespace std;

const int Game::KLEFT = 5;
const int Game::KUP = 2;
const int Game::KWIDTH = 70;
const int Game::KHEIGHT = 20;

Game::Game() {
    this->score_ = 0;
    this->level_ = 1;

    food_ = new Food();
    snake_ = new Snake();
    DrawGameArea();
    DrawGameInfo();
}

void Game::DrawGameArea() {
    // 与下面的程序执行结果相同.
    // Tool::Gotoxy(KLEFT, KUP);
    // for (auto i = 0; i < KWIDTH; i++) {
    //    cout << "-";
    //}
    Tool::Gotoxy(KLEFT + 1, KUP + 2);
    for (auto i = 0; i < KWIDTH - 2; i++) {
        cout << "-";
    }

    for (auto i = KLEFT; i < KLEFT + KWIDTH; i++) {
        Tool::Gotoxy(i, KUP);
        cout << "-";
    }

    for (auto i = KUP; i < KUP + KHEIGHT; i++) {
        Tool::Gotoxy(KLEFT, i);
        cout << "|";
        Tool::Gotoxy(KLEFT + KWIDTH - 1, i);
        cout << "|";
    }
    Tool::Gotoxy(KLEFT, KUP + KHEIGHT);
    for (auto i = 0; i < KWIDTH; i++) {
        cout << "-";
    }
}

void Game::DrawGameInfo() {
    Tool::Gotoxy(KLEFT + 1, KUP + 1);
    cout << "CopyRight @ XL and score = " << score_ << endl;
}

void Game::Run() {
    food_->CreatePos(&(snake_->snake_body_));
    food_->Show();
    snake_->ShowSnake();

    int key = 'w';
    while (!CheckFailed()) {
        if (_kbhit()) {
            key = _getch();
            snake_->ChangeDirection(key);
        } else {

            snake_->Moving();

            if (snake_->EatFood(food_)) {
                Tool::Gotoxy(30, 30);
                cout << "eat food" << endl;
                score_++;
                /*         snake_->Clear();
                         snake_->ShowSnake();*/
                DrawGameInfo();
                food_->CreatePos(&(snake_->snake_body_));
                food_->Show();
            }
        }
    }
}

bool Game::CheckFailed() {
    // left
    if (snake_->snake_body_[0].x_ < KLEFT)
        return true;
    // right
    if (snake_->snake_body_[0].x_ > KLEFT + KWIDTH)
        return true;
    // up
    if (snake_->snake_body_[0].y_ < KUP) // 注意信息扎用
        return true;
    // down
    if (snake_->snake_body_[0].y_ > KUP + KHEIGHT)
        return true;
    // eat itself
    if (snake_->Died())
        return true;
    return false;
}
