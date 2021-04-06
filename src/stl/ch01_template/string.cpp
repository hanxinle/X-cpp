/** @file */
#include <iostream>
#include <string>

using namespace std;
/**
 * @brief string 常用接口
 */
int main() {
    string name = "han xinle";
    string n2("han xinle");
    string n3(name);

    string n4{'h', 'a', 'n'};
    string last(name, 4, 5);
    string line(20, '-');
    string reverse(name.rbegin(), name.rend());

    cout << name << endl;
    cout << n2 << endl;
    cout << n3 << endl;
    cout << n4 << endl;
    cout << last << endl;
    cout << reverse << endl;

    // find string.
    // std::size_t pos = name.find(n4);
    auto pos = name.find(n4);
    if (pos != std::string::npos) {
        cout << "Found first name at: " << pos << endl;
    }

    cout << "Comma at: " << ("hello,How are you?"s).find(",") << endl;

    cout << line << endl;
    // append to string
    string about = "is a programmer";
    name.push_back(' ');
    for (char c : about) {
        name.push_back(c);
    }

    cout << name << endl;

    // insert into string

    name.insert(0, "I have heard that ");
    cout << name << endl;

    // replace some string

    pos = name.find("programmer");
    name.replace(pos, ("programmer"s).length(), "snowboarder");

    cout << name << endl;

    pos = name.find("heard");
    name.erase(pos, ("heard"s).length());
    name.insert(pos, "read somewhere");

    cout << name << endl;

    return 0;
}
