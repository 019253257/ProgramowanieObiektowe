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

size_t y;
tablica<my_type1, my_type2, my_type3> tab;

while(1)
{
	int licznik;
	errors e = NO_ERROR;
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
			cin>>y;
			tab = tablica<my_type1, my_type2, my_type3>(y);
			break;
		case 2:{
			system("clear");
			size_t newy;
			cout<<"Podaj liczbe wierszy"<<endl;
			cin>>newy;
			tab.zmiana_rozmiaru_tablicy(newy);
			}
			break;
		case 4:{
			system("clear");
			size_t newx, newy;
            cout<<"Podaj wiersz: ";
			cin>>newy;
			cout<<"Podaj kolumne: ";
			cin>>newx;
            switch (newx)
            {
            case 0:
                {
                    my_type1 newwart;
                    cout<<"Podaj wartosc: ";
                    cin>>newwart;
                    e = tab.zmien_wartosc<my_type1, 0>(newwart, newy);
                    break;
                }
            case 1:
                {
                    my_type2 newwart;
                    cout<<"Podaj wartosc: ";
                    cin>>newwart;
                    e = tab.zmien_wartosc<my_type2, 1>(newwart, newy);
                    break;
                }
            case 2:
                {
                    my_type3 newwart;
                    cout<<"Podaj wartosc: ";
                    cin>>newwart;
                    e = tab.zmien_wartosc<my_type3, 2>(newwart, newy);
                    break;
                }
            default: e = INDEX_OUT_OF_BOUNDS;
            }

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
			size_t indeks;
			cout<<"Podaj indeks: ";
			cin>>indeks;
			switch (indeks)
            {
            case 0:
                cout << tab.suma_w_kolumnie<my_type1, 0>(e) << endl;
                break;
            case 1:
                cout << tab.suma_w_kolumnie<my_type2, 1>(e) << endl;
                break;
            case 2:
                cout << tab.suma_w_kolumnie<my_type3, 2>(e) << endl;
                break;
            default: e = INDEX_OUT_OF_BOUNDS;
            }
            break;
			}
		case 8:
			{
			system("clear");
			int licznik;
			size_t indeks;
			cout<<"1.Max"<<endl
			<<"2.Min"<<endl
			<<"3.Srednia"<<endl;
			cin>>licznik;
			cout<<"Podaj indeks: ";
			cin>>indeks;
			switch (indeks)
            {
            case 0:
                switch (licznik)
                {
                case 1:
                    cout << tab.znajdz_max_kolumna<my_type1, 0>(e) << endl;
                    break;
                case 2:
                    cout << tab.znajdz_min_kolumna<my_type1, 0>(e) << endl;
                    break;
                case 3:
                    cout << tab.znajdz_srednia_kolumna<my_type1, 0>(e) << endl;
                    break;
                }
                break;
            case 1:
                switch (licznik)
                {
                case 1:
                    cout << tab.znajdz_max_kolumna<my_type2, 1>(e) << endl;
                    break;
                case 2:
                    cout << tab.znajdz_min_kolumna<my_type2, 1>(e) << endl;
                    break;
                case 3:
                    cout << tab.znajdz_srednia_kolumna<my_type2, 1>(e) << endl;
                    break;
                }
                break;
            case 2:
                switch (licznik)
                {
                case 1:
                    cout << tab.znajdz_max_kolumna<my_type3, 2>(e) << endl;
                    break;
                case 2:
                    cout << tab.znajdz_min_kolumna<my_type3, 2>(e) << endl;
                    break;
                case 3:
                    //UWAGA: double zamiast my_type3 pozwala na uzyskanie średniej z integerów w postaci doubla!
                    cout << tab.znajdz_srednia_kolumna<double, 2>(e) << endl;
                    break;
                }
                break;
            default: e = INDEX_OUT_OF_BOUNDS;
            }
            break;
			}

	}
	if (e != NO_ERROR)
				wypisz_bledy(e);
}

}

