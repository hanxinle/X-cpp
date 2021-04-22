#include <iostream>
using namespace std;

class Base {
public:
    virtual Base* copy() const = 0; // {return new xxx(*this);}
    int length() { return length_; }
    int size() { return size_; }
    virtual ~Base() { }
private:
    int length_;
    int size_;
};

class BaseSurrogate {
public:
    BaseSurrogate() :pbase(0) { }
    ~BaseSurrogate() { delete pbase; }
    BaseSurrogate(const Base& other) : pbase(other.copy()) { }
    BaseSurrogate(const BaseSurrogate& other) : pbase(other.pbase ? other.pbase->copy() : 0) { }

    BaseSurrogate& operator = (const BaseSurrogate& other) {
        if (this != &other) {
            delete pbase;
            pbase = (other.pbase ? other.pbase->copy() : 0);
        }

        return *this;
    }
private:
    Base* pbase;
};

class Sub :public Base {
public:
    Sub* copy() const {
        return new Sub(*this);
    }
};


int main() {
    Sub sub;
    BaseSurrogate bs(sub);
    BaseSurrogate bs1(bs);
    BaseSurrogate bs2 = bs1;

    return 0;
}