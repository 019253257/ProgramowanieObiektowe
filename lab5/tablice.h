#pragma once
#include<iostream>
#include<fstream>
#include<string>
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

template<class T>
class tablica
{
	
private:
cell<T>** tab = NULL;
size_t x = 0;
size_t y = 0;

public:
//konstruktory i destrukotry
tablica();
tablica(tablica& b);
tablica<T>& operator=(tablica& b);
tablica(tablica&& b);
tablica<T>& operator=(tablica&& b);
tablica(size_t x, size_t y);
~tablica();

//gettery
size_t get_x() { return x; }
size_t get_y() { return y; }

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
errors zmien_wartosc(T wartosc, size_t index_x, size_t index_y);
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
errors wczytaj(string s);
/*
@param tab - struktura na dane
*/
errors zapisz(string s);
/*

*/
cell<T>* get_wiersz(size_t w);
cell<T>* get_kolumna(size_t k);

/*
@param tab - struktura na dane
*/
T suma_w_wierszu(size_t w, errors& e);
/*
@param tab - struktura na dane
*/
T suma_w_kolumnie(size_t k, errors& e);
/*
@param tab - struktura na dane
*/
T znajdz_srednia_wiersz(size_t w, errors& e);
/*
@param tab - struktura na dane
*/
T znajdz_srednia_kolumna(size_t k, errors& e);
/*
@param tab - struktura na dane
*/
T znajdz_max_kolumna(size_t k, errors& e);
/*
@param tab - struktura na dane
*/
T znajdz_min_kolumna(size_t k, errors& e);
/*
@param tab - struktura na dane
*/
T znajdz_max_wiersz(size_t w, errors& e);
/*
@param tab - struktura na dane
*/
T znajdz_min_wiersz(size_t w, errors& e);

};

template<class T>
tablica<T>::tablica()
{
	x = 0;
	y = 0;
	tab = nullptr;
}
template<class T>
tablica<T>::tablica(tablica& b)
{
	x = b.x;
	y = b.y;
	if (b.tab == nullptr)
		tab = nullptr;
	else
	{
		tab = new T*[x];
		for (size_t i = 0; i < x; i++)
			tab[i] = new T[y];
	}
}
template<class T>
tablica<T>& tablica<T>::operator=(tablica& b)
{
	if (tab != nullptr)
		for (size_t i = 0; i < x; i++)
			delete[] tab[i];
	delete[] tab;
	x = b.x;
	y = b.y;
	if (b.tab == nullptr)
		tab = nullptr;
	else
	{
		tab = new T*[x];
		for (size_t i = 0; i < x; i++)
			tab[i] = new T[y];
	}
	return *this;
}
template<class T>
tablica<T>::tablica(tablica&& b)
{
	x = b.x;
	y = b.y;
	tab = b.tab;
	b.x = 0;
	b.y = 0;
	b.tab = nullptr;
}
template<class T>
tablica<T>& tablica<T>::operator=(tablica&& b)
{
	if (tab != nullptr)
		for (size_t i = 0; i < x; i++)
			delete[] tab[i];
	delete[] tab;
	x = b.x;
	y = b.y;
	tab = b.tab;
	b.x = 0;
	b.y = 0;
	b.tab = nullptr;
	return *this;
}
template<class T>
tablica<T>::tablica(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
	tab = nullptr;
	if (x == 0 || y == 0) return;
	tab = new cell<T>*[x];
	for (size_t i = 0; i < x; i++)
	{
		tab[i] = new cell<T>[y];
		for (size_t j = 0; j < y; j++)
		{
			tab[i][j].data = T();
		}
	}
}
template<class T>
tablica<T>::~tablica()
{
	if (tab != nullptr)
		for (size_t i = 0; i < x; i++)
			delete[] tab[i];
	delete[] tab;
}
template<class T>
void tablica<T>::wyswietl()
{
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			cout << tab[i][j].data << " | ";
		}
		cout << endl;
	}
}
template<class T>
errors tablica<T>::zmien_wartosc(T wartosc, size_t index_x, size_t index_y)
{
	if(index_x < x){
		if(index_y < y){
			tab[index_x][index_y].data = wartosc;
			return NO_ERROR;
		}
		else return INDEX_OUT_OF_BOUNDS;
	}
	else return INDEX_OUT_OF_BOUNDS;
}
template<class T>
void tablica<T>::zmiana_rozmiaru_tablicy(size_t newx, size_t newy)
{
	tablica newtab(newx, newy);
	for(size_t tempx = 0; tempx < newx; tempx++)
	{
		for(size_t tempy = 0; tempy < newy; tempy++)
		{
			if(tempx >= x || tempy >= y){
				newtab.zmien_wartosc(T(), tempx, tempy);
			}
			else{
				newtab.zmien_wartosc(tab[tempx][tempy].data, tempx, tempy);
			}
		}
	}
	*this = move(newtab);
}
template<class T>
errors tablica<T>::wczytaj(string s)
{
	ifstream plik;
	plik.open(s);
	size_t x;
	size_t y;
	T temp;
	if(plik.good())
	{
		plik >> x >> y;
		zmiana_rozmiaru_tablicy(x, y);
		for(size_t index_x=0; index_x < x; index_x++)
			for (size_t index_y=0; index_y < y; index_y++)
			{
				plik >> temp;
				tab[index_x][index_y].data = temp;
			}
		return NO_ERROR;
	}
	else
	{
		return INPUT_FILE_ERROR;
	}
}
template<class T>
errors tablica<T>::zapisz(string s)
{
	ofstream plik;
	plik.open(s);
	if(plik.good())
	{
		plik<<x<<endl<<y<<endl;
			for(size_t index_x = 0; index_x < x; index_x++)
			{
				for (size_t index_y=0; index_y < y; index_y++)
					plik << tab[index_x][index_y].data << " ";
				plik << endl;
			}
		return NO_ERROR;
	}
	else return OUTPUT_FILE_ERROR;
}

template<class T>
cell<T>* tablica<T>::get_wiersz(size_t w)
{
	cell<T>* wyjscie = new cell<T>[y];
	for (int i = 0; i < y; i++)
	{
		wyjscie[i].data = tab[w][i].data;
	}
	return wyjscie;
}
template<class T>
cell<T>* tablica<T>::get_kolumna(size_t k)
{
	cell<T>* wyjscie = new cell<T>[x];
	for (size_t i = 0; i < x; i++)
	{
		wyjscie[i].data = tab[i][k].data;
	}
	return wyjscie;
}

template<class T>
T tablica<T>::suma_w_wierszu(size_t w, errors& e)
{
	if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return T();
	}
	if (w >= x)
	{
		e = INDEX_OUT_OF_BOUNDS;
		return T();
	}
	return cell<T>::suma(get_wiersz(w), y);
}
template<class T>
T tablica<T>::suma_w_kolumnie(size_t k, errors& e)
{
    if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return T();
	}
	if (k >= x)
	{
		e = INDEX_OUT_OF_BOUNDS;
		return T();
	}
	return cell<T>::suma(get_kolumna(k), x);
}

template<class T>
T tablica<T>::znajdz_srednia_wiersz(size_t w, errors& e)
{
	if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return T();
	}
	if (w >= x)
	{
		e = INDEX_OUT_OF_BOUNDS;
		return T();
	}
	return cell<T>::srednia(get_wiersz(w), y);
}
template<class T>
T tablica<T>::znajdz_srednia_kolumna(size_t k, errors& e)
{
    if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return T();
	}
	if (k >= x)
	{
		e = INDEX_OUT_OF_BOUNDS;
		return T();
	}
	return cell<T>::srednia(get_kolumna(k), x);
}
template<class T>
T tablica<T>::znajdz_max_kolumna(size_t k, errors& e)
{
    if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return T();
	}
	if (k >= x)
	{
		e = INDEX_OUT_OF_BOUNDS;
		return T();
	}
	return cell<T>::max(get_kolumna(k), x);
 }
template<class T>
T tablica<T>::znajdz_min_kolumna(size_t k, errors& e)
 {
    if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return T();
	}
	if (k >= x)
	{
		e = INDEX_OUT_OF_BOUNDS;
		return T();
	}
	return cell<T>::min(get_kolumna(k), x);
 }
template<class T>
T tablica<T>::znajdz_max_wiersz(size_t w, errors& e)
 {
	if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return T();
	}
	if (w >= x)
	{
		e = INDEX_OUT_OF_BOUNDS;
		return T();
	}
	return cell<T>::max(get_wiersz(w), y);
 }
template<class T>
T tablica<T>::znajdz_min_wiersz(size_t w, errors& e)
 {
	if (tab == nullptr)
	{
		e = TABLICA_EMPTY;
		return T();
	}
	if (w >= x)
	{
		e = INDEX_OUT_OF_BOUNDS;
		return T();
	}
	return cell<T>::min(get_wiersz(w), y);
 }
 








