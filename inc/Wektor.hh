#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <cassert>

/*
      Klasa opisuje Wektor o rozmiarze ROZMIAR
      skladowe - kolejne elementy wektora
 */
class Wektor {

    double skladowe[ROZMIAR];
  public:
    double operator [](int i) const { assert(i < ROZMIAR); return skladowe[i]; }      //zwraca wartość i-tej skladowej
    double & operator [](int i) { assert(i < ROZMIAR); return skladowe[i]; }          //zwraca referencję do i-tej składowej
    Wektor operator -(const Wektor & drugi) const;                               //zwraca różnicę dwóch wektorów
    double operator *(const Wektor & drugi) const;                               //zwraca iloczyn dwóch wektorów
    double dlugosc() const;                                                      //zwraca długość wektora

    //Wektor operator +(const Wektor & drugi) const;
    //Wektor operator *(double liczba) const;
    //Wektor operator /(double liczba) const;
};


/*
    Funkcja wczytująca Wektor:
    Dane wejściowe:
      Strm - strumień wejściowy
      Wek - wczytywany Wektor
    Wartość zwracana:
      &Strm
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
    Funkcja wypisująca Wektor:
    Dane wejściowe:
      Strm - strumień wyjściowy
      Wek - wypisywany wektor
    Wartość zwracana:
      &Strm
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
