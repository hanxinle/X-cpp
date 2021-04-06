/** @file */
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
/**
 * @brief forward_iterator 特性：fit 没有自增操作，永远指向首元素
 */ 
int main() {
    vector<int> backInsertionVector = {1, 2, 3};
    vector<int> forwardVector = {1, 2, 3};

    back_insert_iterator<vector<int>> bins(backInsertionVector);
    vector<int>::iterator fit = forwardVector.begin();

    *bins = 20;               //insert_on_tail 20,30
    *bins = 30;
    bins++;

    *fit = 20;                //*begin -> 20 -> 30
    *fit = 30;
    fit++;

    cout << "backInsertItt : ";
    for (int i : backInsertionVector) {
        cout << i << " ";
    }

    cout << "\n";

    cout << "forwardItt: ";
    for (int i : forwardVector) {
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}
