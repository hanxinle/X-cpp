/** @file */
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;
/**
 * @brief random_iterator 提供指针一样的功能，可以指向任意偏移位置
 * @brief vector 的偏移可以为 it+n,list 偏移需要借助 stl 函数 advance(list l)
 */
int main() {
    vector<int> vecNum = {1, 2, 3, 4, 5};
    list<int> listNum = {10, 20, 30, 40, 50};

    vector<int>::iterator vit = vecNum.begin();
    list<int>::iterator lit = listNum.begin();

    cout << "vector_iterator deconference should be same: " << endl;
    cout << " vit[3] : "<< vit[3] << endl;
    cout << "*(vit + 3): " << *(vit + 3) << endl;
    // cout << *(vit + 3) << endl;

    cout << "list_iterator deconference will be 40(the 4the element in list):"
         << endl;
    // won't work for list
    // cout << list[3] << endl;
    // cout << *(list + 3) << endl;

    // use *advance* instead
    std::advance(lit, 3);
    cout << *lit << endl;

    return 0;
}
