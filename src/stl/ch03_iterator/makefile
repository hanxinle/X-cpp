all:input output forward bidirectional random_access aux_functions itt_adaptors generic_function  iterator_traits test

input:input.cpp
	g++ $^ -o $@
output:output.cpp
	g++ $^ -o $@
forward:forward.cpp
	g++ $^ -o $@
bidirectional:bidirectional.cpp
	g++ $^ -o $@
random_access:random_access.cpp
	g++ $^ -o $@
aux_functions:aux_functions.cpp
	g++ $^ -o $@
itt_adaptors:itt_adaptors.cpp
	g++ $^ -o $@
generic_function:generic_function.cpp
	g++ $^ -o $@
iterator_traits:iterator_traits.cpp
	g++ $^ -o $@
test:test.cpp
	g++ $^ -o $@
	
clean:
	rm -rf input output forward bidirectional random_access aux_functions itt_adaptors generic_function  iterator_traits test