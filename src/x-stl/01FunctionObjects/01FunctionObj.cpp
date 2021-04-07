#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


//STL=算法+数据结构
class Add {
public:
   Add (int temp) :m_x (temp) {

   }
   int operator()(int a, int b) {
       return a + b + m_x;
   }
private:
   int m_x;
};

// int main (void) {
//    //vector<int> myVec;
//    //sort(myVec.begin(), myVec.end(), greater<int>());
//    //Function Object：函数对象，仿函数

//    //greater<int>()一个对象：调用了（）重载的对象
//    //一个类可以因为重载某一个运算符而改变对象的外观，[]=》数组
//    //重载（）,像一个函数=>我们把重载了（）的类产生的对象，称为仿函数，函数对象

//    Add myAdd (100);

//    // 下面两条语句等价

//    cout << myAdd (1, 2) << endl;
//    cout << myAdd.operator()(1, 2) << endl;
//    Add myAdd2 (200);
//    cout << myAdd2 (1, 2) << endl;
//    //调用了一个函数（）：为什么不用函数指针？
//    //因为当我们使用仿函数的，我们实际上是在调用一个对象
//    //我们可以为这个函数，附加额外的信息，此处是 Add 中的 m_x 变量
//    // 从而可充分利用C++内存对象布局中的代码绑定能力
//    system ("pause");
//    return 0;
// }

void calc (int b) {
   cout << b * 20 << endl;
}
int main (void) {
   //[](int x) {cout << x * 2 << endl;}(10);
   //lambda表达式是C++11一种语法糖
   //让我们便捷创建临时函数
   //calc(10);
   //C++11提供一种语法机制：可以让我们灵活的生成语句块
   auto f = [](int x) {cout << x * 2 << endl; };
   f (10);
   //避免了开发中，我临时处理语句块暴露的风险。
   //==>提高了模块的内聚性
   system ("pause");
   return 0;
}

