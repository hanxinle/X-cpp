#pragma once
#include "snake_part.h"
#include <vector>
class Food;

class Snake {
public:
    enum class Direction { UP, DOWN, LEFT, RIGHT };
    Snake(size_t len = 4);

    inline void Clear() {
        for (auto i = 0; i < snake_length_; i++) {
            snake_body_[i].Erase();
        }
    }

    inline void Show() {
        for (auto i = 0; i < snake_length_; i++) {
            snake_body_[i].Show();
        }
        // 考虑是只读遍历，遍历后不能用获取的值调用类成员函数.
        // for (auto const &v : snake_body_) {
        //    Tool::Gotoxy(v.x_, v.y_);
        //    std::cout << '*';
        //}
    }

    void Moving();
    void GrowUp(Food *pfood); // 长大
    bool Died();              // 舌头等于边缘或者等于自身，死亡

public:
    size_t snake_length_;
    std::vector<SnakePart>::iterator snake_head_;
    Direction cur_direction_;
    std::vector<SnakePart> snake_body_;
};
