//#include <event2/event.h>
//#include <event2/listener.h>
//#include <string.h>
//#ifndef _Win32
//#include <signal.h>
//#else
//#endif // !_Win32
//
//#include <iostream>
//using namespace std;
//
//const unsigned int port = 5001;
//
//void listenCB(struct evconnlistener * ev, evutil_socket_t s,
//              struct sockaddr * addr, int socklen, void  * arg) {
//
//    cout << "lisenCB" << endl;
//}
//
//int main() {
//
//#ifdef _WIN32
//    WSADATA wsa;
//    WSAStartup(MAKEWORD(2, 2), &wsa);
//#else
//    if (signal(SIGPIPE, SIG_IGN) == SIR_ERR)
//        return 1;
//#endif
//    // 创建 event_base 上下文
//    event_base * base = event_base_new();
//    if (nullptr != base)
//        cout << "base create success." << endl;
//    // 创建绑定事件
//    // socket,bind,listen 
//    sockaddr_in sin;
//    memset(&sin, 0, sizeof(sin));
//    sin.sin_family = AF_INET;
//    sin.sin_port = htons(port);
//
//    evconnlistener * ev = evconnlistener_new_bind(
//        base, listenCB, base, LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE,
//        10,
//        (sockaddr *) &sin,
//        sizeof(sin));
//
//    if (base)
//        event_base_dispatch(base);
//    if (ev)
//        evconnlistener_free(ev);
//
//    if (base)
//        event_base_free(base);
//
//#ifdef _WIN32
//    WSACleanup();
//#endif
//    return 0;
//}
