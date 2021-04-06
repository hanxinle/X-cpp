/** @file */
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;
/**
 * @brief 输入数字，返回前 n 项的和
 */
int main() {
    istream_iterator<double> end;
    istream_iterator<double> din(cin);  // Cril+d ends cin

    vector<double> doubles;
    back_insert_iterator<vector<double>> bins(doubles);

    while (din != end) {
        *bins = *din++;  //*bins++ = *din++ also OK
    }

    partial_sum(doubles.begin(), doubles.end(),
                ostream_iterator<double>(cout, " "));

    cout << endl;

    return 0;
}
