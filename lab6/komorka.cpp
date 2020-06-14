#include "komorka.hpp"

Komorka::~Komorka()
{
}

istream& operator>>(istream& in, Komorka& k)
{
    k.czytaj(in);
    return in;
}
ostream& operator<<(ostream& out, const Komorka& k)
{
    k.pisz(out);
    return out;
}

double KomorkaInt::wartosc_statystyczna() const
{
    return wartosc;
}
double KomorkaDouble::wartosc_statystyczna() const
{
    return wartosc;
}
double KomorkaString::wartosc_statystyczna() const
{
    throw bledy(NIE_MA_WARTOSCI_STATYSTYCZNEJ);
    return 0.0;
}

void KomorkaInt::pisz(ostream& out) const
{
    out << wartosc;
    if (!out.good())
        throw bledy(ZLY_STAN_STRUMIENIA);
}
void KomorkaDouble::pisz(ostream& out) const
{
    out << wartosc;
    if (!out.good())
        throw bledy(ZLY_STAN_STRUMIENIA);
}
void KomorkaString::pisz(ostream& out) const
{
    out << wartosc;
    if (!out.good())
        throw bledy(ZLY_STAN_STRUMIENIA);
}

void KomorkaInt::czytaj(istream& in)
{
    in >> wartosc;
    if (!in.good())
        throw bledy(ZLY_STAN_STRUMIENIA);
}
void KomorkaDouble::czytaj(istream& in)
{
    in >> wartosc;
    if (!in.good())
        throw bledy(ZLY_STAN_STRUMIENIA);
}
void KomorkaString::czytaj(istream& in)
{
    in >> wartosc;
    if (!in.good())
        throw bledy(ZLY_STAN_STRUMIENIA);
}
