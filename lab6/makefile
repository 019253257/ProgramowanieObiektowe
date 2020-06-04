program: main.o menu.o
	g++ -o program main.o menu.o
main.o: main.cpp menu.h
	g++ -c main.cpp
menu.o: menu.cpp menu.h tablice.h
	g++ -c menu.cpp

