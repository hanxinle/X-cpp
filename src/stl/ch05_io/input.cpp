/** @file */
#include <exception>
#include <iostream>

using namespace std;
/**
 * @brief 接收用户输入的 int、double、string,其它函数 cin.fail(),cin.clear()
 */
int main() {
    int x = 0;
    double d = 0;
    string name = "";

    cout << "Please enter an integer: ";
    cin >> x;

    cout << "Please enter a double: ";
    cin >> d;

    cout << "Please enter your name: ";
    cin >> name;

    cout << "I expect a number, so enter a string: ";
    cin >> x;

    if (cin.fail()) {
        cin.clear();
        cerr << "There was an error reading a number from the user\n";
        string s;
        cin >> s;
        cout << "Read string: " << s << " from user\n";
    } else {
        cout << "Read in value: " << x << " from the user\n";
    }

    return 0;
}
