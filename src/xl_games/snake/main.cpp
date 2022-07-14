//#include "config_and_tools.h"
#include "snake.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    Snake snake(4);
    //snake.Show();
    for (;;) {
        Sleep(400);
        snake.Moving();
        Sleep(400);
    }
    
    vector<int> v { 1, 2, 3, 4 };
    auto it = v.rbegin();
    it++;
    cout << *it << endl;
    //cout << "X_length = " << XLENGTH << endl;

    //std::cout << "Hello World!\n";
}
