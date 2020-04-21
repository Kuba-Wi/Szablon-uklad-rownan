#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>


/*
    Klasa opisuje Macierz kwadratową o rozmiarze ROZMIARxROZMIAR.
    kolumny - kolejne kolumny składowe Macierzy
 */
class Macierz {

    Wektor kolumny[ROZMIAR];
    void zamien_kolumny(unsigned int a, unsigned int b);            //zamienia kolumne a z kolumna b
  public:
    double & operator ()(unsigned int a, unsigned int b);           //zwraca referencję do elementu Mac(a,b)
    double operator ()(unsigned int a, unsigned int b) const;       //zwraca wartość do elementu Mac(a,b)
    double wyznacznik() const;                                      //zwraca wyznacznik Macierzy
    Wektor operator *(const Wektor & Wek) const;                    //zwraca wektor wynikowy mnożenia macierzy przez wektor
    Macierz wstaw_kolumne(const Wektor & Wek, unsigned int kolumna) const;   //zwraca macierz po zamianie
                                                                             //kolumny 'kolumna' Macierzy z wektorem Wek 

};


/*
    Funkcja wczytująca Macierz:
    Dane wejściowe:
      Strm - strumień wejściowy
      Mac - wczytywana macierz
    Wartość zwracana:
      &Strm
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
    Funkcja wypisująca Macierz:
    Dane wejściowe:
      Strm - strumień wyjściowy
      Mac - wypisywana macierz
    Wartość zwracana:
      &Strm
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
