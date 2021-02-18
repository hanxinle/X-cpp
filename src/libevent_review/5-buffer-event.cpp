#include <iostream>
#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <string.h>
#ifndef _WIN32
#include <signal.h>
#else
#endif

using namespace std;
void eventCB (bufferevent * be, short events, void * arg) {
    cout << "eventCB" << endl;
    if (events & BEV_EVENT_TIMEOUT && events & BEV_EVENT_READING) {
        cout << "bufferevent reading but timeout" << endl;
        bufferevent_free (be);
    }
    else if (events & BEV_EVENT_ERROR) {
        bufferevent_free (be);
    }
    else {
        cout << "other event" << endl;
    }
}



void writeCB (bufferevent * be, void * arg) {
    cout << "writeCB" << endl;
}

void readCB (bufferevent * be, void * arg) {
    cout << "readCB" << endl;
    char data[1024] = {0};
    int len = bufferevent_read (be, data, sizeof (data)-1);
    if (len < 0) return;
    else cout <<  data << flush;
    if (strstr (data, "quit") != nullptr) {
        cout<< "quit" << endl;
        bufferevent_free (be);
    }
    bufferevent_write (be, "ok", 3);

}

void listenCB (evconnlistener * ev, evutil_socket_t s, sockaddr * sin, int slen, void * arg) {
    cout << "listenCB" << endl;
    event_base  * base = (event_base*) arg;
    // 创建bufferevent上下文，清理buffervet时关闭socket
    bufferevent * bev = bufferevent_socket_new (base, s, BEV_OPT_CLOSE_ON_FREE);
    // 添加监管事件
    bufferevent_enable (bev, EV_READ | EV_WRITE);
    // 设置读写水位
    bufferevent_setwatermark (bev, EV_READ,
                              5,   // 低水位，默认是0，表无限制                          5,
                              10); // 高水位，默认是0，表无限制 

    bufferevent_setwatermark (bev, EV_WRITE,
                              5,   // 低水位，默认是0，无限制，缓冲数据低于5写入回调被调用
                              0);  // 高水位无效
    // 设置超时时间
    timeval t1 = {10,0};
    bufferevent_set_timeouts (bev, &t1, 0);

    // 设置回调函数
    bufferevent_setcb (bev, readCB, writeCB, eventCB, base);
}

int main () {
#ifdef _WIN32
    WSADATA wsa;
    WSAStartup (MAKEWORD (2, 2), &wsa);
#else
    if (signal (SIGPIPE, SIG_IGN) == SIG_ERR)
        return 1;
#endif

    event_base * base = event_base_new ();
    // 创建服务器
    sockaddr_in sin;
    memset (&sin, 0, sizeof (sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons (5001);

    evconnlistener * ev = evconnlistener_new_bind (base, listenCB, base,
                                                   LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE,
                                                   10,
                                                   (sockaddr*) & sin, sizeof (sin));




    // 进入事件主循环
    event_base_dispatch (base);
    evconnlistener_free (ev);
    event_base_free (base);

    return 0;
}