/** @file */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
/**
 * @brief stringstream（ss） << 则是添加元素到 ss，>> 为读取 ss 元素
 * @brief << 总是尾部添加, >> 调用后像是有个迭代器+1，将从下个元素读取
 */ 
int main() {
    stringstream ss;

    ss << 25 << " " << 50 << " " << 75 << " ";

    cout << ss.str() << "\n";

    int i = 0;
    ss >> i;

    cout << i << "\n";

    ss << 100;

    cout << ss.str() << "\n";

    while (!ss.eof()) {
        ss >> i;
        cout << i << "\n";
    }

    ss.clear();  // Remove the EOF state

    vector<int> v(10);
    iota(begin(v), end(v), 1);

    copy(begin(v), end(v), ostream_iterator<int>(ss, " "));

    cout << ss.str() << "\n";

    cout << "Reading again\n";
    while (!ss.eof()) {
        ss >> i;
        cout << i << "\n";
    }

    return 0;
}
