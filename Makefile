test : main.o i8080.o
	g++ -g -std=c++1z main.o i8080.o -o test

main.o: main.cpp
	g++ -g -std=c++1z -c main.cpp

i8080.o: i8080.cpp
	g++ -g -std=c++1z -c i8080.cpp