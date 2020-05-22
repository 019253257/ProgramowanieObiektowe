#include <iostream>
#include <cstdlib>
#include <string>
#include "tablice.h"
#include "menu.h"
using namespace std;

void wypisz_bledy(errors& bledy)
{
	if (bledy & INDEX_OUT_OF_BOUNDS)
		cout << "Indeks poza zakresem" << endl;
	if (bledy & INPUT_FILE_ERROR)
		cout << "B³¹d pliku wejœcia" << endl;
	if (bledy & OUTPUT_FILE_ERROR)
		cout << "B³¹d pliku wyjœcia" << endl;
	if (bledy & TABLICA_EMPTY)
		cout << "Tablica jest pusta" << endl;
	bledy = NO_ERROR;
}

void menu(){

size_t x, y;
tablica<my_type> tab;

while(1)
{
	int licznik;
	errors e;
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
			tab = tablica<my_type>(x, y);
			break;
		case 2:{
			system("clear");
			size_t newx,newy;
			cout<<"Podaj liczbe wierszy"<<endl;
			cin>>newx;
			cout<<"Podaj liczbe kolumn"<<endl;
			cin>>newy;
			tab.zmiana_rozmiaru_tablicy(newx, newy);
			}
			break;
		case 4:{
			system("clear");
			size_t newx, newy;
			my_type newwart;
			cout<<"Podaj wiersz: ";
			cin>>newx;
			cout<<"Podaj kolumne: ";
			cin>>newy;
			cout<<"Podaj wartosc: ";
			cin>>newwart;
			e = tab.zmien_wartosc(newwart, newx, newy);
			break;
			}

		case 3:	
			system("clear");	
			tab.wyswietl();
			break;
		case 5:{
			system("clear");
			cout<<"Podaj plik: ";
			string s;
			cin.ignore(1024, '\n');
			getline(cin, s);
			e = tab.wczytaj(s);
			break;
			}
		case 6:{
			system("clear");
			cout<<"Podaj plik: ";
			string s;
			cin.ignore(1024, '\n');
			getline(cin, s);
			e = tab.zapisz(s);
			break;
			}
		case 7:
			{
			system("clear");
			int licznik;
			size_t indeks;
			cout<<"1.Sumuj wedlug kolumn"<<endl
			<<"2.Sumuj wedlug wierszy"<<endl;
			cin>>licznik;
			cout<<"Podaj indeks: ";
			cin>>indeks;
			if (licznik == 1) cout << tab.suma_w_kolumnie(indeks, e) << endl;
			else if (licznik == 2) cout << tab.suma_w_wierszu(indeks, e) << endl;
			else cout<<"Nie ma takiej opcji!"<<endl;
			}
			break;
		case 8:
			{
			system("clear");
			int licznik;
			size_t indeks;
			cout<<"1.Max w kolumnie"<<endl
			<<"2.Max w wierszu"<<endl
			<<"3.Min w kolumnie"<<endl
			<<"4.Min w wierszu"<<endl
			<<"5.Srednia w kolumnie"<<endl
			<<"6.Srednia w wierszu"<<endl;
			cin>>licznik;
			cout<<"Podaj indeks: ";
			cin>>indeks;
			if (licznik == 1) cout << tab.znajdz_max_kolumna(indeks, e) << endl;
			else if (licznik == 2) cout << tab.znajdz_max_wiersz(indeks, e) << endl;
			else if (licznik == 3) cout << tab.znajdz_min_kolumna(indeks, e) << endl;
			else if (licznik == 4) cout << tab.znajdz_min_wiersz(indeks, e) << endl;
			else if (licznik == 5) cout << tab.znajdz_srednia_kolumna(indeks, e) << endl;
			else if (licznik == 6) cout << tab.znajdz_srednia_wiersz(indeks, e) << endl;
			else cout<<"Nie ma takiej opcji!"<<endl;
			}
			break;
		
	}
	if (e != NO_ERROR)
				wypisz_bledy(e);
}

}

