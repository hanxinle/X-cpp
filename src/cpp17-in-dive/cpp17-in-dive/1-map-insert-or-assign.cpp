#include <iostream>
#include <map>

// assign-赋值
// 这段程序的含义是：没有插入 "John",26 ,而是给 "John" 重新赋值了
// wasAdded 检测的是是否是插入新数据，1-插入新数据，0-重新赋值
// if 语句的这个写法是 捕获最后一个表达式的值吗？

int main() {
    std::map<std::string, int> mapUsersAge{ { "Alex", 45 }, { "John", 25 } };

    std::map mapCopy{ mapUsersAge };

    if (auto [iter, wasAdded] = mapCopy.insert_or_assign("John", 26); !wasAdded)
        std::cout << iter->first << " reassigned...\n";

    for (const auto& [key, value] : mapCopy)
        std::cout << key << ", " << value << '\n';


    return 0;
}

// C++17 允许if 里面有两个表达式，第二个表达式的值就是 if 语句判定的值 
//using namespace std;
//
//int main() {
//    bool flag = true;
//    bool flag1 = false;
//    if (flag; !flag1)
//        cout << "second flag is false" << endl;
//    return 0;
//}
