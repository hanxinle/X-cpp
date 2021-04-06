/** @file */
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
/**
 * @brief 迭代器辅助函数如下:begin,next,distance
 */
int main() {
    vector<int> numbers{2, 4, 6, 8, 10, 12, 14};
    int arr[]{1, 3, 5, 7, 9, 11, 13};

    for (auto it = begin(numbers); it != end(numbers); ++it) {
        cout << *it << " ";
    }

    cout << endl;

    for (auto it = begin(arr); it != end(arr); ++it) {
        cout << *it << " ";
    }

    cout << endl;

    auto thirdItm = next(next(begin(numbers)));

    cout << "third element of number is: " << *thirdItm << endl;

    cout << "third element of arr is: " << *(next(next(begin(arr)))) << endl;

    cout << "there are " << distance(begin(numbers), end(numbers)) << " numbers"
         << endl;

    cout << "there are " << distance(begin(arr), end(arr)) << " arr items"
         << endl;

    return 0;
}
