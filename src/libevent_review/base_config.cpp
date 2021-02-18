#include <event2/event.h>#include <event2/thread.h>#include <event2/listener.h>#ifndef _WIN32#include <signal.h>#endif#include <iostream>using namespace std;
void listenCB(struct evconnlistener * ev, evutil_socket_t t, struct sockaddr * addr, int socklen, void * arg) {
    cout << "ListenCB"  << endl;
}
const int port = 5001;
int main() {#ifdef _WIN32    WSADATA  wsa;    WSAStartup(MAKEWORD(2, 2), &wsa);#else    if (signal(SIGPIPE, SGI_IGN) == SIG_ERR)        return 1;#endif    // 创建配置上下文    auto conf = event_config_new();    auto methods = event_get_supported_methods();    cout << "This PC suport I/O mothods:\n" << endl;;    for (int i = 0; methods[i] != NULL; i++) {        cout << methods[i] << endl;    }    //windows 支持IOCP（线程池）#ifdef _WIN32    event_config_set_flag(conf, EVENT_BASE_FLAG_STARTUP_IOCP);    evthread_use_windows_threads();    SYSTEM_INFO si;    GetSystemInfo(&si);    event_config_set_num_cpus_hint(conf, si.dwNumberOfProcessors);
#endif
    //初始化 libevent 上下文    auto  base = event_base_new_with_config(conf);    base = event_base_new();    if (!base) {        cerr << "event_base_new failed" << endl;        return 0;    }
    else {
        if (f & EV_FEATURE_ET)            cout << "EV_FEATRE_ET events are supported" << endl;        else            cout << "EV_FEATRE_ET events are NOT supported" << endl;        if (f & EV_FEATURE_O1)            cout << "EV_FEATURE_O1 events are supported" << endl;        else            cout << "EV_FEATURE_O1 events are NOT supported" << endl;
        if (f & EV_FEATURE_FDS)            cout << "EV_FEATURE_FDS events are supported" << endl;        else            cout << "EV_FEATURE_FDS events are NOT supported" << endl;
        if (f & EV_FEATURE_EARLY_CLOSE)            cout << "EV_FEATURE_EARLY_CLOSE events are supported" << endl;        else            cout << "EV_FEATURE_EARLY_CLOSE events are NOT supported" << endl;        // 创建监听事件，socket 由程序自动管理        sockaddr_in    sin;        memset(&sin, 0, sizeof(sin));        sin.sin_family = AF_INET;       // ipv4        sin.sin_port = htons(port);        /**
         * Allocate a new evconnlistener object to listen for incoming TCP connections
           on a given address.

         * @param base The event base to associate the listener with.
         * @param cb A callback to be invoked when a new connection arrives. If the
                  callback is NULL, the listener will be treated as disabled until the
                  callback is set.
         * @param ptr A user-supplied pointer to give to the callback.
         * @param flags Any number of LEV_OPT_* flags
         * @param backlog Passed to the listen() call to determine the length of the
                  acceptable connection backlog.  Set to -1 for a reasonable default.
         * @param addr The address to listen for connections on.
         * @param socklen The length of the address.

         * EVENT2_EXPORT_SYMBOL
              struct evconnlistener *evconnlistener_new_bind(struct event_base *base,
                  evconnlistener_cb cb, void *ptr, unsigned flags, int backlog,
                  const struct sockaddr *sa, int socklen);
         */
        evconnlistener * ev = evconnlistener_new_bind(base, listenCB, base, 10,
                                                      LEV_OPT_CLOSE_ON_FREE|LEV_OPT_REUSEABLE,
                                                      (sockaddr*) &sin, sizeof(sin));
        event_base_dispatch(base);        evconnlistener_free(ev);        event_base_free(base);    }    return 0;}


