all:send_string_server send_index_html

send_string_server:server1_response_browser.cpp
	g++ $+ -o $@ -I../xsocket  -std=c++11 -lpthread -lxsocket -L../xsocket

send_index_html:server2_http_server.cpp
	g++ $+ -o $@ -I../xsocket  -std=c++11 -lpthread -lxsocket -L../xsocket

clean:
	rm -rf send_string_server send_index_html