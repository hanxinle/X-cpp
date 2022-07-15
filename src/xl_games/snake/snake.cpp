#include "snake.h"
#include "config_and_tools.hpp"
#include "snake_part.hpp"
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

void Snake::Moving() {
    /********* 蛇的移动原理 ****************
     * 身体坐标从尾部向前覆盖的过程,
     **************************************/
    Clear();
    for (auto i = snake_length_ - 1; i > 0; i--) {
        snake_body_[i].x_ = snake_body_[i - 1].x_; // 此处 i - 1 < 0 ，会引发 vector subscript out of range 的错误.
        snake_body_[i].y_ = snake_body_[i - 1].y_;
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
