#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Trace {
public:
    Trace() {
        noisy = 0;
        f = stdout;
    }

    Trace(FILE* ff) {
        noisy = 0;
        f = ff;
    }
    void print(char* s) {
        if (noisy)
            fprintf(f, "%s", s);
        else
            cout << s << endl;
    }

    // 这两个开关功能，若用C语言实现，１代码复杂；２易出错
    void on() { noisy = 1; }
    void off() { noisy = 0; }
private:
    int noisy;
    FILE* f;
};


int main() {
    // 通过开关功能，控制输出手段
    const char* filename = "test.txt";
    FILE* f = fopen(filename, "w");
    Trace t(f);
    char comment[] = "Write to file";
    t.off();
    t.print(comment);
    t.on();
    t.print(comment);
    t.off();

    return 0;
}