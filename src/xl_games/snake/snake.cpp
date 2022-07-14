#include "snake.h"
#include "config_and_tools.h"
#include "snake_part.h"
#include <iostream>

Snake::Snake(size_t len) {
    for (size_t i = 0; i < len; i++) {
        auto x = 40 + i;
        auto y = 12;
        auto syp = '*';
        SnakePart sp(x, y, syp);
        snake_body_.push_back(sp);
    }

    snake_head_ = snake_body_.begin();
    cur_direction_ = Direction::UP;
    snake_length_ = len;
}

//void Snake::Show() {
//    for (auto const v : snake_body_) {
//        Tool::Gotoxy(v.x_, v.y_);
//        std::cout << v.sympol_;
//    }
//}
 
// 先假设每个小模块没有 show 模块
void Snake::Moving() {
    // switch (cur_direction_) {
    // case Direction::UP:
    //    (*snake_head_).y_--;
    //    break;
    // case Direction::DOWN:
    //    (*snake_head_).y_++;
    //    break;
    // case Direction::LEFT:
    //    (*snake_head_).x_--;
    //    break;
    // case Direction::RIGHT:
    //    (*snake_head_).x_++;
    //    break;
    // default:
    //    break;
    //}
    // 可以移动，但是有 bug,换一种实现
    // auto it = snake_body_.rbegin();
    // for (; it != snake_body_.rend(); it++) {
    //    if (it != snake_body_.rbegin()) {
    //        (*it).x_ = (*(it + 1)).x_;
    //        (*it).y_ = (*(it + 1)).y_;
    //        Tool::Gotoxy((*it).x_, (*it).y_);
    //        std::cout << '*';
    //    } else {
    //        Tool::Gotoxy((*it).x_, (*it).y_);
    //        std::cout << ' ';
    //    }
    //}
    //

    // switch (cur_direction_) {
    // case Direction::UP:
    //    snake_body_[0].y_--;
    //    break;
    // case Direction::DOWN:
    //    snake_body_[0].y_++;
    //    break;
    // case Direction::LEFT:
    //    snake_body_[0].x_--;
    //    break;
    // case Direction::RIGHT:
    //    snake_body_[0].x_++;
    //    break;
    // default:
    //    break;
    //}
    Clear();
    // 要对整条蛇身进行刷新，每次重新绘制，省去管理的逻辑!!!!
    //for (auto i = 0; i < snake_length_; i++) {
    //    snake_body_[i].Erase();
    //}

    for (auto i = snake_length_ - 1; i > 0; i--) {
        // if (i == snake_body_.size() - 1) {
        //    Tool::Gotoxy(snake_body_[i].x_, snake_body_[i].y_);
        //    std::cout << ' ';
        //} else {
        snake_body_[i].x_ = snake_body_[i - 1].x_; // 此处 i - 1 < 0 ，会引发 vector subscript out of range 的错误.
        snake_body_[i].y_ = snake_body_[i - 1].y_;
        //}
    }
    // switch 语句放到后面，程序的逻辑才是正常的.
    switch (cur_direction_) {
    case Direction::UP:
        snake_body_[0].y_--;
        break;
    case Direction::DOWN:
        snake_body_[0].y_++;
        break;
    case Direction::LEFT:
        snake_body_[0].x_--;
        break;
    case Direction::RIGHT:
        snake_body_[0].x_++;
        break;
    default:
        break;
    }
    Show();

}

void Snake::GrowUp(Food *pfood) {}

bool Snake::Died() {
    return false;
}
