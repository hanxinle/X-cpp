> 数据结构与算法对应的是数据的存储逻辑设计及关联操作，设计模式对应的是 OOP 的设计逻辑。

# 1 创建型设计模式

## 1.1 简单工厂模式

简单工厂，定制对象的产生，封装了不同对象生成的统一方法，即采用统一接口生成不同的对象，仅需要少许参数指定即可。

```c++
#include <iostream>
#include<string>
#include "DynOBJ.h"
using namespace std;

class Api {
public:
    virtual void test(string s) = 0;
protected:
    Api() {}
};


class ImpleOne :public Api {
public:
    void test(string s) {
        cout << "现在是One在执行" << s;
    }
};

class ImpleTwo :public Api {
public:
    void test(string s) {
        cout << "现在是Two在执行" << s;
    }
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

    static Api* createApi() {
        return new ImpleOne();
    }
};


/**
 * 传入参数1，可以实现从 数据库 读入的功能
 * 传入参数2，可以实现从 文本文件 读入的功能
 * 实现了客户端调用和 implOne，implTwo 的解耦合
 * class Factory 实现了变化隔离
 */

int main1(void) {
    Api* pApi = Factory::createApi(2);     

    pApi->test("现在是使用简单工厂方法重构");
    Api* pApiEx = Factory::createApi();
    system("pause");
    return 0;
}
```
## 1.2 单例模式

单例模式，保证全局存在且唯一存在一个对象实例。以下是单例模式最直观的实现：

```c++
#include <iostream>
#include <stdio.h>
using namespace std;

class Singleton {
private:
    static Singleton * p_instance;
    Singleton() {
        p_instance = nullptr;
        cout << "调用私有构造函数" << endl;
    }

public:
// C++ 中构造函数不是线程安全的,
// getInstance 中 if 语句被打断，将生成多个不同对象
    static Singleton * getInstance() {
        if (p_instance == nullptr) {
            p_instance = new Singleton();
        }
        return p_instance;
    }
};

Singleton *Singleton::p_instance = nullptr;

int main() {
    Singleton * p1 = Singleton::getInstance();
    Singleton * p2 = Singleton::getInstance();

    printf("p1 = %x,p2 = %x", p1, p2); // 结果应相同
    return 0;
}

```
上述实现是懒汉模式， getInstance 函数中 if 语句被打断跳出时间片，会造成在全局创建多个对象的情况，下面代码描述了那样一种情况。

```c++
#include <afxwin.h>
#include <iostream>
#include <stdio.h>
using namespace std;

CRITICAL_SECTION g_cs;
class Singleton {
private:
    Singleton() {
        m_singer = NULL;
        cout << "构造一个Singleton对象" << endl;
    }
public:
    static Singleton* getInstance() { //懒汉式:延迟加载
        if (m_singer == NULL) {
            if (m_singer == NULL)
                m_singer = new Singleton();
        }
        return m_singer;
    }
private:
    static Singleton* m_singer;
};

UINT Func(LPVOID) {
    printf("%x\n", Singleton::getInstance());
    return 0;
}
Singleton *Singleton::m_singer = NULL;//new Singleton; 在C++中构造函数不是线程安全的
int main(void) {

    ::InitializeCriticalSection(&g_cs);
    for (int i = 0; i < 10; i++) {
        AfxBeginThread(Func, NULL);
    }
    ::DeleteCriticalSection(&g_cs);
    system("pause");
    return 0;
}
```
上述 getInstance 中判断实例指针为空并创建对象是懒汉模式，if 被打断则会造成创建多个对象，解决方法是设置互斥访问，本例子使用的机制是临界区，第一条 if 语句每个线程都可以执行，但是第二条 if 语句及对象创建语句则是要在临界区中完成。两条语句采用double-checkin 模式。

```c++
#include <afxwin.h>
#include <iostream>
#include <stdio.h>
using namespace std;

CRITICAL_SECTION g_cs;
class Singleton {
private:
    Singleton() {
        m_singer = NULL;
        cout << "构造一个Singleton对象" << endl;
    }
public:
    static Singleton* getInstance() {
        // double check-in，第一条 if 可以多个线程访问
        // 但是涉及创建对象的时候，必须重新判断，if 语句是多条汇编的组合
        // 因此要进入临界区，判断和创建必须是互斥的
        if (m_singer == NULL) {
            ::EnterCriticalSection(&g_cs);
            if (m_singer == NULL)
                m_singer = new Singleton();
            ::LeaveCriticalSection(&g_cs);
        }
        return m_singer;
    }
private:
    static Singleton* m_singer;
};

UINT Func(LPVOID) {
    printf("%x\n", Singleton::getInstance());
    return 0;
}
Singleton *Singleton::m_singer = NULL;//new Singleton; 在C++中构造函数不是线程安全的
int main(void) {

    ::InitializeCriticalSection(&g_cs);
    for (int i = 0; i < 30; i++) {
        AfxBeginThread(Func, NULL);
    }
    ::DeleteCriticalSection(&g_cs);
    system("pause");
    return 0;
}
```
单例模式可以和全局 map 结合，实现唯一缓存。
利用 map 还可以实现多例模式，单例模式指定存在且唯一存在一个实例，多例模式可以指定存在一个数量的实例。



# 2 行为设计模式

## 2.1 解释器模式


## 2.2 观察者模式

软件构建过程中，对象间存在一种“通知依赖关系”，一个对象的状态发生改变，所有的依赖对象都将得到通知。这样的依赖关系过于紧密，将使软件不能很好抵御变化。

使用面向对象技术，可以将这种依赖关系弱化，使得生成何种通知、是否接收通知可控，从而实现软件体系结构的松耦合，把通知定义为接口，Application 继承这个接口，在App class中重写对接口的调用。

定义：定义对象间一种一对多（变）的依赖关系，以便当一个对象的状态发生变化时，所有依赖它的对象都得到通知并自动更新，产生一种松耦合的关系。

PS：在 C++ 及其它 OO 语言中，多继承因为可能导致过多 bug 而很少用（以前的例子菱形继承中需要虚继承），多继承往往是继承的类都是接口类（抽象基类）。
