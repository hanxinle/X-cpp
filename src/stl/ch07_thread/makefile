all:threads shared locks atomic conditional promise match

threads:threads.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra	-lpthread
shared:shared.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra -lpthread
locks:locks.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra -lpthread
atomic:atomic.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra -lpthread
conditional:conditional.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra -lpthread
promise:promise.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra -lpthread
match:match.cpp
	 g++-8 match.cpp -o match -lpthread -lstdc++fs --std=c++17
clean:
	rm -rf threads shared locks atomic conditional promise match