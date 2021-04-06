all:arrays deque lists maps multimaps sets vector test_circular_buffer

arrays:arrays.cpp
	g++ $^ -o $@
deque: deque.cpp
	g++ $^ -o $@
lists:lists.cpp
	g++ $^ -o $@
maps:maps.cpp
	g++ $^ -o $@
multimaps:multimaps.cpp
	g++ $^ -o $@
sets:sets.cpp
	g++ $^ -o $@
vector:vector.cpp
	g++ $^ -o $@
test_circular_buffer:test.cpp circular_buffer.hpp
	g++ $^ -o $@

clean:
	rm -rf arrays deque lists maps multimaps sets vector test_circular_buffer