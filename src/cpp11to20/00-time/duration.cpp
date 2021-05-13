/**
* doc link:https://en.cppreference.com/w/cpp/header/chrono
*
*/
#include<chrono>
#include <iostream>
using namespace std;

int main() {
    chrono::milliseconds ms(3);
    chrono::microseconds us = 2*ms;

    cout << ms.count() << endl;
    cout << us.count() << endl;

    chrono::minutes t1(10);  //                                                                                                        10 min
    chrono::seconds t2(60);  // 60 s
    auto t3 = t1- t2;
    cout << t3.count() << endl;
    cout << typeid(t3).name() << endl;
    cout << t3.count() << endl;

    chrono::seconds t4 = t1 - t2;
    cout << typeid(t4).name() << endl;
    cout << t4.count() << endl;

    return 0;
}
