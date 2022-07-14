#pragma once
#include "base_unit.h"
class Food : public BaseUnit {
public:
    Food(int x, int y, char c):BaseUnit(x,y,c) {}

    virtual ~Food() {}

    // void CreateFood();
};
