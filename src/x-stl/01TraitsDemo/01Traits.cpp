#include <iostream>
using namespace std;
//特化数据类型表
//class Test1 {
//public:
//    char compute (int x, double y) {
//        return x;
//    }
//};
//
//class Test2 {
//public:
//    double compute (double x, double y) {
//        return x;
//    }
//};
//// 都只有一个compute函数，而且这两个函数的逻辑完全相同
//// 不同的仅仅是函数参数类型
//// 下面会重新设计class Test
////template<typename Arg1, typename Arg2, typename Ret>
////class Test {
////public:
////    Ret compute (Arg1 x, Arg2 y) {
////        return x;
////    }
////};//==>没有很好的复用已经设计好的函数
///*
//    fun(){}
//    go(){
//        fun();
//    }
//    在Test的设计中，它侵入了test1，和test2的设计。
//*/
//
//class Test1;
//class Test2;
////两个类模板规范一个统一的接口
//template <typename T>
//class TypeTb1 {
//
//};
//
////特化模板
//template<>
//class TypeTb1<Test1> {
//public:
//    typedef char ret_type;
//    typedef int par1_type;
//    typedef double par2_type;
//};
//
//template<>
//class TypeTb1<Test2> {
//public:
//    typedef double ret_type;
//    typedef double par1_type;
//    typedef int par2_type;
//};
//
////Test1和Test2的模板
//template<class T>
//class Test {
//public:
//    typename TypeTb1<T>::ret_type compute (
//        typename TypeTb1<T>::par1_type x,
//        typename TypeTb1<T>::par2_type y
//    ) {
//        return  x;
//    }
//};
//int main (void) {
//    Test<Test1> t1;
//    cout << t1.compute (65, 6.18) << endl;
//    system ("pause");
//    return 0;
//}

//Traits：类型萃取
//泛型=》约定代码中的复杂数据类型的基本特征
//Student,Teacher:pStu,pTeacher
//void *pTemp= pStu,pTemp=pTeacher
//类型不安全的问题：指针天生的不具备向外提供数据类型的能力
//指针不是类，他就是一个变量，约束类型
//对指针进行模板特化，这样
//衍生出符合接口定义的统一类型型别的别名
template<typename T>
class Iterator_1 {
public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
};

template <typename T>
class Iterator_2 {
public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
};

template<typename T>
struct Traits {

};

template<typename T>
struct Traits<T *> {
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
};

class A {
public:
    void show () {
        cout << "A::show()" << endl;
    }
};

class B;

int main (void) {
    Iterator_1<int>::value_type t1 = 100;
    cout << t1 << endl;
    Iterator_2<double>::value_type t2 = 6.18;
    cout << t2 << endl;
    Traits<double*>::value_type t3 = 4.44;
    cout << t3 << endl;

    // 我们通过Traits的数据类型信息，
    // 可以有效的规范出，类型性别统一，从而避免了类型转化问题。
    // 泛型的基石：
    Iterator_1<A>::pointer iter = new A;
    iter->show ();

    system ("pause");
    return 0;
}