//#include <iostream>
//using namespace std;
//
////Traits:利用typedef：类型萃取器
//typedef long double LDBL;
//typedef unsigned int UINT32;
//
////类的外部形成数据类型的访问能力
////模板名<模板实参>::类型名 变量名；
//
////template<typename T>
////struct  map
////{
////	typedef T value_type;
////	typedef T& reference;
////	typedef T* pointer;
////};
//////实现：我们内嵌了数据类型=》从模板传入的类型衍生出了其对象相关类型的能力
//////内陷数据类型表
////int main(void) {
////	map<int>::value_type a = 100.9;    // 100
////	cout << "a=" << a << endl;
////	map<double>::value_type b = 100.9; // 100.9
////	cout << "b=" << b << endl;
////	system("pause");
////	return 0;
////}
//
////第二个案例：
////如果一个类模板中，全部的成员都是共有数据类型，
////这个模板就是一个独立的数据类型表，用来规范数据
//
////第一步：我们定义一个规范类模板类型表的基类模板
////第二步：凡是继承了这个类型表的模板，它的访问类型就被确定
//template<typename T, typename U>
//class TypeTb1 {
//public:
//    typedef T value_type1;
//    typedef T& reference1;
//    typedef U value_type2;
//    typedef U& reference2;
//};
//
////我用一个类继承这个数据类型表
//template<typename T, typename U>
//class A :public TypeTb1<T, U> {
//
//};
//int main1 (void) {
//    A<int, double>::value_type1 a = 200;
//    A<int, double>::reference1 b = a;
//    cout << a << endl;
//    cout << b << endl;
//    system ("pause");
//    return 0;
//}
//
////在STL库中，设计人员经常使用这种技巧
////binaray,对二元函数的形参类型进行了约束
///*
//    template<class _A1,class _A2, class _R>
//    struct bianray{
//        typedef _A1 Arg1; //第一个形参类型
//        typedef _A2 Arg2; //第二个形参类型
//        typedef _R  Rtn;  //返回值类型
//    }
//*/
//
//template<class _A1, class _A2, class _R>
//struct binary {
//    typedef _A1 Arg1;
//    typedef _A2 Arg2;
//    typedef _R Rtn;
//};
//
////设计一个继承了上面这个bianray接口的类模板
//template<typename TR, typename T1, typename T2>
//class Add :public binary<TR, T1, T2> {
//public:
//    TR bFunction (const T1& x, const T2& y)const {
//        return x + y;
//    }
//};
//int main (void) {
//    double a = 100.01, b = 20.2;
//    Add<double, double, double> addObj;
//    cout << addObj.bFunction (a, b) << endl;
//    //使用Arg1定义一个变量x
//    typename Add<int, int, double>::Arg1 x = 1000;
//    cout << x << endl;
//    system ("pause");
//    return 0;
//}
//
///*
//因为Add包含了binary的数据类型表，因此，系统中的其他模块就可以
//使用Add::Arg1 Add::Arg2，Add：：Rtn这种方式和Add本身进行对接。
//这种数据类型的抽象：达到了多个系统模块之间的类型统一。
//*/