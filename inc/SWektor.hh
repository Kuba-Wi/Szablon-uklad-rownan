#ifndef SWEKTOR_HH
#define SWEKTOR_HH

#include <iostream>
#include <cassert>
#include <cmath>
#include "rozmiar.h"
#include "LZespolona.hh"

/*
      Klasa opisuje Wektor o rozmiarze ROZMIAR
      skladowe - kolejne elementy wektora
 */
template<typename Typ, int Rozmiar>
class SWektor {

    Typ skladowe[Rozmiar];
    //Typ operator *(const SWektor<Typ, Rozmiar> & drugi) const;
  public:
    Typ operator [](int i) const { assert(i < Rozmiar); return skladowe[i]; }      //zwraca wartość i-tej skladowej
    Typ & operator [](int i) { assert(i < Rozmiar); return skladowe[i]; }          //zwraca referencję do i-tej składowej
    SWektor<Typ, Rozmiar> operator -(const SWektor<Typ, Rozmiar> & drugi) const;                               //zwraca różnicę dwóch wektorów
    double dlugosc() const;                                                      //zwraca długość wektora

    //Wektor operator +(const Wektor & drugi) const;
    SWektor<Typ, Rozmiar> operator *(Typ liczba) const;
    //Wektor operator /(double liczba) const;
};

template<typename Typ, int Rozmiar>
SWektor<Typ, Rozmiar> SWektor<Typ, Rozmiar>::operator -(const SWektor<Typ, Rozmiar> & drugi) const {

    SWektor<Typ, Rozmiar> Roznica;

    for (int i = 0; i < Rozmiar; i++)
        Roznica.skladowe[i] = skladowe[i] - drugi.skladowe[i];
    
    return Roznica;
}

/*
template<typename Typ, int Rozmiar>
Typ SWektor<Typ, Rozmiar>::operator *(const SWektor<Typ, Rozmiar> & drugi) const {
    Typ iloczyn = 0;

    for (int i = 0; i < Rozmiar; i++)
        iloczyn += skladowe[i] * drugi.skladowe[i];
    
    return iloczyn;
}
*/
template<typename Typ, int Rozmiar>
SWektor<Typ, Rozmiar> SWektor<Typ, Rozmiar>::operator *(Typ liczba) const
{
    SWektor<Typ, Rozmiar> Wynik;

    for (int i = 0; i < Rozmiar; i++)
        Wynik.skladowe[i] = skladowe[i] * liczba;

    return Wynik;
}

template<typename Typ, int Rozmiar>
double SWektor<Typ, Rozmiar>::dlugosc() const
{
    double Wynik = 0;
    for(int i = 0; i < Rozmiar; i++)
        Wynik += skladowe[i] * skladowe[i];
    
    return sqrt(Wynik);
}

template<>
double SWektor<LZespolona, ROZMIAR>::dlugosc() const
{
    double Wynik = 0;
    for(int i = 0; i < ROZMIAR; i++)
        Wynik += skladowe[i].Modul2();
    
    return sqrt(Wynik);
}


/*
    Funkcja wczytująca Wektor:
    Dane wejściowe:
      Strm - strumień wejściowy
      Wek - wczytywany Wektor
    Wartość zwracana:
      &Strm
 */
template<typename Typ, int Rozmiar>
std::istream& operator >> (std::istream &Strm, SWektor<Typ, Rozmiar> &Wek) {

    for (int i = 0; i < Rozmiar; i++)
        Strm >> Wek[i];
    
    return Strm;
}

/*
    Funkcja wypisująca Wektor:
    Dane wejściowe:
      Strm - strumień wyjściowy
      Wek - wypisywany wektor
    Wartość zwracana:
      &Strm
 */
template<typename Typ, int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const SWektor<Typ, Rozmiar> &Wek) {

    for(int i = 0; i < Rozmiar; i++)
        Strm << Wek[i] << "   ";
    
    Strm << std::endl;

    return Strm;
}

#endif