/** @file */
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
/**
 * @brief numbers{} 中元素先乘以 10，再减去 5
 * @brief bidrectinal_iterator 具有自减操作
 * @brief bidrectinal_iterator 初始化 std::prev(xxx.end())
 * @brief numbers.end() 指向尾元素的下一个位置
 */

int main() {
    vector<int> numbers{1, 2, 3, 4, 5};

    // Note that numbers.end() points to 1 past the end, and
    // that we use ++it because it++ is the same as
    // temp a = it; ++it; return a

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        *it *= 10;
    }

    for (auto it = std::prev(numbers.end()); it >= numbers.begin(); --it) {
        *it -= 5;
    }

    for (int i : numbers) {
        cout << i << endl;
    }

    return 0;
}
