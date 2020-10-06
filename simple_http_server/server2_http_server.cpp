#include <stdlib.h>
#include <string.h>

#include <regex>
#include <string>
#include <thread>

#include "XTcp.h"
using namespace std;
class TcpThread {
   public:
    void Main() {
        char buf[10000] = {0};
        for (;;) {
            // 接收 http 请求
            int recvLen = client.Recv(buf, sizeof(buf) - 1);
            if (recvLen <= 0) {
                Close();
                return;
            }
            buf[recvLen] = '\0';

            printf("========recv=========\n%s================\n", buf);

            // GET /index.html HTTP/1.1
            // Host:http://192.168.92.128
            // User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; rv:51.0)
            // Gecko/20100101 Fi Accept:
            // text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
            // Accept-Language: zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3
            // Accept-Encoding: gzip, deflate
            // DNT: 1
            // Connection: keep-alive
            // Upgrade-Insecure-Requests: 1

            // 指定规则
            string src = buf;
            string pattern = "^([A-Z]+) (.+) HTTP/1";
            regex r(pattern);
            //结果集
            smatch mas;
            regex_search(src, mas, r);
            if (mas.size() == 0) {
                printf("%s failed.\n", pattern.c_str());
                Close();
                return;
            }

            string type = mas[1];
            string path = mas[2];
            if (type != "GET") {
                Close();
                return;
            }

            string filename = path;
            if (path == "/") {
                filename = "/index.html";
            }
            string filepath = "www";

            filepath += filename;

            FILE *fp = fopen(filepath.c_str(), "rb");
            if (fp == nullptr) {
                Close();
                return;
            }

            fseek(fp, 0, SEEK_END);
            int filesize = ftell(fp);

            fseek(fp, 0, 0);

            printf("filesize is %d\n", filesize);

            //开始回应 http GET请求
            //\r\n 分隔符，两个 \r\n 为协议头结束标志
            string rmsg = "";
            rmsg = "HTTP/1.1 200 OK\r\n";
            rmsg += "Server: xhttp\r\n";
            rmsg += "Content-Type:text/html\r\n";
            rmsg += "Content-Length:";
            // rmsg += "6\r\n";
            char bsize[128] = {0};
            sprintf(bsize, "%d", filesize);
            rmsg += bsize;
            rmsg += "\r\n\r\n";

            // rmsg += "0123456789";
            //发送消息头
            int sendSize = client.Send(rmsg.c_str(), rmsg.size());
            printf("sendSize = %d\n", sendSize);
            printf("========send==========\n%s\n====================\n",
                   rmsg.c_str());

            //发送正文
            for (;;) {
                int len = fread(buf, 1, sizeof(buf), fp);
                if (len <= 0) break;
                int re = client.Send(buf, len);
                if (re <= 0) break;
            }
        }
        Close();
        // char buf[1024] = { 0 };
        // for (;;)
        // {
        // 	int recvlen = client.Recv(buf, sizeof(buf)-1);
        // 	if (recvlen <= 0) break;
        // 	buf[recvlen] = '\0';
        // 	if (strstr(buf, "quit") != NULL)
        // 	{
        // 		char re[] = "quit success!\n";
        // 		client.Send(re, strlen(re) + 1);
        // 		break;
        // 	}
        // 	int sendlen = client.Send("ok\n", 4);
        // 	printf("recv %s\n", buf);
        // }
        // client.Close();
        // delete this;
    }
    void Close() {
        client.Close();
        delete this;
    }
    XTcp client;
};

int main(int argc, char *argv[]) {
	unsigned short port = 8080;
    if (argc > 1) {
        port = atoi(argv[1]);
    }
    XTcp server;
    server.CreateSocket();
    server.Bind(port);
    for (;;) {
        XTcp client = server.Accept();
        TcpThread *th = new TcpThread();
        th->client = client;
        std::thread sth(&TcpThread::Main, th);
        sth.detach();
    }
    server.Close();
    getchar();
    return 0;
}