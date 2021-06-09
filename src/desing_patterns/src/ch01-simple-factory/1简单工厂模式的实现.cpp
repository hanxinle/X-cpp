#include <iostream>
#include <string>

///#include "DynOBJ.h"
using namespace std;

class Api {
public:
    virtual void test(string s) = 0;

protected:
    Api() { }
};

class ImpleOne : public Api {
public:
    void test(string s) { cout << "现在是One在执行" << s << endl; }
};

class ImpleTwo : public Api {
public:
    void test(string s) { cout << "现在是Two在执行" << s << endl; }
};

class Factory {
public:
    static Api* createApi(int type) {
        Api* pApi = nullptr;
        if (type == 1) {
            pApi = new ImpleOne();
        }
        if (type == 2) {
            pApi = new ImpleTwo();
        }
        return pApi;
    }

    static Api* createApi() { return new ImpleOne(); }
};

/**
 * 传入参数1，可以实现从 数据库 读入的功能
 * 传入参数2，可以实现从 文本文件 读入的功能
 * 实现了客户端调用和 implOne，implTwo 的解耦合
 * class Factory 实现了变化隔离
 */

int main(void) {
    Api* pApi = Factory::createApi(2);

    pApi->test("现在是使用简单工厂方法重构");
    Api* pApiEx = Factory::createApi();
    system("pause");

    return 0;
}
