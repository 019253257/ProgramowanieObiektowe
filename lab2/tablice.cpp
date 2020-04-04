#include<iostream>
#include<fstream>
using namespace std;
double* tworzenie_tablicy(size_t n)
{
	return new double[n];
}

void zmien_wartosc(double* tab, size_t n, double wartosc, size_t index)
{
	if(index<n)
		tab[index]=wartosc;
	else
		cout<<"Indeks poza zakresem"<<endl;
}

void wyswietl(double* tab, size_t n)
{
	for (size_t i=0; i<n; i++)
	cout<<tab[i]<<" | ";
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
