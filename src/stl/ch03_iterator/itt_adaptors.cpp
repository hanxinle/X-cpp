/** @file */
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

using namespace std;
/**
 * @brief 迭代器适配器(itt_adaptors)接收迭代器，并且改变迭代器的行为
 * @brief reverse_iterator 逆向遍历容器
 * @brief insert_iterator 在指定位置插入元素
 * @brief move_iterator 示例程序不好，并没有说明什么，再找资料吧，教程上说
 * @brief 接收任意类型的input iterator反引用使其产生右值引用(如同
 * @brief std::move 的使用)，暂且当作参考
 */
int main() {
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reverse_iterator<vector<int>::iterator> begin(numbers.end());
    reverse_iterator<vector<int>::iterator> end(numbers.begin());

    while (begin != end) {
        cout << *begin++ << endl;
    }

    cout << endl;
    // 在第四个元素处开始插入 10，20，30，40，50
    vector<int>::iterator it = numbers.begin();
    std::advance(it, 3);

    insert_iterator<vector<int>> inserter(numbers, it);

    for (int i = 1; i <= 5; ++i) {
        *inserter = (i * 10);
    }

    cout << "numbers: ";
    for (auto i : numbers) {
        cout << i << " ";
    }

    cout << endl;
    // back_insert_iterator 不能被 copy，但是可以 moved.
    vector<unique_ptr<int>> pointers;
    vector<unique_ptr<int>> others;

    using iter_t = vector<unique_ptr<int>>::iterator;

    for (int i = 0; i < 10; ++i) {
        int *tmp = new int;
        *tmp = i;
        pointers.push_back(unique_ptr<int>(tmp));
    }

    cout << "pointers size: " << pointers.size()
         << " others size: " << others.size() << endl;

    back_insert_iterator<vector<unique_ptr<int>>> binsert(others);

    copy(move_iterator<iter_t>(pointers.begin()),
         move_iterator<iter_t>(pointers.end()), binsert);

    pointers.clear();  // undefined after move

    cout << "pointers size: " << pointers.size()
         << " others size: " << others.size() << endl;

    return 0;
}
