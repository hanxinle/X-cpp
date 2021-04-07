#include <iostream>
using namespace std;
//
////写一个函数，完成两个变量的交换:只能交换int，char ，double
//void myswap(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//class Student;
////如果，现在这个变量，是未知类型？
////repeate myself
////如何有效节约开发成本，降低出错概率
//void myswap(double &a, double &b);
//void myswap(char &a, char &b);
//
//

//函数模板和模板函数的辨析
//template<typename T>
//void myswap(T &a, T &b) {
//	T tmp;
//	tmp = a;
//	a = b;
//	b = tmp;
//}
//int main(void) {
//
//	int a = 2, b = 3;
//	cout << "a=" << a << ",b=" << b<<endl;
//	myswap(a, b);//==>myswap<int>
//	cout << "a=" << a << ",b=" << b<<endl;
//
//	double x = 10, y = 8;
//	myswap(x, y);//==>>myswap<double>
//	cout << "x=" << x<<",y=" << y;
//	system("pause");
//	return 0;
//}

template<typename T>
void myswap (T &a, T &b) {
   cout << "template的函数被调用了" << endl;
}

void myswap (char &x, int& y) {
   cout << "普通myswap被调用了" << endl;
}

void myswap (int &a, int &b) {
   cout << "int 普通的myswap函数被调用了" << endl;
}

//类型严格匹配是模板函数调用的先决条件。
//int main2(void) {
//
//	char p = 'a';
//	int data = 23;
//	//myswap<int>(p, data);//函数模板不提供隐式类型转化，因此，必须严格遵循T的类型定义
//	myswap(p, data);
//
//	system("pause");
//	return 0;
//}


//当函数模板和普通函数都符合调用规则的时候，优先使用普通函数
//因为普通函数在编译的期间就生成了函数体
//而模板函数的生成需要在调用的时候，编译器才会编译。
int main (void) {
   int data1 = 1;
   int data2 = 2;
   myswap<> (data1, data2);
   system ("pause");
   return 0;
}