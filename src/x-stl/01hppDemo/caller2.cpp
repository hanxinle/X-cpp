#include <iostream>

template<typename T>
void MyFunc(T const& v) {
	std::cout << "MyFunc Caller2" << std::endl;
}

void caller2() {
	MyFunc(2);//myfunc<int>
	MyFunc(0.2f);//myfunc<float>
}