/** @file */
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
/**
 * @brief 输出格式化，其操作不如 printf 直观
 * @brief 但是 cout 可以与货币、时区关联
 */
int main() {
    int byte = 0xA9;
    cout << byte << "\n";
    cout << std::dec << byte << "\n";
    cout << std::oct << byte << "\n";
    cout << std::hex << byte << "\n";
    cout << std::showbase << std::hex << byte << "\n";

    string name = "James Slocum";
    cout << setfill('*');
    cout << name << "\n";
    cout << setw(40) << name << "\n";
    cout << setw(40) << std::left << name << "\n";
    cout << setw(40) << std::right << name << "\n";

    long double d = 4 * atan(1);
    cout << d << "\n";
    cout << std::setprecision(20) << d << "\n";
    cout << std::setprecision(3) << d << "\n";
    cout << std::scientific << d << "\n";

    long double cash = 12345;
    cout.imbue(std::locale(""));  // Show hows this change change ja_JP
    cout << put_money(cash) << "\n";
    cout << put_money(cash, true) << "\n";

    return 0;
}
