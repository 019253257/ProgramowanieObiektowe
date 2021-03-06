#include<iostream>
#include<fstream>
#include "tablice.h"
using namespace std;

tablica tworzenie_tablicy(size_t x, size_t y)
{
	tablica tab;
	tab.x=x;
	tab.y=y;
	tab.tab= new double*[x];
	for (size_t i = 0;i<x;i++){
		tab.tab[i]=new double [y];
	}
	return tab;
}

void zmien_wartosc(tablica tab, double wartosc, size_t index_x, size_t index_y, tablica::errors& bledy)
{
	bledy = tablica::NO_ERROR;
	if(index_x<tab.x){
		if(index_y<tab.y){
			tab.tab[index_x][index_y] = wartosc;
		}
	}
	else bledy = tablica::INDEX_OUT_OF_BOUNDS;
}

void wyswietl(tablica tab)
{
	for (size_t i=0; i<tab.x; i++){
		for (size_t j=0; j<tab.y; j++){
			cout<<tab.tab[i][j]<<" | ";
		}
		cout<<endl;
	}
}

tablica zmiana_rozmiaru_tablicy(tablica tab, size_t newx, size_t newy)
{
	tablica newtab=tworzenie_tablicy(newx,newy);
	for(size_t tempx=0; tempx<newx; tempx++)
	{
		for(size_t tempy=0; tempy<newy; tempy++){
			if(tempx>=tab.x || tempy>=tab.y){
				newtab.tab[tempx][tempy]=0;
			}
			else{
				newtab.tab[tempx][tempy]=tab.tab[tempx][tempy];
			}
		}
	}
	if (tab.tab != NULL) for (size_t tempx=0; tempx < tab.x; tempx++) delete[] tab.tab[tempx];
	delete[] tab.tab;
	return newtab;
}

tablica wczytaj(size_t &x, size_t &y, tablica::errors& bledy)
{
	bledy = tablica::NO_ERROR;
	ifstream plik;
	plik.open("dane.txt");
	if(plik.good()){
	plik>>x>>y;
	tablica tab = tworzenie_tablicy(x,y);
	for(size_t index_x=0; index_x < x; index_x++)
		for (size_t index_y=0; index_y < y; index_y++)
			plik>>tab.tab[index_x][index_y];
	return tab;
	}
	else
	{
	bledy = tablica::INPUT_FILE_ERROR;
	tablica tab = tworzenie_tablicy(1,1);
	return tab;
	}
}

void zapisz(tablica tab, tablica::errors& bledy)
{
	bledy = tablica::NO_ERROR;
	ofstream plik;
	plik.open("wyjscie.txt");
	if(plik.good()){
		plik<<tab.x<<endl<<tab.y<<endl;
			for(size_t index_x=0; index_x < tab.x; index_x++){
				for (size_t index_y=0; index_y < tab.y; index_y++)
					plik<<tab.tab[index_x][index_y]<<" ";
				plik<<endl;
			}
	}
	else bledy = tablica::OUTPUT_FILE_ERROR;
}
void suma_w_wierszu(tablica tab)
{
    double suma_temp=0;
	for (size_t i=0; i<tab.x; i++){
		for(size_t j=0; j<tab.y;j++){
            suma_temp+=tab.tab[i][j];
        }
        cout<<suma_temp<<endl;
        suma_temp=0;
     }

}

void suma_w_kolumnie(tablica tab)
{
    double suma_temp=0;
	for (size_t i=0; i<tab.y; i++){
		for(size_t j=0; j<tab.x;j++){
            suma_temp+=tab.tab[j][i];
        }
        cout<<suma_temp<<" | ";
        suma_temp=0;
     }
    cout<<endl;
}

void znajdz_max_kolumna(tablica tab)
 {
	for (size_t i=0; i<tab.y; i++){
		double max_temp=tab.tab[0][i];
		for(size_t j=0; j<tab.x;j++){
            		if(max_temp<tab.tab[j][i])
            			max_temp=tab.tab[j][i];	
        }
        cout<<max_temp<<" | ";
     }
    cout<<endl;
 }
 
void znajdz_min_kolumna(tablica tab)
 {
	for (size_t i=0; i<tab.y; i++){
		double min_temp=tab.tab[0][i];
		for(size_t j=0; j<tab.x;j++){
            		if(min_temp>tab.tab[j][i])
            			min_temp=tab.tab[j][i];	
        }
        cout<<min_temp<<" | ";
     }
    cout<<endl;
 }

void znajdz_max_wiersz(tablica tab)
 {
	for (size_t i=0; i<tab.x; i++){
		double max_temp=tab.tab[i][0];
		for(size_t j=0; j<tab.y;j++){
            		if(max_temp<tab.tab[i][j])
            			max_temp=tab.tab[i][j];	
        }
        cout<<max_temp<<endl;
     }
    cout<<endl;
 }
 
void znajdz_min_wiersz(tablica tab)
 {
	for (size_t i=0; i<tab.x; i++){
		double min_temp=tab.tab[i][0];
		for(size_t j=0; j<tab.y;j++){
            		if(min_temp>tab.tab[i][j])
            			min_temp=tab.tab[i][j];	
        }
        cout<<min_temp<<endl;
     }
    cout<<endl;
 }
 
 void znajdz_srednia_kolumna(tablica tab)
 {
 	double suma_temp=0;
	for (size_t i=0; i<tab.y; i++){
		for(size_t j=0; j<tab.x;j++){
            suma_temp+=tab.tab[j][i];
        }
        cout<<suma_temp/tab.x<<" | ";
        suma_temp=0;
     }
    cout<<endl;
 }
 
 void znajdz_srednia_wiersz(tablica tab)
 {
     double suma_temp=0;
	for (size_t i=0; i<tab.x; i++){
		for(size_t j=0; j<tab.y;j++){
            suma_temp+=tab.tab[i][j];
        }
        cout<<suma_temp/tab.y<<endl;
        suma_temp=0;
     }
 }
