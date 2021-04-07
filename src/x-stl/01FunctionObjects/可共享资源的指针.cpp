#include <iostream>
using namespace std;

// 关键词：shared_ptr
// 多个指针指向同一个资源，只要还有指针使用同一个资源，
// 就不能释放该资源
// 通过引用计数标记是否有指针指向资源

template <typename T> class SharedPtr;
template <typename T>
class Res_Ptr {
private:
    T * res;
    int use_count;
public:
    Res_Ptr (T * p) :res (p), use_count (1) {
        cout << "构造函数" << endl;
    }

    ~Res_Ptr () {
        delete res;
        cout << "析构函数" << endl;
    }

    friend class SharedPtr<T>;
};

template <typename T>
class SharedPtr {
public:
    SharedPtr (T* p, T i) :ptr (new Res_Ptr<T> (p)), val (i) {
        cout << "SharedPtr 构造函数" << "use_count = " << ptr->use_count << endl;
    }

    SharedPtr (const SharedPtr& orig) :ptr (orig.ptr), val (orig.val) {
        ++ptr->use_count;
        cout << "SharedPtr 的拷贝构造函数" << "use_count = "
            << ptr->use_count << endl;
    }

    ~SharedPtr () {
        if (--ptr->use_count == 0)
            delete ptr->res;
        cout << "SharedPtr 析构函数" << endl;
        cout << "use_count = " << ptr->use_count << endl;
    }
private:
    Res_Ptr<T> * ptr;
    T val;

};
int main () {
    {
        SharedPtr<int> hpA = SharedPtr<int> (new int (42), 100);
        SharedPtr<int> hpB (hpA);
        SharedPtr<int> hpC (hpB);
        SharedPtr<int> hpD = hpA;
    }
    cout << "内层括号结束" << endl;

    return 0;
}