#pragma once
#include<iostream>
#include<fstream>
using namespace std;
double** tworzenie_tablicy(size_t x, size_t y);
void zmien_wartosc(double** tab, size_t x,size_t y, double wartosc, size_t index_x, size_t index_y);
void wyswietl(double** tab, size_t x, size_t y);
double** zmiana_rozmiaru_tablicy(double** tab, size_t &x,size_t &y, size_t newx, size_t newy);
double** wczytaj(size_t &x, size_t &y);
void zapisz(size_t x, size_t y, double** tab);
