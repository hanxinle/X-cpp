#include <iostream>
using namespace std;

// RAII - 资源获取时初始化
// 资源分配和对象声明周期绑定
// 创建对象时分配资源-->构造函数
// 销毁对象时回收资源-->析构函数
// 裸指针：封装为一个类
// operator -> *

template <class T>
class My_ptr {
   private:
    T* ptr;

   public:
    My_ptr(T* p) : ptr(p) { cout << "构造时分配资源" << endl; }
    ~My_ptr() {
        cout << "析构时销毁资源" << endl;
        delete ptr;
    }
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
};

int main() {
    int a = 10;  // 局部变量
    // 异常，local heap ==> new delete
    // 跨 local heap/heap ==> 注意构造和析构的内容
    //{
    //    My_ptr<int> p (&a);
    //    cout << *p << endl;
    //}
    // 没有异常，C++中new 和 delete 管理的是堆
    int* pa = new int(10);
    {
        My_ptr<int> p(pa);
        cout << *p << endl;
    }

    return 0;
}