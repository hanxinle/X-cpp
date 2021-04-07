#include <iostream>
using namespace std;


class Foo {
public:
   Foo (int x) {
       p = new int (x);
   }

   ~Foo () {
       if (p != nullptr) {
           delete p;
       }
   }
   // 如果一个对象是临时对象，使用浅拷贝的意义是：
   // 当需要“转移语义”的拷贝构造函数时，浅拷贝的效率意义就凸显了
   Foo (const Foo & r) {
       // 浅拷贝，共享机制
       //this->p = r.p;
       this->p = new int;
       *this->p = *(r.p);
   }

   // 右值引用拷贝构造函数
   Foo (Foo && r) {
       cout << "Foo(Foo&&)" << endl;
       // step1：指向同一空间
       // step2: 原对象放弃了资源所有权
       p = r.p;
       r.p = nullptr;
   }

   void Showp () {
       cout << p << " " << *p  << endl;
   }
private:
   int * p;
};

Foo func () {
   Foo foo (100);
   return foo;
}
int main () {
   // 浅拷贝示例
   //Foo f1 (10);
   //Foo f2 (f1);
   //f1.Showp ();
   //f2.Showp ();

   // 深拷贝
   // 资源所有权发生转移，资源位置没有发生改变
   // 而所属对象发生了变化
   Foo f (func ());
   f.Showp ();

   return 0;
}


