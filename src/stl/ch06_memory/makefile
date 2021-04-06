all:unique shared allocator debug_allocator rawmem

unique:unique.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra	
shared:shared.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra
allocator:allocator.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra
debug_allocator:debug_allocator.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra
rawmem:rawmem.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra


clean:
	rm -rf unique shared allocator debug_allocator rawmem