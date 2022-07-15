#pragma once
#include "config_and_tools.hpp"
#include <iostream>
class BaseUnit {
public:
    BaseUnit(int x, int y, char s)
        : x_(x)
        , y_(y)
        , sympol_(s) {}
    ~BaseUnit() {}

    inline void Show() {
        Tool::Gotoxy(x_, y_);
        std::cout << sympol_;
    }

    inline void Erase() {
        Tool::Gotoxy(x_, y_);
        std::cout << " ";
    }

public:
    int x_;
    int y_;
    char sympol_;
};
