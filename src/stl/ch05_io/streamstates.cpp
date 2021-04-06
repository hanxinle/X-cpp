/** @file */
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @brief echo "This is some text" > input.txt 创建 input.txt
 * @brief 不创建 input.txt，程序会在一开始提示个错误，不能查看接下来内容
 */
int main() {
    ifstream fs("input.txt");

    if (fs) {
        cout << "ifstream is in a good state\n";
        // keep reading while state is good
        int count = 0;
        while (fs.good()) {
            string line;
            fs >> line;
            if (line.size() > 0) {
                ++count;
            }
        }
        cout << "Read " << count << " words\n";
    }

    if (fs.bad()) {
        cout << "ifstream is in a bad state\n";
    }

    if (fs.fail()) {
        cout << "ifstream is in a fail state\n";
    }

    if (fs.eof()) {
        cout << "ifstream is in an EOF state\n";
    }

    cout << std::showbase << std::hex << (int)fs.rdstate() << "\n";

    fs.setstate(ios::eofbit);

    cout << std::showbase << std::hex << (int)fs.rdstate() << "\n";
    return 0;
}
