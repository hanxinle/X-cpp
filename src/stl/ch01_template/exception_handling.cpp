/** @file */
#include <exception>
#include <iostream>

class ResourceException : public std::exception {
    std::string w;

   public:
    ResourceException(const std::string& w) : w(w) {}
    const char* what() const noexcept { return w.c_str(); }
};

class SomethingImport {
   public:
    SomethingImport() {
        throw ResourceException("Unable to open some resource i need");
        //  throw 10;
        // throw "hello world.";
    }
};

using namespace std;

int main() {
    /**
     * @brief 用不同的变量类型描述同一个异常
     */
    try {
        SomethingImport si;
    } catch (std::exception& except) {
        cout << except.what() << endl;
        return 1;
    } catch (int i) {
        cout << "exception is i: " << i << endl;
        return 2;
    } catch (...) {
        cout << "catch all" << endl;
        return 3;
    }

    return 0;
}
