all:output input fileio stringstream streamstates lowlevel money

output:output.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra
	
input:input.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra
fileio:fileio.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra
stringstream:stringstream.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra
manipulators:manipulators.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra
streamstates:streamstates.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra
lowlevel:lowlevel.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra
money:money.cpp
	g++ $^ -o $@ --std=c++17 -Wall -Wextra

clean:
	rm -rf output input fileio stringstream streamstates lowlevel money