#include<iostream>
#include"tablice.h"
using namespace std;
void menu(){
size_t x,y;
double** tab=NULL;
while(1)
{
	int licznik;
	cout<<"1.Stworz tablice"<<endl<<"2.Zmiana rozmiaru tablicy"<<endl<<"3.Wyswietl zawartosc tablicy"<<endl<<"4.Zmien wartosc w tablicy"<<endl<<"5.Wczytaj tablice z pliku"<<endl<<"6.Zapisz tablice do pliku"<<endl<<"0.Zamknij program"<<endl;
	cin>>licznik;
	switch(licznik)
	{
		case 0:
			exit(0);
		case 1:
			cout<<"Podaj liczbe wierszy"<<endl;
			cin>>x;
			cout<<"Podaj liczbe kolumn"<<endl;
			cin>>y;
			tab=tworzenie_tablicy(x,y);
			break;
		case 2:{
			size_t newx,newy;
			cout<<"Podaj liczbe wierszy"<<endl;
			cin>>newx;
			cout<<"Podaj liczbe kolumn"<<endl;
			cin>>newy;
			tab=zmiana_rozmiaru_tablicy(tab,x , y,  newx, newy);
			}
			break;
		case 4:{
			size_t newx, newy;
			double newwart;
			cout<<"Podaj wiersz: ";
			cin>>newx;
			cout<<"Podaj kolumne: ";
			cin>>newy;
			cout<<"Podaj wartosc: ";
			cin>>newwart;
			zmien_wartosc(tab,x,y,newwart, newx, newy);
			}
			break;

		case 3:		
			wyswietl(tab,x,y);
			break;
		case 5:
			tab=wczytaj(x,y);
			break;
		case 6:
			zapisz(x,y,tab);
			break;

	}




}

}
