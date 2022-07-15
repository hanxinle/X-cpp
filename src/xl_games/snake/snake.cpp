#include "snake.h"
#include "config_and_tools.h"
#include "snake_part.h"
#include <iostream>

Snake::Snake(int x, int y, size_t len, Direction direction, int speed, char ipic) {

    head_x_ = x;
    head_y_ = y;
    speed_ = speed;
    ipic_ = ipic;
    cur_direction_ = direction;
    snake_length_ = len;

    int tx = 0, ty = 0;

    for (size_t i = 0; i < len; i++) {
        // 这里可以根据方向做初始化的优化.
        switch (cur_direction_) {
        case Direction::UP:
            tx = head_x_;
            ty = head_y_ + i;
            break;

        case Direction::DOWN:
            tx = head_x_;
            ty = head_y_ - i;
            break;

        case Direction::LEFT:
            tx = head_x_ + i;
            ty = head_y_;
            break;

        case Direction::RIGHT:
            tx = head_x_ - i;
            ty = head_y_;
            break;
        }
        SnakePart sp(tx, ty, ipic);
        snake_body_.push_back(sp);
    }
}

// void Snake::Show() {
//    for (auto const v : snake_body_) {
//        Tool::Gotoxy(v.x_, v.y_);
//        std::cout << v.sympol_;
//    }
//}

void Snake::ChangeDirection(int drc) {
    switch (drc) {
    case 'w':
        if (cur_direction_ == Direction::LEFT || cur_direction_ == Direction::RIGHT)
            cur_direction_ = Direction::UP;
        break;
    case 's':
        if (cur_direction_ == Direction::LEFT || cur_direction_ == Direction::RIGHT)
            cur_direction_ = Direction::DOWN;
        break;
    case 'a':
        if (cur_direction_ == Direction::UP || cur_direction_ == Direction::DOWN)
            cur_direction_ = Direction::LEFT;
        break;
    case 'd':
        if (cur_direction_ == Direction::UP || cur_direction_ == Direction::DOWN)
            cur_direction_ = Direction::RIGHT;
        break;
    }
}

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
    /********* 蛇的移动原理 ****************
    * 身体坐标从尾部向前覆盖的过程,
    * 
    * 
    * 
    **************************************/
    Clear();
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
    ShowSnake();
    Sleep(speed_);
}

