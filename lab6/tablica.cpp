#include "tablica.hpp"

Tablica::Tablica()
{
    x = 0;
    y = 0;
    typy_tablicy = nullptr;
    tab = nullptr;
}
Tablica::Tablica(size_t nowy_x, size_t nowy_y, typy* nowe_typy)
{
    if (nowy_x == 0 || nowy_y == 0)
    {
        x = 0;
        y = 0;
        typy_tablicy = nullptr;
        tab = nullptr;
    }
    else
    {
        x = nowy_x;
        y = nowy_y;
        typy_tablicy = new typy[x];
        for (size_t i = 0; i < x; ++i)
            typy_tablicy[i] = nowe_typy[i];
        tab = new Komorka**[x];
        for (size_t i = 0; i < x; ++i)
        {
            tab[i] = new Komorka*[y];
            switch (typy_tablicy[i])
            {
                case typ_int:
                    for (size_t j = 0; j < y; ++j)
                    {
                        tab[i][j] = new KomorkaInt();
                    }
                    break;
                case typ_double:
                    for (size_t j = 0; j < y; ++j)
                    {
                        tab[i][j] = new KomorkaDouble();
                    }
                    break;
                case typ_string:
                    for (size_t j = 0; j < y; ++j)
                    {
                        tab[i][j] = new KomorkaString();
                    }
                    break;
            }
        }
    }
}
void Tablica::usun_stara()
{
    delete [] typy_tablicy;
    for (size_t i = 0; i < x; ++i)
    {
        for (size_t j = 0; j < y; ++j)
            delete tab[i][j];
        delete [] tab[i];
    }
    delete [] tab;
}
void Tablica::skopiuj_nowa(const Tablica& t)
{
    if (t.x == 0 || t.y == 0)
    {
        x = 0;
        y = 0;
        typy_tablicy = nullptr;
        tab = nullptr;
    }
    else
    {
        x = t.x;
        y = t.y;
        typy_tablicy = new typy[x];
        for (size_t i = 0; i < x; ++i)
            typy_tablicy[i] = t.typy_tablicy[i];
        tab = new Komorka**[x];
        for (size_t i = 0; i < x; ++i)
        {
            tab[i] = new Komorka*[y];
            switch (typy_tablicy[i])
            {
                default:
                case typ_int:
                    for (size_t j = 0; j < y; ++j)
                    {
                        tab[i][j] = new KomorkaInt(*t.tab[i][j]);
                    }
                    break;
                case typ_double:
                    for (size_t j = 0; j < y; ++j)
                    {
                        tab[i][j] = new KomorkaDouble(*t.tab[i][j]);
                    }
                    break;
                case typ_string:
                    for (size_t j = 0; j < y; ++j)
                    {
                        tab[i][j] = new KomorkaString(*t.tab[i][j]);
                    }
                    break;
            }
        }
    }
}
void Tablica::przenies_nowa(Tablica& t)
{
    x = t.x;
    y = t.y;
    typy_tablicy = t.typy_tablicy;
    tab = t.tab;
    t.x = 0;
    t.y = 0;
    t.typy_tablicy = nullptr;
    t.tab = nullptr;
}
Tablica::Tablica(const Tablica& t)
{
    skopiuj_nowa(t);
}
Tablica::Tablica(Tablica&& t)
{
    przenies_nowa(t);
}
Tablica& Tablica::operator=(const Tablica& t)
{
    usun_stara();
    skopiuj_nowa(t);
    return *this;
}
Tablica& Tablica::operator=(Tablica&& t)
{
    usun_stara();
    przenies_nowa(t);
    return *this;
}
Tablica::~Tablica()
{
    usun_stara();
}

size_t Tablica::zwroc_x() const
{
    return x;
}
size_t Tablica::zwroc_y() const
{
    return y;
}
typy* Tablica::zwroc_typy(typy* w) const
{
    typy* r = w == nullptr ? new typy[x] : w;
    for (size_t i = 0; i < x; ++i)
    {
        r[i] = typy_tablicy[i];
    }
    return r;
}

Komorka** Tablica::zwroc_kolumne(size_t k) const
{
    if (x == 0 || y == 0)
        throw bledy(TABLICA_JEST_PUSTA);
    if (k >= x)
        throw bledy(INDEKS_POZA_TABLICA);
    Komorka** r = new Komorka*[y];
    for (size_t i = 0; i < y; ++i)
    {
        r[i] = tab[k][i];
    }
    return r;
}
Komorka** Tablica::zwroc_wiersz(size_t w) const
{
    if (x == 0 || y == 0)
        throw bledy(TABLICA_JEST_PUSTA);
    if (w >= y)
        throw bledy(INDEKS_POZA_TABLICA);
    Komorka** r = new Komorka*[x];
    for (size_t i = 0; i < x; ++i)
    {
        r[i] = tab[i][w];
    }
    return r;
}
Komorka& Tablica::zwroc_komorke(size_t indeks_x, size_t indeks_y)
{
    if (x == 0 || y == 0)
        throw bledy(TABLICA_JEST_PUSTA);
    if (indeks_x >= x || indeks_y >= y)
        throw bledy(INDEKS_POZA_TABLICA);
    return *(tab[indeks_x][indeks_y]);
}

void Tablica::wypisz(ostream& out, bool naglowek) const
{
    if (naglowek)
    {
        out << x << " " << y << endl;
        for (size_t i = 0; i < x; ++i)
        {
            out << typy_tablicy[i] << " ";
        }
        out << endl;
    }
    for (size_t j = 0; j < y; ++j)
    {
        if (!naglowek)
            out << "| ";
        for (size_t i = 0; i < x; ++i)
        {
            out << *tab[i][j] << " ";
            if (!naglowek)
                out << "| ";
        }
        out << endl;
    }
}
void Tablica::wczytaj(istream& in)
{
    usun_stara();
    in >> x;
    in >> y;
    if (x == 0 || y == 0)
    {
        x = 0;
        y = 0;
        typy_tablicy = nullptr;
        tab = nullptr;
    }
    else
    {
        typy_tablicy = new typy[x];
        unsigned int temp_typ;
        for (size_t i = 0; i < x; ++i)
        {
            in >> temp_typ;
            typy_tablicy[i] = (typy)temp_typ;
        }
        tab = new Komorka**[x];
        for (size_t i = 0; i < x; ++i)
        {
            tab[i] = new Komorka*[y];
            switch (typy_tablicy[i])
            {
                default:
                case typ_int:
                    for (size_t j = 0; j < y; ++j)
                    {
                        tab[i][j] = new KomorkaInt();
                    }
                    break;
                case typ_double:
                    for (size_t j = 0; j < y; ++j)
                    {
                        tab[i][j] = new KomorkaDouble();
                    }
                    break;
                case typ_string:
                    for (size_t j = 0; j < y; ++j)
                    {
                        tab[i][j] = new KomorkaString();
                    }
                    break;
            }
        }
        for (size_t j = 0; j < y; ++j)
        {
            for (size_t i = 0; i < x; ++i)
            {
                in >> *tab[i][j];
            }
        }
    }
}

void Tablica::zmien_rozmiar(size_t nowy_x, size_t nowy_y, typy* nowe_typy)
{
    if (nowy_x == 0 || nowy_y == 0)
    {
        usun_stara();
        x = 0;
        y = 0;
        typy_tablicy = nullptr;
        tab = nullptr;
    }
    else
    {
        typy* nowe_typy_tablicy = new typy[nowy_x];
        for (size_t i = 0; i < nowy_x; ++i)
            nowe_typy_tablicy[i] = nowe_typy[i];
        Komorka*** nowe_tab = new Komorka**[nowy_x];
        for (size_t i = 0; i < nowy_x; ++i)
        {
            nowe_tab[i] = new Komorka*[nowy_y];
            switch (nowe_typy_tablicy[i])
            {
                case typ_int:
                    for (size_t j = 0; j < nowy_y; ++j)
                    {
                        nowe_tab[i][j] = i < x && j < y ? new KomorkaInt(*tab[i][j]): new KomorkaInt();
                    }
                    break;
                case typ_double:
                    for (size_t j = 0; j < nowy_y; ++j)
                    {
                        nowe_tab[i][j] = i < x && j < y ? new KomorkaDouble(*tab[i][j]): new KomorkaDouble();
                    }
                    break;
                case typ_string:
                    for (size_t j = 0; j < nowy_y; ++j)
                    {
                        nowe_tab[i][j] = i < x && j < y ? new KomorkaString(*tab[i][j]): new KomorkaString();
                    }
                    break;
            }
        }
        usun_stara();
        x = nowy_x;
        y = nowy_y;
        typy_tablicy = nowe_typy_tablicy;
        tab = nowe_tab;
    }
}

double Tablica::policz_min(Komorka** t, size_t n)
{
    double r = t[0] -> wartosc_statystyczna();
    double temp;
    for (size_t i = 1; i < n; ++i)
    {
        temp = t[i] -> wartosc_statystyczna();
        if (temp < r)
        {
            r = temp;
        }
    }
    return r;
}
double Tablica::policz_max(Komorka** t, size_t n)
{
    double r = t[0] -> wartosc_statystyczna();
    double temp;
    for (size_t i = 1; i < n; ++i)
    {
        temp = t[i] -> wartosc_statystyczna();
        if (temp > r)
        {
            r = temp;
        }
    }
    return r;
}
double Tablica::policz_sum(Komorka** t, size_t n)
{
    double r = 0.0;
    for (size_t i = 0; i < n; ++i)
    {
        r += t[i] -> wartosc_statystyczna();
    }
    return r;
}
double Tablica::policz_avg(Komorka** t, size_t n)
{
    return Tablica::policz_sum(t, n) / (double)n;
}
