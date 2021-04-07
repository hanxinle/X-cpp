#pragma once
template <typename T, int n>
class Array {
public:
    Array ();
    Array (int length);
    ~Array ();
    T Get (int num);
    int Size ();
    void Set (T data, int num);
    T& operator[](int num);
private:
    int size;
    T * pt;
};

// n 是定长的，所以数组一旦生成不能变化
template <typename T, int n>
Array<T, n>::Array () {
    this->pt = new T[n];
}

template <typename T, int n>
int Array<T, n>::Size () {
    return n;
}
template <typename T, int n>
Array<T, n>::Array (int length) {
    this->pt = new T[length];
}

template <typename T, int n>
Array<T, n>::~Array () {
    delete[] this->pt;
}

template <typename T, int n>
T Array<T, n>::Get (int num) {
    if (num > n || num  < 0) {
        // 异常，不用做
    } else {
        return *(this->pt+num);
    }

}


template <typename T, int n>
void Array<T, n>::Set (T data, int num) {
    if (num > n || num  < 0) {
        // 异常，不用做
    } else {
        *(this->pt+num) = data;
    }
}

template <typename T, int n>
T& Array<T, n>::operator[](int num) {
    if (num > n || num  < 0) {
        // 异常，不用做
    } else {
        return *(this->pt+num);
    }
}
