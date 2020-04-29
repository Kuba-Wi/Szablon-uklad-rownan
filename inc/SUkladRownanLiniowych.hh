#ifndef SUKLADROWNANLINIOWYCH_HH
#define SUKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "SMacierz.hh"
#include "SWektor.hh"

/*!
 * Szablon klasy modeluje pojęcie układu równań     
 */
template<typename Typ, int Rozmiar>
class SUkladRownanLiniowych {
  
    SMacierz<Typ, Rozmiar> A; /*! macierz współczynników */
    SWektor<Typ, Rozmiar> b;  /*! wektor wyrazów wolnych */
  public:
    SUkladRownanLiniowych() {} /*! konstruktor domyślny */
    /*!
     * Konstruktor
     * Argumenty:
     * Mac - macierz przypisywana do A
     * Wek - wektor przypisywany do b
     */
    SUkladRownanLiniowych(SMacierz<Typ, Rozmiar> & Mac, SWektor<Typ, Rozmiar> & Wek) { A = Mac; b = Wek; };

    /*!
     * Metoda rozwiązuje układ równań.
     * Argumenty:   Brak
     * Zwraca:
     * wektor - rozwiązanie układu równań
     */
    SWektor<Typ, Rozmiar> policz_wynik() const;
    
    /*!
     * Metoda pozwala ustawić wartość wektora b:
     * Argumenty: Brak
     * Zwraca: referencję do wektora b
     */
    SWektor<Typ, Rozmiar> & setWek() { return b; }
    /*!
     * Metoda pozwala odczytać wartość wektora b:
     * Argumenty: Brak
     * Zwraca: wektor b
     */
    SWektor<Typ, Rozmiar> getWek() const { return b; }

    /*!
     * Metoda pozwala ustawić wartość macierzy A:
     * Argumenty: Brak
     * Zwraca: referencję do macierzy A
     */
    SMacierz<Typ, Rozmiar> & setMac() { return A; }
    /*!
     * Metoda pozwala odczytać wartość macierzy A:
     * Argumenty: Brak
     * Zwraca: macierz A
     */
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



/*!
 * Funkcja wczytuje układ równań:
 * Argumenty:
 * Strm - strumień wejściowy
 * UklRown - wczytywany układ równań
 * Zwraca:
 * referencję do Strm
 */
template<typename Typ, int Rozmiar>
std::istream& operator >> (std::istream &Strm, SUkladRownanLiniowych<Typ, Rozmiar> &UklRown)
{
    Strm >> UklRown.setMac();
    Strm >> UklRown.setWek();

    return Strm;
}

/*!
 * Funkcja wypisuje układ równań:
 * Argumenty:
 * Strm - strumień wyjściowy
 * UklRown - wczytywany układ równań
 * Zwraca:
 * referencję do Strm
 */
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
