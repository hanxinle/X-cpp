/** @file */
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(const vector<T>& vec) {
    cout << "used: " << vec.size() << "/" << vec.capacity()
         << " max_size: " << vec.max_size() << endl;

    for (const T& t : vec) {
        cout << t << " ";
    }

    cout << endl;
}

int main() {
    vector<int> numbers;
    vector<string> strings = {"hello,", "han", " xinle.", "How", "are", "you?"};
    /**
     * @brief v.push_back(T t) 添加元素 t 到向量 v 中
     */
    numbers.push_back(100);
    numbers.push_back(200);

    printVector(numbers);
    printVector(strings);

    /**
     * @brief v.size(),v.max_size(),v.resize() 用于处理 vec
     * 大小相关问题,没必要自定义函数
     */
    strings.resize(3);
    printVector(strings);
    cout << endl;

    strings.resize(10, "aaa");
    printVector(strings);
    cout << endl;
    numbers[0] = 1;

    numbers.push_back(2);
    numbers.push_back(3);
    printVector(numbers);
    cout << endl;
    /**
     * @brief iterator,下标,指针都能访问 vector 中元素,首选 iterator
     */
    cout << "Print vector by iterator:" << endl;
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;

    cout << "Print vector by pointer(index):" << endl;
    for (int* p = &numbers[0]; p < (&numbers[0] + numbers.size()); ++p) {
        cout << *p << endl;
    }

    cout << "numbers[0]: " << numbers[0] << endl;

    try {
        cout << numbers.at(100);
    } catch (std::out_of_range& e) {
        cerr << e.what() << endl;
    }

    /**
     * @brief v.front(),v.back() 返回 v 的首尾元素的值
     */
    cout << "front " << numbers.front() << " and back " << numbers.back()
         << endl;
    numbers.clear();

    printVector(numbers);

    return 0;
}
