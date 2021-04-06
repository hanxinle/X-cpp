/** @file */
#include <iostream>
using namespace std;

template <typename T>
class Container {
   public:
    explicit Container(T t) : t(t) {}

    friend std::ostream& operator<<(std::ostream& os, const Container<T>& c) {
        return (os << "private T t == " << c.t);
    }

   private:
    T t;
};

template <typename T>
bool isGreator(T t1, T t2) {
    return t1 > t2;
}
/**
 * @brief 友元输出重载，lamba 模板使用
 */
int main() {
    Container<int> c_i_obj(100);
    Container<string> c_str_obj("ssss");

    cout << c_i_obj << endl;
    cout << c_str_obj << endl;

    cout << "Test template functions isGreator(template func & lambda func)"
         << endl;

    cout << isGreator(110, 22) << endl;       // 1
    cout << isGreator(12.3, 12.2) << endl;    // 1
    cout << isGreator("AAA", "ZZZ") << endl;  // 1
    cout << isGreator('z', 'a') << endl;      // 1

    // template lambda feature not supported in visual studio 2017
    auto f = []<typename T>(T t1, T t2) { return t1 > t2; };
    cout << "lambda function isGreator(T t1, T t2)" << endl;
    cout << f(110, 22) << endl;       // 1
    cout << f(12.3, 12.2) << endl;    // 1
    cout << f("AAA", "ZZZ") << endl;  // 1
    cout << f('z', 'a') << endl;      // 1

    return 0;
}

// build by - g++ xxx.cpp -o xxx -Wall -Wextra --std=c++17
