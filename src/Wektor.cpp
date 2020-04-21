#include <cassert>
#include <cmath>
#include "Wektor.hh"


 Wektor Wektor::operator -(const Wektor & drugi) const
 {
    Wektor Roznica;

    for (int i = 0; i < ROZMIAR; i++)
        Roznica.skladowe[i] = skladowe[i] - drugi.skladowe[i];
    
    return Roznica;
}

double Wektor::operator *(const Wektor & drugi) const
 {
    double iloczyn = 0.0;

    for (int i = 0; i < ROZMIAR; i++)
        iloczyn += skladowe[i] * drugi.skladowe[i];
    
    return iloczyn;
}

std::istream & operator >> (std::istream &Strm, Wektor &Wek)
{
    for (int i = 0; i < ROZMIAR; i++)
        Strm >> Wek[i];
    
    return Strm;
}

std::ostream & operator << (std::ostream &Strm, const Wektor &Wek)
{
    for(int i = 0; i < ROZMIAR; i++)
        Strm << Wek[i] << "   ";
    
    Strm << std::endl;

    return Strm;
}

double Wektor::dlugosc() const
{
    return sqrt(*this * *this);
}





/*
Wektor Wektor::operator +(const Wektor & drugi) const
{
    Wektor Suma;

    for (int i = 0; i < ROZMIAR; i++)
        Suma.skladowe[i] = skladowe[i] + drugi.skladowe[i];
    
    return Suma;
}
*/


/*
Wektor Wektor::operator *(double liczba) const
{
    Wektor Wynik;

    for (int i = 0; i < ROZMIAR; i++)
        Wynik.skladowe[i] *= liczba;

    return Wynik;
}

Wektor Wektor::operator /(double liczba) const
{
    assert(liczba != 0);
    
    Wektor Wynik;

    for (int i = 0; i < ROZMIAR; i++)
        Wynik.skladowe[i] /= liczba;

    return Wynik;
}
*/
