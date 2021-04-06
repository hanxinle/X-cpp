/** @file */
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <vector>

using namespace std;
/**
 * @brief iterator_traits 提供了类型特性接口，使得算法可以仅依赖迭代器实现
 * @brief iterator_traits 定义了
 * value_type，pointer，reference，difference_type，iterator_category
 */
int main() {
    vector<string> vec = {"1", "2", "3"};

    using traits = iterator_traits<vector<string>::iterator>;

    cout << std::boolalpha;

    cout << "value_type == string: "
         << (typeid(traits::value_type) == typeid(string)) << endl;

    cout << "pointer == string* : "
         << (typeid(traits::pointer) == typeid(string*)) << "\n";
    cout << "reference == string& : "
         << (typeid(traits::reference) == typeid(string&)) << "\n";
    // result of subtracting of two pointers
    cout << "difference_type == std::ptrdiff_t : "
         << (typeid(traits::difference_type) == typeid(std::ptrdiff_t)) << "\n";

    cout << "iterator_category == std::random_access_iterator_tag : "
         << (typeid(traits::iterator_category) ==
             typeid(std::random_access_iterator_tag))
         << "\n";

    return 0;
}
