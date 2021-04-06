/** @file */
#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> list1{10, 20, 25, 30, 40, 50};
    list<int> other{15, 25, 35, 45, 50, 55};
    /**
     * @brief list1.merge(list2) 将 list2 合并到 list1
     */
    list1.merge(other);

    cout << "list size = " << list1.size() << endl;
    /**
     * @brief list.begin(),list.end() 获取 list 首尾迭代器并访问元素值
     */
    for (auto i = list1.begin(); i != list1.end(); i++) {
        cout << *i << "  ";
    }

    list1.unique();
    for (auto i = list1.begin(); i != list1.end(); i++) {
        cout << *i << "  ";
    }

    cout << endl;

    return 0;
}
