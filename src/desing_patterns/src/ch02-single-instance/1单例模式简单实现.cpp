//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//class Singleton {
//private:
//    static Singleton* p_instance;
//    Singleton() {
//        p_instance = nullptr;
//        cout << "调用私有构造函数" << endl;
//    }
//
//public:
//    // C++ 中构造函数不是线程安全的,
//    // getInstance 中 if 语句被打断，将生成多个不同对象
//    static Singleton* getInstance() {
//        if (p_instance == nullptr) {
//            p_instance = new Singleton();
//        }
//        return p_instance;
//    }
//};
//
//Singleton* Singleton::p_instance = nullptr;
//
//int main() {
//    Singleton* p1 = Singleton::getInstance();
//    Singleton* p2 = Singleton::getInstance();
//
//    printf("p1 = %x,p2 = %x", p1, p2); // 结果应相同
//    return 0;
//}
