#include "menu.hpp"

void pisz_bledy(ostream& out, bledy b)
{
    if (b & NIE_MA_WARTOSCI_STATYSTYCZNEJ)
        out << "Próba uzyskania wartości natrafiła na komórkę dla której nie można uzyskać wartości statystycznej" << endl;
    if (b & ZLY_STAN_STRUMIENIA)
        out << "Operacja na strumieniu zakończyła się jego niepoprawnym stanem" << endl;
    if (b & INDEKS_POZA_TABLICA)
        out << "Indeks operacji leży poza tablicą" << endl;
    if (b & TABLICA_JEST_PUSTA)
        out << "Tablica jest pusta" << endl;
    if (b & BLAD_ODCZYTU_PLIKU)
        out << "Otwarcie pliku do odczytu nie powiodło się" << endl;
    if (b & BLAD_ZAPISU_PLIKU)
        out << "Otwarcie pliku do zapisu nie powiodło się" << endl;
    if (b & NIEZNANE_POLECENIE)
        out << "Nieznane polecenie" << endl;
}

void nowa_tablica(Tablica& t)
{
    size_t nowy_x;
    size_t nowy_y;
    typy* nowe_typy;
    unsigned int temp;
    cout << "Podaj nową szerokość:" << endl;
    cin >> nowy_x;
    cout << "Podaj nową wysokość:" << endl;
    cin >> nowy_y;
    nowe_typy = new typy[nowy_x];
    if (nowy_x > 0)
    {
        cout << "1. integer" << endl;
        cout << "2. double" << endl;
        cout << "3. string" << endl;
        for (size_t i = 0; i < nowy_x; ++i)
        {
            cout << "Podaj typ dla kolumny " << i << ":" << endl;
            cin >> temp;
            if (temp < 1 || temp > 3)
            {
                delete [] nowe_typy;
                throw bledy(NIEZNANE_POLECENIE);
            }
            nowe_typy[i] = typy(temp);
        }
    }
    t = Tablica(nowy_x, nowy_y, nowe_typy);
}
void zmien_rozmiar(Tablica& t)
{
    size_t nowy_x;
    size_t nowy_y;
    unsigned int temp;
    typy* nowe_typy;
    cout << "Podaj nową szerokość:" << endl;
    cin >> nowy_x;
    cout << "Podaj nową wysokość:" << endl;
    cin >> nowy_y;
    nowe_typy = t.zwroc_typy(new typy[max(nowy_x, t.zwroc_x())]);
    if (nowy_x > t.zwroc_x())
    {
        cout << "1. integer" << endl;
        cout << "2. double" << endl;
        cout << "3. string" << endl;
        for (size_t i = t.zwroc_x(); i < nowy_x; ++i)
        {
            cout << "Podaj typ dla kolumny " << i << ":" << endl;
            cin >> temp;
            if (temp < 1 || temp > 3)
            {
                delete [] nowe_typy;
                throw bledy(NIEZNANE_POLECENIE);
            }
            nowe_typy[i] = typy(temp);
        }
    }
    t.zmien_rozmiar(nowy_x, nowy_y, nowe_typy);
    delete [] nowe_typy;
}
void wyswietl(Tablica& t)
{
    t.wypisz(cout);
}
void zmien_wartosc(Tablica& t)
{
    size_t x;
    size_t y;
    cout << "Podaj kolumnę:" << endl;
    cin >> x;
    cout << "Podaj wiersz:" << endl;
    cin >> y;
    cout << "Podaj nową wartość:" << endl;
    cin >> t.zwroc_komorke(x, y);
}
void wczytaj(Tablica& t)
{
    string nazwa_pliku;
    cout << "Podaj nazwę pliku:" << endl;
    cin >> nazwa_pliku;
    ifstream plik(nazwa_pliku);
    if (!plik.good())
        throw bledy(BLAD_ODCZYTU_PLIKU);
    t.wczytaj(plik);
    plik.close();
}
void zapisz(Tablica& t)
{
    string nazwa_pliku;
    cout << "Podaj nazwę pliku:" << endl;
    cin >> nazwa_pliku;
    ofstream plik(nazwa_pliku);
    if (!plik.good())
        throw bledy(BLAD_ZAPISU_PLIKU);
    t.wypisz(plik, true);
    plik.close();
}
void szukaj(Tablica& t)
{
    unsigned int tryb;
    unsigned int indeks;
    size_t n;
    double wynik;
    Komorka** temp = nullptr;
    cout << "1. Suma według kolumny" << endl;
    cout << "2. Suma według wiersza" << endl;
    cout << "3. Średnia według kolumny" << endl;
    cout << "4. Średnia według wiersza" << endl;
    cout << "5. Min według kolumny" << endl;
    cout << "6. Min według wiersza" << endl;
    cout << "7. Max według kolumny" << endl;
    cout << "8. Max według wiersza" << endl;
    cout << "Wybierz kryterium:" << endl;
    cin >> tryb;
    if (tryb < 1 || tryb > 8)
        throw bledy(NIEZNANE_POLECENIE);
    cout << "Podaj indeks operacji:" << endl;
    cin >> indeks;
    try
    {
        if (tryb % 2 == 1)
        {
            temp = t.zwroc_kolumne(indeks);
            n = t.zwroc_y();
        }
        else
        {
            temp = t.zwroc_wiersz(indeks);
            n = t.zwroc_x();
        }
        switch(tryb)
        {
            case 1: case 2:
                wynik = Tablica::policz_sum(temp, n);
                cout << "Suma wynosi: " << wynik << endl;
                break;
            case 3: case 4:
                wynik = Tablica::policz_avg(temp, n);
                cout << "Średnia wynosi: " << wynik << endl;
                break;
            case 5: case 6:
                wynik = Tablica::policz_min(temp, n);
                cout << "Min wynosi: " << wynik << endl;
                break;
            case 7: case 8:
                wynik = Tablica::policz_max(temp, n);
                cout << "Max wynosi " << wynik << endl;
                break;
            default:
                throw bledy(NIEZNANE_POLECENIE);
        }
        delete [] temp;
    }
    catch (bledy b)
    {
        delete [] temp;
        throw b;
    }
}

void obsluz(Tablica& tab, unsigned int polecenie)
{
    switch (polecenie)
    {
        case 1:
            return nowa_tablica(tab);
        case 2:
            return zmien_rozmiar(tab);
        case 3:
            return wyswietl(tab);
        case 4:
            return zmien_wartosc(tab);
        case 5:
            return wczytaj(tab);
        case 6:
            return zapisz(tab);
        case 7:
            return szukaj(tab);
        case 0:
            return;
        default:
            throw bledy(NIEZNANE_POLECENIE);
    }
}

void menu()
{
    Tablica tab;
    unsigned int polecenie;
    do
    {
        cout << "1. Stworz tablice" << endl;
        cout << "2. Zmiana rozmiaru tablicy" << endl;
        cout << "3. Wyswietl zawartosc tablicy" << endl;
        cout << "4. Zmien wartosc w tablicy" << endl;
        cout << "5. Wczytaj tablice z pliku" << endl;
        cout << "6. Zapisz tablice do pliku" << endl;
        cout << "7. Znajdz" << endl;
        cout << "0. Zamknij program" << endl;
        cout << endl;
        cout << "> ";
        cin >> polecenie;
        cout << endl;
        //system("clear");
        try
        {
            obsluz(tab, polecenie);
        }
        catch (bledy e)
        {
            pisz_bledy(cout, e);
            if (!cin.good())
            {
                cin.clear();
                cin.ignore(1024, '\n');
            }
        }
        cout << endl;
    }
    while (polecenie != 0);
}
