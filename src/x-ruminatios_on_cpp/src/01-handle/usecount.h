#pragma once
// 把引用计数抽象出来

class UseCount {
public:
    UseCount() { count = new int(1); }
    UseCount(const UseCount& other) : count(other.count) { ++* count; }
    ~UseCount() {
        if (--*count == 0) {
            delete count;
        }
    }
    bool IsOnly() { return *count==1; }
    UseCount& operator= (const UseCount& other) {
        ++(*other.count);
        if (--(*count)==0) {
            delete count;
            count = other.count;
            return *this;
        }
        count = other.count;
        return *this;
    }

    // 为句柄类拷贝构造函数服务
    // 功能:拷贝构造并返回结果,other计数+1，本身类计数-1
    bool ReAttach(const UseCount& other) {
        ++(*count);
        if (--(*count)==0) {
            delete count;
            count = other.count;
            return true;
        }
        count = other.count;
        return false;
    }
private:
    int* count;
};
