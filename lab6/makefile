program: main.o menu.o tablica.o komorka.o
	g++ -o program main.o menu.o tablica.o komorka.o
main.o: main.cpp menu.hpp
	g++ -c main.cpp
menu.o: menu.cpp menu.hpp tablica.hpp
	g++ -c menu.cpp
tablica.o: tablica.cpp tablica.hpp komorka.hpp
	g++ -c tablica.cpp
komorka.o: komorka.cpp komorka.hpp
	g++ -c komorka.cpp
