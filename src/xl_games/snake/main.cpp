//#include "config_and_tools.h"
#include "snake.h"
#include "food.h"
#include "game.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    //Food * food= new Food(10, 10);
    //cout << food->x_ << " " << food->y_ << endl;

    //Snake snake(10,11);
    //cout << snake.snake_body_[0].x_ << " " << snake.snake_body_[0].y_ << endl;

    //if (snake.EatFood(food))
    //    cout << "eat food" << endl;

    Game game;
    game.Run();
    system("pause");

    //Food food(10, 10);
    //food.CreatePos();
    //food.Show();
    //system("pause");

    // hanxinle-test-in-2022-07-15
  //  Snake snake(60,22,4);
  //  Food food(50,33);
  //  snake.ShowSnake();
  //  int i = 0;
  //   for (;;) {
  //      Sleep(400);
  ///*       if (i % 5 == 0) 
  //            snake.GrowUp();*/
  //      snake.EatFood(&food);
  //      snake.Moving();
  //      snake.ChangeDirection('w');
  //      Sleep(400);
  //      i++;
  //  }
    
    //vector<int> v { 1, 2, 3, 4 };
    //auto it = v.rbegin();
    //it++;
    //cout << *it << endl;
    //cout << "X_length = " << XLENGTH << endl;

    //std::cout << "Hello World!\n";
}
