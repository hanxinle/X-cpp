#include <iostream>
#include <string>
using namespace std;

//template <typename T>
//class Base {
//public:
//    Base (T x) {
//        this->x = x;
//    }
//    virtual void print () = 0;
//    // private error
//protected:
//    T x;
//};
//
//template <typename T>
//class SubClass :public Base<T> {
//public:
//    SubClass (T x, T y) :Base (x), y (y) { }
//    void print () {
//        cout << "x = " << x << " y = " << y << endl;
//    }
//private:
//    T y;
//};
//
//int main () {
//    Base<int> *  p = new SubClass<int> (12, 3);
//    p->print ();
//    return 0;
//}

// 模板类可以继承普通类，
// 是C++灵活性的一种体现
//class Base {
//public:
//    int x;
//    Base (int x) {
//        this->x = x;
//    }
//    virtual void print () = 0;
//};
//
//
//template <typename T>
//class Sub1 :public Base {
//public:
//    T y;
//    Sub1 (T y, int x) :Base (x), y (y) { }
//    void print () {
//        cout << "x = " << x << " y = " << y <<  endl;
//    }
//};
//
//class Sub2 :public Sub1<string> {
//public:
//    double z;
//    Sub2 (double z, string y, int x) :Sub1 (y, x), z (z) { }
//    void print () {
//        cout <<"x = " << x << " y = " << y
//            << " z = " << z << endl;
//    }
//};
//
//int main () {
//    double v = 3.2;
//    string str = "han";
//    Sub2 s2 (v, str, 9);
//    s2.print ();
//
//    Sub1<double> s1 (1.2, 1);
//    s1.print ();
//
//
//    return 0;
//}



// 模板类类中是可以嵌套定义模板类的
template <typename T>
class Base {
public:
   T x;

   class Sub1 {
   public:
       string y;
   }sub1;

   template <typename V>
   class Sub2 {
   public:
       V z;
   };
   //Sub1 s1;
   Sub2<double> s2;
   Sub2<int> s3;
};

int main () {
   Base<int> base;
   // base.s1.y = "hello";
   base.s2.z = 3.14;
   base.s3.z = 10;
   cout <<  base.s2.z << " " << base.s3.z << endl;
   // cout << base.s1.y << " " << base.s2.z
   //    << " " << base.s3.z << endl;
   return 0;
}