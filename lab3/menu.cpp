#include<iostream>
#include<cstdlib>
#include"tablice.h"
using namespace std;

void wypisz_bledy(tablica::errors& bledy)
{
	if (bledy & tablica::INDEX_OUT_OF_BOUNDS)
		cout << "Indeks poza zakresem" << endl;
	if (bledy & tablica::INPUT_FILE_ERROR)
		cout << "Błąd pliku wejścia" << endl;
	if (bledy & tablica::OUTPUT_FILE_ERROR)
		cout << "Błąd pliku wyjścia" << endl;
}

void menu(){

size_t x, y;
tablica tab;

while(1)
{
	int licznik;
	tablica::errors e;
	cout<<"1.Stworz tablice"<<endl
	<<"2.Zmiana rozmiaru tablicy"<<endl
	<<"3.Wyswietl zawartosc tablicy"<<endl
	<<"4.Zmien wartosc w tablicy"<<endl
	<<"5.Wczytaj tablice z pliku"<<endl
	<<"6.Zapisz tablice do pliku"<<endl
	<<"7.Sumuj wedlug"<<endl
	<<"8.Znajdz"<<endl
	<<"0.Zamknij program"<<endl;
	
	cin>>licznik;
	switch(licznik)
	{
		case 0:
			system("clear");
			exit(0);
		case 1:
			system("clear");
			cout<<"Podaj liczbe wierszy"<<endl;
			cin>>x;
			cout<<"Podaj liczbe kolumn"<<endl;
			cin>>y;
			tab=tworzenie_tablicy(x,y);
			break;
		case 2:{
			system("clear");
			size_t newx,newy;
			cout<<"Podaj liczbe wierszy"<<endl;
			cin>>newx;
			cout<<"Podaj liczbe kolumn"<<endl;
			cin>>newy;
			tab=zmiana_rozmiaru_tablicy(tab, newx, newy);
			}
			break;
		case 4:{
			system("clear");
			size_t newx, newy;
			double newwart;
			cout<<"Podaj wiersz: ";
			cin>>newx;
			cout<<"Podaj kolumne: ";
			cin>>newy;
			cout<<"Podaj wartosc: ";
			cin>>newwart;
			zmien_wartosc(tab,newwart, newx, newy, e);
			break;
			}

		case 3:	
			system("clear");	
			wyswietl(tab);
			break;
		case 5:
			system("clear");
			tab=wczytaj(x,y,e);
			break;
		case 6:
			system("clear");
			zapisz(tab,e);
			break;
		case 7:
			{
			system("clear");
			int licznik;
			cout<<"1.Sumuj wedlug kolumn"<<endl
			<<"2.Sumuj wedlug wierszy"<<endl;
			cin>>licznik;
			if (licznik == 1) suma_w_kolumnie(tab);
			else if (licznik == 2) suma_w_wierszu(tab);
			else cout<<"Nie ma takiej opcji!"<<endl;
			}
			break;
		case 8:
			{
			system("clear");
			int licznik;
			cout<<"1.Max w kolumnie"<<endl
			<<"2.Max w wierszu"<<endl
			<<"3.Min w kolumnie"<<endl
			<<"4.Min w wierszu"<<endl
			<<"5.Srednia w kolumnie"<<endl
			<<"6.Srednia w wierszu"<<endl;
			cin>>licznik;
			if (licznik == 1) znajdz_max_kolumna(tab);
			else if (licznik == 2) znajdz_max_wiersz(tab);
			else if (licznik == 3) znajdz_min_kolumna(tab);
			else if (licznik == 4) znajdz_min_wiersz(tab);
			else if (licznik == 5) znajdz_srednia_kolumna(tab);
			else if (licznik == 6) znajdz_srednia_wiersz(tab);
			else cout<<"Nie ma takiej opcji!"<<endl;
			}
			break;
		
	}
	if (e != tablica::NO_ERROR)
				wypisz_bledy(e);
			




}

}
