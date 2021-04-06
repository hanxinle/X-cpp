/** @file */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "circular_buffer.hpp"

using namespace std;

/**
 * @brief 测试 CircularBuffer 
 */
int main() {
    CircularBuffer<int, 5> buffer;

    for (int i = 0; i < 6; i++) {
        buffer.push_back(i);
    }

    cout << endl;
    cout << "After insert 0~5,buffer info: " << buffer << endl;
    cout << endl;

    for (auto it = buffer.begin(); it != buffer.end(); ++it) {
        cout << *it << endl;
    }

    while (!buffer.empty()) {
        cout << "pop()ing: " << buffer.head() << endl;
        buffer.pop();
    }

    return 0;
}
