all:template memory string regex exception_handling bitcoin bitcoin2

template:template.cpp
	g++ template.cpp -o template -std=c++17 -Wall -Wextra

memory:memory.cpp
	g++ memory.cpp -o memory -std=c++17 -Wall -Wextra

string:string.cpp
	g++ string.cpp -o string -std=c++17 -Wall -Wextra

regex:regex.cpp
	g++ regex.cpp -o regex -std=c++17 -Wall -Wextra

exception_handling:exception_handling
	g++ exception_handling.cpp -o exception_handling -std=c++17 -Wall -Wextra


bitcoin:bitcoin.cpp
	g++ bitcoin.cpp -o bitcoin -std=c++17 -Wall -Wextra -lcurl

bitcoin2:bitcoin2.cpp
	g++ bitcoin2.cpp -o bitcoin2 -std=c++17 -Wall -Wextra -lcurl

clean:
	rm -rf template memory string regex exception_handling bitcoin bitcoin2