#include <iostream>
using namespace std;


int main () {


   /*****************
   右值是一个和运算过程匹配的临时对象，
   无法从语法层面访问，
   左值是一个有名字的，有固定地址的表达式，
   右值是匿名的，没有固定地址的对象
   *****************/

   int a = 10;
   int &b = a;   // 为左值a取一个常量别名b

   //int a + b = 20;
   int x = 100, y = 10;
   int && r = x+y;
   //为右值 x+y 命名一个右值引用 r，使得右值变成了和左值完全相同的临时对象
   r++;
   cout << "r-value r = " << r << endl;
   system ("pause");
   return 0;
}