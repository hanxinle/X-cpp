#include "handle.h"
#include <iostream>
using namespace std;

int main() {
    Handle h(1, 2);
    Handle h1 = h;
    Handle h2(h1);
    cout << h2.x() << endl;
    cout << h2.y() << endl;

    h2.SetX(12);
    h2.SetY(12);
    cout << h2.x() << endl;
    cout << h2.y() << endl;
    return 0;
}