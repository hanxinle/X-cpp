all:http response

http:server2_http_server.cpp
	g++ $+ -o $@ -I../xsocket  -std=c++11 -lpthread -lxsocket -L../xsocket

response:server1_response_browser.cpp
	g++ $+ -o $@ -I../xsocket  -std=c++11 -lpthread -lxsocket -L../xsocket

clean:
	rm -rf response http