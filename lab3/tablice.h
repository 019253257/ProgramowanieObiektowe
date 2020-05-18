#pragma once
#include<iostream>
#include<fstream>
using namespace std;
struct tablica
{

enum errors
{
NO_ERROR = 0,
INDEX_OUT_OF_BOUNDS = 1,
INPUT_FILE_ERROR = 2,
OUTPUT_FILE_ERROR = 4	
};

double** tab = NULL;
size_t x = 0;
size_t y = 0;
};
/*!
TU OPISZ FUNKCĘ

@param x - ilość wierszy
@param y - ilość kolumn
*/
tablica tworzenie_tablicy(size_t x, size_t y);

/*
@param tab - struktura na dane
@param wartosc - nowa wprowadzana wartosc
@param index_x - wiersz w ktorym ma byc wprowadzona wartosc
@param index_y - kolumna w ktorej ma byc wprowadzona wartosc
*/
void zmien_wartosc(tablica tab, double wartosc, size_t index_x, size_t index_y, tablica::errors& bledy);

/*
@param tab - struktura na dane
*/
void wyswietl(tablica tab);

/*
@param tab - struktura na dane
@param newx - nowa ilość wierszy
@param newy - nowa ilość kolumn
*/
tablica zmiana_rozmiaru_tablicy(tablica tab, size_t newx, size_t newy);

/*
@param x - ilość wierszy do aktualizacji
@param y - ilość kolumn do aktualizacji
*/
tablica wczytaj(size_t &x, size_t &y, tablica::errors& bledy);

/*
@param tab - struktura na dane
*/
void zapisz(tablica tab, tablica::errors& bledy);

/*
@param tab - struktura na dane
*/
void suma_w_wierszu(tablica tab);

void suma_w_kolumnie(tablica tab);

void znajdz_max_kolumna(tablica tab);

void znajdz_min_kolumna(tablica tab);
 
void znajdz_max_wiersz(tablica tab);
 
void znajdz_min_wiersz(tablica tab);
