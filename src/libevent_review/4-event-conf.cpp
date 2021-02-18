//#include <event2/event.h>
//#include <event2/listener.h>
//#include <string.h>
//#ifndef _Win32
//#include <signal.h>
//#else
//#endif // !_Win32
//#include <thread>
//#include <errno.h>
//#include <iostream>
//using namespace std;
//
//const unsigned int port = 5001;
//void clientCB (evutil_socket_t s, short w, void * arg) {
//    event * ev = (event*) arg;
//    // 判断超时
//    if (w&EV_TIMEOUT) {
//        cout << "Timeout" << endl;
//        event_free (ev);
//        evutil_closesocket (s);
//        return;
//    }
//    char buf[1024] = {0};
//    int len = recv (s, buf, sizeof (buf)-1, 0);
//    if (len > 0) {
//        cout << buf << endl;
//        send (s, "ok", 2, 0);
//    }
//    else {
//        // 清理event
//        cout << "event free" << endl;
//        event_free (ev);
//        evutil_closesocket (s);
//    }
//}
//
//void listenCB (evutil_socket_t s, short w, void * arg) {
//    cout<< "listenCB" << endl;
//    sockaddr_in sin;
//    socklen_t size = sizeof (sin);
//
//    evutil_socket_t client = accept (s, (sockaddr*) &sin, &size);
//
//    // 获取客户端ip
//    char ip[16] = {0};
//    evutil_inet_ntop (AF_INET, &sin.sin_addr, ip, sizeof (ip)-1);
//    cout << "client ip is " << ip << endl;
//
//    // 创建客户端事件读取事件
//    event_base * base = (event_base *) arg;
//    event * ev = event_new (base, client, EV_READ| EV_PERSIST, clientCB, event_self_cbarg ());
//
//    // 边缘触发
//    //event * ev = event_new (base, client, EV_READ| EV_PERSIST|EV_ET, clientCB, event_self_cbarg ());
//    timeval t = {20,0};
//    event_add (ev, &t);
//
//
//
//}
//
//int main () {
//
//#ifdef _WIN32
//    WSADATA wsa;
//    WSAStartup (MAKEWORD (2, 2), &wsa);
//#else
//    if (signal (SIGPIPE, SIG_IGN) == SIR_ERR)
//        return 1;
//#endif
//    // 创建 event_base 上下文
//    event_base * base = event_base_new ();
//    if (nullptr != base)
//        cout << "base create success." << endl;
//    // evutilsocket 定制
//    evutil_socket_t sock = socket (AF_INET, SOCK_STREAM, 0);
//    if (sock < 0) {
//        cerr << "socket error" <<strerror (errno) << endl;
//        return -1;
//    }
//    int val = 1;
//    // 设置地址复用和非阻塞
//    evutil_make_socket_nonblocking (sock);
//    evutil_make_listen_socket_reuseable (sock);
//
//    sockaddr_in sin;
//    memset (&sin, 0, sizeof (sin));
//    sin.sin_family = AF_INET;
//    sin.sin_port = htons (port);
//
//    int re = ::bind (sock, (sockaddr*) &sin, sizeof (sin));
//
//    if (re != 0) {
//        cerr << "bind error: " << strerror (errno) << endl;
//        return -1;
//    }
//
//    listen (sock, 10);
//
//    event * ev = event_new (base, sock, EV_READ | EV_PERSIST, listenCB, base);
//    event_add (ev, 0);
//    // 进入事件主循环
//    event_base_dispatch (base);
//    evutil_closesocket (sock);
//    event_base_free (base);
//
//#ifdef _WIN32
//    WSACleanup ();
//#endif
//    return 0;
//}
