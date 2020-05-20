#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class tablica
{
	
private:
double** tab = NULL;
size_t x = 0;
size_t y = 0;

public:
enum errors
{
NO_ERROR = 0,
INDEX_OUT_OF_BOUNDS = 1,
INPUT_FILE_ERROR = 2,
OUTPUT_FILE_ERROR = 4	
};

//konstruktory i destrukotry
tablica();
tablica(tablica& b);
tablica& operator=(tablica& b);
tablica(tablica&& b);
tablica& operator=(tablica&& b);
tablica(size_t x, size_t y);
~tablica();

/*
@param tab - struktura na dane
*/
void wyswietl();
/*
@param tab - struktura na dane
@param wartosc - nowa wprowadzana wartosc
@param index_x - wiersz w ktorym ma byc wprowadzona wartosc
@param index_y - kolumna w ktorej ma byc wprowadzona wartosc
*/
tablica::errors zmien_wartosc(double wartosc, size_t index_x, size_t index_y);
/*
@param tab - struktura na dane
@param newx - nowa iloœæ wierszy
@param newy - nowa iloœæ kolumn
*/
void zmiana_rozmiaru_tablicy(size_t newx, size_t newy);
/*
@param x - iloœæ wierszy do aktualizacji
@param y - iloœæ kolumn do aktualizacji
*/
tablica::errors wczytaj(string s);
/*
@param tab - struktura na dane
*/
tablica::errors zapisz(string s);
/*
@param tab - struktura na dane
*/
void suma_w_wierszu();
/*
@param tab - struktura na dane
*/
void suma_w_kolumnie();
/*
@param tab - struktura na dane
*/
void znajdz_max_kolumna();
/*
@param tab - struktura na dane
*/
void znajdz_min_kolumna();
/*
@param tab - struktura na dane
*/
void znajdz_max_wiersz();
/*
@param tab - struktura na dane
*/
void znajdz_min_wiersz();
/*
@param tab - struktura na dane
*/
void znajdz_srednia_kolumna();
/*
@param tab - struktura na dane
*/
void znajdz_srednia_wiersz();

};











