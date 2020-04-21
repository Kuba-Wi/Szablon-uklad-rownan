#ifndef SUKLADROWNANLINIOWYCH_HH
#define SUKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "SMacierz.hh"
#include "SWektor.hh"

/*
      Klasa opisuje uklad równań złożony z macierzy kwadratowej
      i wektora wyrazów wolnych
      Pola:
      A - Macierz kwadratowa współczynników
      b - Wektor wyrazów wolnych
 */
template<typename Typ, int Rozmiar>
class SUkladRownanLiniowych {
  
    SMacierz<Typ, Rozmiar> A;
    SWektor<Typ, Rozmiar> b;
  public:
    SUkladRownanLiniowych() {}                             //domyślny konstruktor
    SUkladRownanLiniowych(SMacierz<Typ, Rozmiar> & Mac, SWektor<Typ, Rozmiar> & Wek) { A = Mac; b = Wek; };    //konstruktor: wpisuje Mac do A oraz Wek do b
    SWektor<Typ, Rozmiar> policz_wynik() const;                                //oblicza wektor wynikowy i zwraca go
    
    SWektor<Typ, Rozmiar> & setWek() { return b; }
    SWektor<Typ, Rozmiar> getWek() const { return b; }
    SMacierz<Typ, Rozmiar> & setMac() { return A; }
    SMacierz<Typ, Rozmiar> getMac() const { return A; }
};


template<typename Typ, int Rozmiar>
SWektor<Typ, Rozmiar> SUkladRownanLiniowych<Typ, Rozmiar>::policz_wynik() const
{
    SMacierz<Typ, Rozmiar> pom;
    SWektor<Typ, Rozmiar> Wynik;
    Typ wyznacznik_gl;
    Typ wyznacznik[Rozmiar];

    wyznacznik_gl = A.wyznacznik();

    if(fabs(wyznacznik_gl) < pow(0.1, 12))    //gdy wyznacznik_gl==0
    {
        std::cout << "Wyznacznik główny równy zero.\n";
        std::cout << "Koniec programu.\n";

        exit(EXIT_SUCCESS);
    }

    for(int i = 0; i < Rozmiar; i++)
    {
        pom = A.wstaw_kolumne(b, i);
        wyznacznik[i] = pom.wyznacznik();
    }

    for(int i = 0; i < Rozmiar; i++)
        Wynik[i] = wyznacznik[i]/wyznacznik_gl; 

    return Wynik;   
}


template<typename Typ, int Rozmiar>
std::istream& operator >> (std::istream &Strm, SUkladRownanLiniowych<Typ, Rozmiar> &UklRown)
{
    Strm >> UklRown.setMac();
    Strm >> UklRown.setWek();

    return Strm;
}


template<typename Typ, int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const SUkladRownanLiniowych<Typ, Rozmiar> &UklRown)
{
    Strm << "\nMacierz A:\n\n";
    Strm << UklRown.getMac() << std::endl << std::endl;

    Strm << "Wektor wyrazów wolnych b:\n\n\t";
    Strm << UklRown.getWek() << std::endl << std::endl;

    return Strm;
}


#endif
