/** @file */
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
/**
 * @brief 编写参数类型是 iterator 的泛型函数
 * @brief 每隔 1 位打印 vector 中的元素
 * @param begin 待打印左区间
 * @param end 待打印左区间
 * @param out 用于打印元素的输出迭代器
 * @return  out
 */
template <typename InputIt, typename OutputIt>
OutputIt copy_every_other(InputIt begin, InputIt end, OutputIt out) {
    while (begin != end) {
        *out++ = *begin;
        ++begin;
        if (begin == end) break;
        ++begin;
    }
    return out;
}

/**
 * @brief 隔 1 位打印 vector 中元素
 */
int main() {
    vector<double> numbers{1.0, 1.1, 1.2, 1.3, 1.4, 1.5};

    std::copy(std::begin(numbers), std::end(numbers),
              ostream_iterator<double>(std::cout, " "));

    cout << endl;

    copy_every_other(std::begin(numbers), std::end(numbers),
                     // back_insert_iterator<vector<double>>(other));  //OK
                     // cout and back_insert_iterator both OK,
                     // template InputIt,OutputIt powerful
                     ostream_iterator<double>(std::cout, " "));

    cout << endl;
    return 0;
}
