#pragma once
#include<iostream>
#include<fstream>
using namespace std;
struct tablica
{
double** tab = NULL;
size_t x = 0;
size_t y = 0;
};
/*
@param x - ilość wierszy
@param y - ilość kolumn
*/
tablica tworzenie_tablicy(size_t x, size_t y);
/*
@param tab - wskaźnik do tablicy
@param x - ilość wierszy
@param y - ilość kolumn
@param wartosc - nowa wprowadzana wartosc
@param index_x - wiersz w ktorym ma byc wprowadzona wartosc
@param index_y - kolumna w ktorej ma byc wprowadzona wartosc
*/
void zmien_wartosc(tablica tab, double wartosc, size_t index_x, size_t index_y);
/*
@param tab - wskaźnik do tablicy
@param x - ilość wierszy
@param y - ilość kolumn
*/
void wyswietl(tablica tab);
/*
@param tab - wskaźnik do tablicy
@param x - ilość wierszy
@param y - ilość kolumn
@param newx - nowa ilość wierszy
@param newy - nowa ilość kolumn

*/
tablica zmiana_rozmiaru_tablicy(tablica tab, size_t newx, size_t newy);
/*
@param x - ilość wierszy do aktualizacji
@param y - ilość kolumn do aktualizacji
*/
tablica wczytaj(size_t &x, size_t &y);
/*
@param x - ilość wierszy
@param y - ilość kolumn
@param tab - tablica do zapisu
*/
void zapisz(tablica tab);
