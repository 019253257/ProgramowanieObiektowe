#include<iostream>
#include<fstream>
#include<string>
#include "tablice.h"
using namespace std;

tablica::tablica()
{
	x = 0;
	y = 0;
	tab = nullptr;
}
tablica::tablica(tablica& b)
{
	x = b.x;
	y = b.y;
	if (b.tab == nullptr)
		tab = nullptr;
	else
	{
		tab = new double*[x];
		for (size_t i = 0; i < x; i++)
			tab[i] = new double[y];
	}
}
tablica& tablica::operator=(tablica& b)
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
		tab = new double*[x];
		for (size_t i = 0; i < x; i++)
			tab[i] = new double[y];
	}
	
	return *this;
}
tablica::tablica(tablica&& b)
{
	x = b.x;
	y = b.y;
	tab = b.tab;
	b.x = 0;
	b.y = 0;
	b.tab = nullptr;
}
tablica& tablica::operator=(tablica&& b)
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
tablica::tablica(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
	tab = nullptr;
	if (x == 0 || y == 0) return;
	tab = new double*[x];
	for (size_t i = 0; i < x; i++)
	{
		tab[i] = new double[y];
		for (size_t j = 0; j < y; j++)
		{
			tab[i][j] = 0;
		}
	}
}
tablica::~tablica()
{
	if (tab != nullptr)
		for (size_t i = 0; i < x; i++)
			delete[] tab[i];
	delete[] tab;
}

void tablica::wyswietl()
{
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			cout << tab[i][j]<<" | ";
		}
		cout << endl;
	}
}

tablica::errors tablica::zmien_wartosc(double wartosc, size_t index_x, size_t index_y)
{
	if(index_x < x){
		if(index_y < y){
			tab[index_x][index_y] = wartosc;
			return tablica::NO_ERROR;
		}
		else return tablica::INDEX_OUT_OF_BOUNDS;
	}
	else return tablica::INDEX_OUT_OF_BOUNDS;
}

void tablica::zmiana_rozmiaru_tablicy(size_t newx, size_t newy)
{
	tablica newtab(newx, newy);
	for(size_t tempx = 0; tempx < newx; tempx++)
	{
		for(size_t tempy = 0; tempy < newy; tempy++)
		{
			if(tempx >= x || tempy >= y){
				newtab.zmien_wartosc(0, tempx, tempy);
			}
			else{
				newtab.zmien_wartosc(tab[tempx][tempy], tempx, tempy);
			}
		}
	}
	*this = move(newtab);
}

tablica::errors tablica::wczytaj(string s)
{
	ifstream plik;
	plik.open(s);
	size_t x;
	size_t y;
	if(plik.good())
	{
		plik >> x >> y;
		zmiana_rozmiaru_tablicy(x, y);
		for(size_t index_x=0; index_x < x; index_x++)
			for (size_t index_y=0; index_y < y; index_y++)
				plik >> tab[index_x][index_y];
		return tablica::NO_ERROR;
	}
	else
	{
		return tablica::INPUT_FILE_ERROR;
	}
}

tablica::errors tablica::zapisz(string s)
{
	ofstream plik;
	plik.open(s);
	if(plik.good())
	{
		plik<<x<<endl<<y<<endl;
			for(size_t index_x=0; index_x < x; index_x++){
				for (size_t index_y=0; index_y < y; index_y++)
					plik<<tab[index_x][index_y]<<" ";
				plik<<endl;
			}
		return tablica::NO_ERROR;
	}
	else return tablica::OUTPUT_FILE_ERROR;
}

void tablica::suma_w_wierszu()
{
    double suma_temp=0;
	for (size_t i=0; i<x; i++){
		for(size_t j=0; j<y;j++){
            suma_temp+=tab[i][j];
        }
        cout<<suma_temp<<endl;
        suma_temp=0;
     }

}

void tablica::suma_w_kolumnie()
{
    double suma_temp=0;
	for (size_t i=0; i<y; i++){
		for(size_t j=0; j<x;j++){
            suma_temp+=tab[j][i];
        }
        cout<<suma_temp<<" | ";
        suma_temp=0;
     }
    cout<<endl;
}

void tablica::znajdz_max_kolumna()
 {
	for (size_t i=0; i<y; i++){
		double max_temp=tab[0][i];
		for(size_t j=0; j<x;j++){
            		if(max_temp<tab[j][i])
            			max_temp=tab[j][i];	
        }
        cout<<max_temp<<" | ";
     }
    cout<<endl;
 }
 
void tablica::znajdz_min_kolumna()
 {
	for (size_t i=0; i<y; i++){
		double min_temp=tab[0][i];
		for(size_t j=0; j<x;j++){
            		if(min_temp>tab[j][i])
            			min_temp=tab[j][i];	
        }
        cout<<min_temp<<" | ";
     }
    cout<<endl;
 }

void tablica::znajdz_max_wiersz()
 {
	for (size_t i=0; i<x; i++){
		double max_temp=tab[i][0];
		for(size_t j=0; j<y;j++){
            		if(max_temp<tab[i][j])
            			max_temp=tab[i][j];	
        }
        cout<<max_temp<<endl;
     }
    cout<<endl;
 }
 
void tablica::znajdz_min_wiersz()
 {
	for (size_t i=0; i<x; i++){
		double min_temp=tab[i][0];
		for(size_t j=0; j<y;j++){
            		if(min_temp>tab[i][j])
            			min_temp=tab[i][j];	
        }
        cout<<min_temp<<endl;
     }
    cout<<endl;
 }
 
 void tablica::znajdz_srednia_kolumna()
 {
 	double suma_temp=0;
	for (size_t i=0; i<y; i++){
		for(size_t j=0; j<x;j++){
            suma_temp+=tab[j][i];
        }
        cout<<suma_temp/x<<" | ";
        suma_temp=0;
     }
    cout<<endl;
 }
 
 void tablica::znajdz_srednia_wiersz()
 {
     double suma_temp=0;
	for (size_t i=0; i<x; i++){
		for(size_t j=0; j<y;j++){
            suma_temp+=tab[i][j];
        }
        cout<<suma_temp/y<<endl;
        suma_temp=0;
     }
 }
