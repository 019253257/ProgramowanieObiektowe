#ifndef komorka_hpp
#define komorka_hpp

#include <iostream>
#include <string>
using namespace std;

enum typy: unsigned int
{
    typ_int = 1,
    typ_double = 2,
    typ_string = 3
};

enum bledy: unsigned int
{
    BEZ_BLEDU = 1,
    NIE_MA_WARTOSCI_STATYSTYCZNEJ = 2,
    ZLY_STAN_STRUMIENIA = 4,
    INDEKS_POZA_TABLICA = 8,
    TABLICA_JEST_PUSTA = 16,
    BLAD_ODCZYTU_PLIKU = 32,
    BLAD_ZAPISU_PLIKU = 64,
    NIEZNANE_POLECENIE = 128
};

class Komorka
{
public:
    Komorka(){}
    virtual ~Komorka() = 0;
    friend istream& operator>>(istream& in, Komorka& k);
    friend ostream& operator<<(ostream& out, const Komorka& k);
    virtual double wartosc_statystyczna() const = 0;
private:
    virtual void czytaj(istream& in) = 0;
    virtual void pisz(ostream& out) const = 0;
};

class KomorkaInt: public Komorka
{
public:
    KomorkaInt(): wartosc(0){}
    KomorkaInt(const Komorka& k): wartosc(((KomorkaInt*)&k)->wartosc){};
    KomorkaInt(const KomorkaInt& k): wartosc(k.wartosc){};
    virtual double wartosc_statystyczna() const;
private:
    virtual void czytaj(istream& in);
    virtual void pisz(ostream& out) const;
    int wartosc;
};

class KomorkaDouble: public Komorka
{
public:
    KomorkaDouble(): wartosc(0.0){}
    KomorkaDouble(const Komorka& k): wartosc(((KomorkaDouble*)&k)->wartosc){};
    KomorkaDouble(const KomorkaDouble& k): wartosc(k.wartosc){};
    virtual double wartosc_statystyczna() const;
private:
    virtual void czytaj(istream& in);
    virtual void pisz(ostream& out) const;
    double wartosc;
};

class KomorkaString: public Komorka
{
public:
    KomorkaString(): wartosc("N/A"){}
    KomorkaString(const Komorka& k): wartosc(((KomorkaString*)&k)->wartosc){};
    KomorkaString(const KomorkaString& k): wartosc(k.wartosc){};
    virtual double wartosc_statystyczna() const;
private:
    virtual void czytaj(istream& in);
    virtual void pisz(ostream& out) const;
    string wartosc;
};

#endif /* komorka_hpp */
