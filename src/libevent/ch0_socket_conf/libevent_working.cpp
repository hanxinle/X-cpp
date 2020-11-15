#include <event2/event.h>
#include <stdio.h>
#include <signal.h>

void signal_cb (int fd,short event, void *argc) {
    // 函数内部要用到 main 中的 base
    struct event_base * base = (event_base *)argc;
    struct timeval t1 = {2,0};
    printf ("捕获中断信号，两秒内退出.\n");
    event_base_loopexit(base,&t1);
}

void timeout_cb (int fd, short event, void *argc) {
    printf("timeout_cb.\n");
}

int main() {
    // 创建 Reactor 实例指针 base，base 内可以包含多个事件处理器
    event_base * base = event_base_new();
    // 创建信号时间处理器，处理中断信号，指明回调函数
    event * signal_event = evsignal_new ( base, SIGINT, signal_cb, base );
    // 将事件处理器至于待激活(pending)模式
    event_add ( signal_event, NULL );


    timeval tv = { 1,0 };
    event *timeout_event = evtimer_new ( base, timeout_cb, NULL );

    event_add ( timeout_event, &tv );
    // 事件循环，该过程会激活事件处理器处理特定事件
    event_base_dispatch ( base );
    // 回收事件处理器及相关系统资源
    event_free ( timeout_event );
    event_free ( signal_event );
    event_base_free ( base );

    return 0;
}