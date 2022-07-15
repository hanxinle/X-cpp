#pragma once
#include "base_unit.h"

class SnakePart : public BaseUnit {
public:
    SnakePart(int x, int y, char c = '*')
        : BaseUnit(x, y, c) {}

    virtual ~SnakePart() {}
};
