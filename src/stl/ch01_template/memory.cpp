/** @file */
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Widget {
   public:
    Widget(string s) : str(s) {
        cout << "Constructing Widget" << endl;
        cout << "str == " << str << endl;
    }

    virtual ~Widget() {
        cout << "Destroying Widget" << endl;
        cout << "str == " << str << endl;
    }

   private:
    string str;
};

/**
 * @brief unique_ptr 自动管理资源，不需要手动回收
 */

int main() {
    Widget* w = new Widget("new");
    unique_ptr<Widget> uw = make_unique<Widget>("unique_ptr");
    // 没有delete，内存不会释放
    // delete w;
    return 0;
}
