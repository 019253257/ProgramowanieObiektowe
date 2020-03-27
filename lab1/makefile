program: main.o tablice.o menu.o
	g++ -o program main.o tablice.o menu.o
main.o: main.cpp menu.h
	g++ -c main.cpp
tablice.o: tablice.cpp tablice.h
	g++ -c tablice.cpp
menu.o: menu.cpp menu.h tablice.h
	g++ -c menu.cpp

