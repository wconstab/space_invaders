main : main.o i8080.o
	g++ -g -std=c++1z main.o i8080.o -o main

main.o: main.cpp
	g++ -g -std=c++1z -c main.cpp

i8080.o: i8080.cpp
	g++ -g -std=c++1z -c i8080.cpp

GTEST_DIR = googletest-release-1.8.1.nosync/googletest/
gtest_all.o: 
	g++ -std=c++11 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
    -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

# TODO use CMAKE
# https://github.com/google/googletest/tree/master/googletest#using-cmake
test_main: gtest_all.o i8080.cpp tests/test_main.cpp
	g++ -std=c++1z -isystem ${GTEST_DIR}/include -I. -pthread tests/test_main.cpp i8080.cpp libgtest.a \
    -o test_main

test: test_main
	./test_main

run: main
	./main