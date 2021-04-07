#include <iostream>

template<typename T>
void MyFunc(T const& v) {
	std::cout << "MyFunc Caller1" << std::endl;
}

void caller1() {
	MyFunc(1);//myfunc<int>
	MyFunc(0.1);//myfunc<double>
}