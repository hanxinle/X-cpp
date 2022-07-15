#pragma once
#include "food.h"
#include "snake_part.h"
#include <vector>
// class Food;

class Snake {
public:
    enum class Direction { UP, DOWN, LEFT, RIGHT };
    Snake(
        int x = 40, int y = 10, size_t len = 4, Direction direction = Direction::LEFT, int speed = 500, char ipic = '*');

    inline void Clear() {
        for (auto i = 0; i < snake_length_; i++) {
            snake_body_[i].Erase();
        }
    }

    inline void ShowSnake() {
        for (auto i = 0; i < snake_length_; i++) {
            snake_body_[i].Show();
        }
        // 考虑是只读遍历，遍历后不能用获取的值调用类成员函数.
        // for (auto const &v : snake_body_) {
        //    Tool::Gotoxy(v.x_, v.y_);
        //    std::cout << '*';
        //}
    }
    void ChangeDirection(int drc); // in cpp
    void Moving(); // in cpp

    // 参考的是别人的写法
    void GrowUp() {
        SnakePart part(0, 0);
        snake_body_.push_back(part);
        snake_length_++;
    }

    bool EatFood(Food *pfd) {
        if ((snake_body_[0].x_ == pfd->x_) && (snake_body_[0].y_ == pfd->y_)) {
            GrowUp();
            return true;
        } 
        return false;
    }

    bool Died() {
        for (auto it = snake_body_.begin() + 3; it != snake_body_.end(); it++) {
            if (snake_body_[0].x_ == it->x_ && snake_body_[0].y_ == it->y_)
                return true;
        }
        return false;
    } // 蛇头等于边缘或者等于自身，死亡

public:
    size_t snake_length_;
    // std::vector<SnakePart>::iterator snake_head_;
    // snake head x,y
    int head_x_;
    int head_y_;
    int speed_;           // 2000 == 2s
    char ipic_; 
    Direction cur_direction_;
    std::vector<BaseUnit> snake_body_;
};
