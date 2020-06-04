#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<tuple>
using namespace std;

enum errors
{
NO_ERROR = 0,
INDEX_OUT_OF_BOUNDS = 1,
INPUT_FILE_ERROR = 2,
OUTPUT_FILE_ERROR = 4,
TABLICA_EMPTY = 8,
};

template<class T>
class cell
{
	public:
	T data;
	static T suma(cell<T>* dane, size_t n)
	{
		T acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			acc += dane[i].data;
		delete[] dane;
		return acc;
	}
	static T min(cell<T>* dane, size_t n)
	{
		T acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			if (dane[i].data < acc)
				acc = dane[i].data;
		delete[] dane;
		return acc;
	}
	static T max(cell<T>* dane, size_t n)
	{
		T acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			if (dane[i].data > acc)
				acc = dane[i].data;
		delete[] dane;
		return acc;
	}
	static T srednia(cell<T>* dane, size_t n)
	{
		return suma(dane, n) / n;
	}
};
template<>
class cell<string>
{
	public:
	string data;
	static string suma(cell<string>* dane, size_t n)
	{
		string acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			acc += dane[i].data;
		delete[] dane;
		return acc;
	}
	static string min(cell<string>* dane, size_t n)
	{
		string acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			if (dane[i].data < acc)
				acc = dane[i].data;
		delete[] dane;
		return acc;
	}
	static string max(cell<string>* dane, size_t n)
	{
		string acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			if (dane[i].data > acc)
				acc = dane[i].data;
		delete[] dane;
		return acc;
	}
	static string srednia(cell<string>* dane, size_t n)
	{
		return "N/A";
	}
};

template<class T1, class T2, class T3>
class tablica
{

private:
tuple<cell<T1>, cell<T2>, cell<T3>>* tab = NULL;
size_t y = 0;

public:
//konstruktory i destrukotry
tablica();
tablica(tablica& b);
tablica<T1, T2, T3>& operator=(tablica& b);
tablica(tablica&& b);
tablica<T1, T2, T3>& operator=(tablica&& b);
tablica(size_t y);
~tablica();

//gettery
size_t get_x() { return 3; }
size_t get_y() { return y; }

/*!
Ta funkcja ma wyswietlac arkusz
*/
void wyswietl();
/*
Ta funkcja zmienia wartosc wybranej komorki
@param wartosc - nowa wprowadzana wartosc
@param index_x - wiersz w ktorym ma byc wprowadzona wartosc
@param index_y - kolumna w ktorej ma byc wprowadzona wartosc
*/
template<class rT, int n>
errors zmien_wartosc(rT wartosc, size_t index_y);
/*
Ta funkcja zmienia rozmiar arkusza
@param newx - nowa iloœæ wierszy
@param newy - nowa iloœæ kolumn
*/
void zmiana_rozmiaru_tablicy(size_t newy);
/*
Ta funkcja wczytuje arkusz z pliku i zwraca ew. blad
@param s - nazwa wczytywanego pliku
*/
errors wczytaj(string s);
/*
Ta funkcja zapisuje arkusz do pliku i zwraca ew. blad
@param s - nazwa zapisywanego pliku
*/
errors zapisz(string s);
/*
Funkcje sluzace wykopiowaniu wiersza/kolumny o zadanym indexie (w/k)
*/
template<class rT, int n>
cell<rT>* get_kolumna();

/*
Ta funkcja liczy sume w kolumnie
@param k - numer kolumny
@param e - niezbedy do zwrocenia informacji o bledzie
*/
template<class rT, int n>
rT suma_w_kolumnie(errors& e);
/*
Ta funkcja liczy srednia w kolumnie
@param k - numer kolumny
@param e - niezbedy do zwrocenia informacji o bledzie
*/
template<class rT, int n>
rT znajdz_srednia_kolumna(errors& e);
/*
Ta funkcja znajduje max w kolumnie
@param k - numer kolumny
@param e - niezbedy do zwrocenia informacji o bledzie
*/
template<class rT, int n>
rT znajdz_max_kolumna(errors& e);
/*
Ta funkcja znajduje min w kolumnie
@param k - numer kolumny
@param e - niezbedy do zwrocenia informacji o bledzie
*/
template<class rT, int n>
rT znajdz_min_kolumna(errors& e);

};

template<class T1, class T2, class T3>
tablica<T1, T2, T3>::tablica()
{
	y = 0;
	tab = nullptr;
}
template<class T1, class T2, class T3>
tablica<T1, T2, T3>::tablica(tablica& b)
{
	y = b.y;
	if (b.tab == nullptr)
    {
        tab = nullptr;
    }
	else
	{
		tab = new tuple<cell<T1>, cell<T2>, cell<T3>>[y];
	}
}
template<class T1, class T2, class T3>
tablica<T1, T2, T3>& tablica<T1, T2, T3>::operator=(tablica& b)
{
	delete[] tab;
	y = b.y;
	if (b.tab == nullptr)
    {
        tab = nullptr;
    }
	else
	{
		tab = new tuple<cell<T1>, cell<T2>, cell<T3>>[y];
		for (int i = 0; i < y; i++)
		{
		    tab[i] = b.tab[i];
		}
	}
	return *this;
}
template<class T1, class T2, class T3>
tablica<T1, T2, T3>::tablica(tablica&& b)
{
	y = b.y;
	tab = b.tab;
	b.y = 0;
	b.tab = nullptr;
}
template<class T1, class T2, class T3>
tablica<T1, T2, T3>& tablica<T1, T2, T3>::operator=(tablica&& b)
{
	delete[] tab;
	y = b.y;
	tab = b.tab;
	b.y = 0;
	b.tab = nullptr;
	return *this;
}
template<class T1, class T2, class T3>
tablica<T1, T2, T3>::tablica(size_t y)
{
	this->y = y;
	tab = nullptr;
	if (y == 0) return;
	tab = new tuple<cell<T1>, cell<T2>, cell<T3>>[y];
}
template<class T1, class T2, class T3>
tablica<T1, T2, T3>::~tablica()
{
	delete[] tab;
}
template<class T1, class T2, class T3>
void tablica<T1, T2, T3>::wyswietl()
{
	for (size_t i = 0; i < y; i++)
	{
        cout << get<0>(tab[i]).data << " | ";
        cout << get<1>(tab[i]).data << " | ";
        cout << get<2>(tab[i]).data << " | ";
		cout << endl;
	}
}
template<class T1, class T2, class T3>
template<class rT, int n>
errors tablica<T1, T2, T3>::zmien_wartosc(rT wartosc, size_t index_y)
{
    if(index_y < y)
    {
        get<n>(tab[index_y]).data = wartosc;
        return NO_ERROR;
	}
	else return INDEX_OUT_OF_BOUNDS;
}
template<class T1, class T2, class T3>
void tablica<T1, T2, T3>::zmiana_rozmiaru_tablicy(size_t newy)
{
	tablica newtab(newy);
    for(size_t tempy = 0; tempy < newy; tempy++)
    {
        if(tempy < y)
        {
            newtab.tab[tempy] = tab[tempy];
        }
    }
	*this = move(newtab);
}
template<class T1, class T2, class T3>
errors tablica<T1, T2, T3>::wczytaj(string s)
{
	ifstream plik;
	plik.open(s);
	size_t y;
	if(plik.good())
	{
		plik >> y;
		zmiana_rozmiaru_tablicy(y);
        for (size_t index_y = 0; index_y < y; index_y++)
        {
            plik >> get<0>(tab[index_y]).data;
            plik >> get<1>(tab[index_y]).data;
            plik >> get<2>(tab[index_y]).data;
        }
		return NO_ERROR;
	}
	else
	{
		return INPUT_FILE_ERROR;
	}
}
template<class T1, class T2, class T3>
errors tablica<T1, T2, T3>::zapisz(string s)
{
	ofstream plik;
	plik.open(s);
	if(plik.good())
	{
		plik << y << endl;
        for (size_t index_y = 0; index_y < y; index_y++)
        {
            plik << get<0>(tab[index_y]).data << " ";
            plik << get<1>(tab[index_y]).data << " ";
            plik << get<2>(tab[index_y]).data << endl;
        }
		return NO_ERROR;
	}
	else return OUTPUT_FILE_ERROR;
}

template<class T1, class T2, class T3>
template<class rT, int n>
cell<rT>* tablica<T1, T2, T3>::get_kolumna()
{
	cell<rT>* wyjscie = new cell<rT>[y];
	for (size_t i = 0; i < y; i++)
	{
		wyjscie[i].data = get<n>(tab[i]).data;
	}
	return wyjscie;
}

template<class T1, class T2, class T3>
template<class rT, int n>
rT tablica<T1, T2, T3>::suma_w_kolumnie(errors& e)
{
    if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return rT();
	}
	return cell<rT>::suma(get_kolumna<rT, n>(), y);
}

template<class T1, class T2, class T3>
template<class rT, int n>
rT tablica<T1, T2, T3>::znajdz_srednia_kolumna(errors& e)
{
    if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return rT();
	}
	return cell<rT>::srednia(get_kolumna<rT, n>(), y);
}
template<class T1, class T2, class T3>
template<class rT, int n>
rT tablica<T1, T2, T3>::znajdz_max_kolumna(errors& e)
{
    if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return rT();
	}
	return cell<rT>::max(get_kolumna<rT, n>(), y);
 }
template<class T1, class T2, class T3>
template<class rT, int n>
rT tablica<T1, T2, T3>::znajdz_min_kolumna(errors& e)
{
    if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return rT();
	}
	return cell<rT>::min(get_kolumna<rT, n>(), y);
}
