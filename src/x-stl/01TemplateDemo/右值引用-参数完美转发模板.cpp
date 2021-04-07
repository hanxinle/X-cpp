#include <iostream>
using namespace std;

// 模板参数类型推导
// move：
// T&& move(T & val)
// 接收一个参数 val，然后返回这个餐宿的右值引用
// 左值：T＆
// 右值：T
// forward ==>   T& ==> T&& 

void Myfunc (int &v) {
    cout << "左值" << endl;
}

void Myfunc (int &&v) {
    cout << "右值" << endl;
}

void Myfunc (const int &v) {
    cout << "常左值" << endl;
}

void Myfunc (const int &&v) {
    cout << "常右值" << endl;
}

// 完美地参数转发
// STL中make_pair,make_unique 大量使用
// 解决了临时对象效率问题

template <typename T>
void Tmp (T && a) {
    Myfunc (std::forward<T> (a));
}

int main () {
    int a;
    const int b = 3;
    Tmp (10);        // 右
    Tmp (a);         // 左
    Tmp (move (a));  // 右
    Tmp (b);         // 常左
    Tmp (move (b));  // 常右

    return 0;
}