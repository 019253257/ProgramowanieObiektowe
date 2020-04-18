#include<iostream>
#include<fstream>
using namespace std;
struct tablica
{
double** tab = NULL;
size_t x = 0;
size_t y = 0;
};
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

void zmien_wartosc(tablica tab, double wartosc, size_t index_x, size_t index_y)
{
	if(index_x<tab.x){
		if(index_y<tab.y){
			tab.tab[index_x][index_y] = wartosc;
		}
	}

	else{
		cout<<"Indeks poza zakresem"<<endl;
	}
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

tablica wczytaj(size_t &x, size_t &y)
{
	ifstream plik;
	plik.open("dane.txt");
	if(plik.good()==1){
	plik>>x>>y;
	tablica tab = tworzenie_tablicy(x,y);
	for(size_t index_x=0; index_x < x; index_x++)
		for (size_t index_y=0; index_y < y; index_y++)
			plik>>tab.tab[index_x][index_y];
	return tab; 
	}
	else {
		cout<<"Blad pliku wejscia!"<<endl;
	}
	;
} 

void zapisz(tablica tab)
{
	ofstream plik;
	plik.open("wyjscie.txt");
	if(plik.good()==1){
		plik<<tab.x<<endl<<tab.y<<endl;
			for(size_t index_x=0; index_x < tab.x; index_x++){
				for (size_t index_y=0; index_y < tab.y; index_y++)
					plik<<tab.tab[index_x][index_y]<<" ";
				plik<<endl;
			} 
	}
	else 
		cout<<"Blad pliku wyjscia!"<<endl;
} 
