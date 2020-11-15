#include <event2/event.h>
#include <string.h>
#ifndef _WIN32
#include <signal.h>
#else
#endif
#include <iostream>
#include <thread>
using namespace std;
#define SPORT 5001

static timeval t1 = {1, 0};

void timerl(int sock, short which, void *arg) {
    cout << "[timer1]" << endl;
    event *ev = (event *)arg;
    // 进入一次就退出
    if (!evtimer_pending(ev, &t1)) {
        evtimer_del(ev);
        evtimer_add(ev, &t1);
    }
}

void timer2(int sock, short which, void *arg) {
    cout << "[timer2]" << endl;
    this_thread::sleep_for(3000ms);
}

void timer3(int sock, short which, void *arg) { cout << "[timer3]" << endl; }

int main() {
#ifdef _WIN32
    //初始化socket库
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#else
    //忽略管道信号，发送数据给已关闭的socket
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) return 1;
#endif
    event_base *base = event_base_new();
    // 非持久的，最后一个参数传递的是事件处理器
    event *evl = evtimer_new(base, timerl, event_self_cbarg());

    if (!evl) {
        cout << "evtimer_new timerl failed!" << endl;
        return -1;
    }

    evtimer_add(evl, &t1);

    static timeval t2;
    t2.tv_sec = 1;
    t2.tv_usec = 200000;
    // ev2 定时器是持久的，不需要在回调函数中执行定时器的 pending 操作
    event *ev2 = event_new(base, -1, EV_PERSIST, timer2, 0);
    event_add(ev2, &t2);

    //超时优化，event 默认用二叉堆存储（完全二叉树），插入删除都是O(logN)
    //优化到双向队列，插入删除都是 O(1)
    event *ev3 = event_new(base, -1, EV_PERSIST, timer3, 0);
    static timeval t3_in = {3, 0};
    const timeval *t3;
    t3 = event_base_init_common_timeout(base, &t3_in);
    event_add(ev3, t3);

    event_base_dispatch(base);
    event_base_free(base);

    return 0;
}