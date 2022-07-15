#pragma once
#include "base_unit.h"
#include <vector>
class Food : public BaseUnit {
public:
    Food(int x=0, int y=0, char c = '$')
        : BaseUnit(x, y, c) {}

    virtual ~Food() {}

    // 在他人的提示下，自己想到了这个函数的初步实现.
    void CreatePos(std::vector<BaseUnit> *vec) {
        while (true) {
            srand(time(NULL));
            int x = rand() % XLENGTH;
            int y = rand() % YLENGTH;
            size_t i = 0;
            for (; i < vec->size(); i++) {
                if (x == vec->at(i).x_ && y == vec->at(i).y_) {
                    break;
                }
            }
            if (i == vec->size()) {
                x_ = x;
                y_ = y;
                return;
            }
        }

    }
};
