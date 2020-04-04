#include<iostream>
#include<fstream>
using namespace std;
double** tworzenie_tablicy(size_t x, size_t y)
{
	double** tab= new double*[x];
	for (size_t i = 0;i<x;i++)
		tab[i]=new double [y];
	return tab;
	
}

void zmien_wartosc(double** tab, size_t x,size_t y, double wartosc, size_t index_x, size_t index_y)
{
	if(index_x<x){
		if(index_y<y){
			tab[index_x][index_y] = wartosc;
		}
	}

	else
		cout<<"Indeks poza zakresem"<<endl;
}

void wyswietl(double** tab, size_t x, size_t y)
{
	for (size_t i=0; i<x; i++){
		for (size_t j=0; j<y; j++)
			cout<<tab[i][j]<<" | ";
		cout<<endl;
	}		
}

double* zmiana_rozmiaru_tablicy(double* tab, size_t n, size_t newn)
{
	size_t tempn = n;
	if (newn < n) tempn = newn;
	double* newtab = new double[newn];
	for (size_t i = 0; i < tempn; i++) newtab[i] = tab[i];
	delete[] tab;
	return newtab;
}

double** wczytaj()
{
ifstream plik;
plik.open("dane.txt");
if(plik.good()==1){
size_t x,y;
plik>>x>>y;
double** tab = tworzenie_tablicy(x,y);
for(size_t index_x=0; index_x < x; index_x++)
	for (size_t index_y=0; index_y < y; index_y++)
		plik>>tab[index_x][index_y];
return tab; 
}
else {
	cout<<"Blad pliku wejscia!"<<endl;
}
return NULL;
} 