#ifndef tablica_hpp
#define tablica_hpp

#include <iostream>
#include "komorka.hpp"
using namespace std;

class Tablica
{
public:
    size_t zwroc_x() const;
    size_t zwroc_y() const;
    typy* zwroc_typy(typy* w = nullptr) const;
    Komorka** zwroc_kolumne(size_t k) const;
    Komorka** zwroc_wiersz(size_t w) const;
    Komorka& zwroc_komorke(size_t indeks_x, size_t indeks_y);
    
    //konstruktory i destruktor
    Tablica();
    Tablica(size_t nowy_x, size_t nowy_y, typy* nowe_typy);
    Tablica(const Tablica& t);
    Tablica(Tablica&& t);
    Tablica& operator=(const Tablica& t);
    Tablica& operator=(Tablica&& t);
    ~Tablica();
    
    void wypisz(ostream& out, bool naglowek = false) const;
    void wczytaj(istream& in);
    void zmien_rozmiar(size_t nowy_x, size_t nowy_y, typy* nowe_typy);
    
    static double policz_min(Komorka** t, size_t n);
    static double policz_max(Komorka** t, size_t n);
    static double policz_sum(Komorka** t, size_t n);
    static double policz_avg(Komorka** t, size_t n);
private:
    void usun_stara();
    void skopiuj_nowa(const Tablica& t);
    void przenies_nowa(Tablica& t);
    
    Komorka*** tab;
    typy* typy_tablicy;
    size_t x;
    size_t y;
};

#endif /* tablica_hpp */
