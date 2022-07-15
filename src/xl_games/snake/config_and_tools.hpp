#ifndef TOOL
#define TOOL

#include <windows.h>

const unsigned int XLENGTH = 80;
const unsigned int YLENGTH = 25;
// 为什么将函数定义放到类中就不会提示链接错误呢?
class Tool {
public:
    static void Gotoxy(int x, int y) {
        COORD coor;
        coor.X = x;
        coor.Y = y;

        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(handle, coor);
    }
};

#endif
