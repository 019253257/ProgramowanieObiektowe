#pragma once
#include<iostream>
#include<fstream>
using namespace std;
/*
@param x - ilość wierszy
@param y - ilość kolumn
*/
double** tworzenie_tablicy(size_t x, size_t y);
/*
@param tab - wskaźnik do tablicy
@param x - ilość wierszy
@param y - ilość kolumn
@param wartosc - nowa wprowadzana wartosc
@param index_x - wiersz w ktorym ma byc wprowadzona wartosc
@param index_y - kolumna w ktorej ma byc wprowadzona wartosc
*/
void zmien_wartosc(double** tab, size_t x,size_t y, double wartosc, size_t index_x, size_t index_y);
/*
@param tab - wskaźnik do tablicy
@param x - ilość wierszy
@param y - ilość kolumn
*/
void wyswietl(double** tab, size_t x, size_t y);
/*
@param tab - wskaźnik do tablicy
@param x - ilość wierszy
@param y - ilość kolumn
@param newx - nowa ilość wierszy
@param newy - nowa ilość kolumn

*/
double** zmiana_rozmiaru_tablicy(double** tab, size_t &x,size_t &y, size_t newx, size_t newy);
/*
@param x - ilość wierszy do aktualizacji
@param y - ilość kolumn do aktualizacji
*/
double** wczytaj(size_t &x, size_t &y);
/*
@param x - ilość wierszy
@param y - ilość kolumn
@param tab - tablica do zapisu
*/
void zapisz(size_t x, size_t y, double** tab);
