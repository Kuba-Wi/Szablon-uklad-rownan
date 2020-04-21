#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"

/*
      Klasa opisuje uklad równań złożony z macierzy kwadratowej
      i wektora wyrazów wolnych
      Pola:
      A - Macierz kwadratowa współczynników
      b - Wektor wyrazów wolnych
 */
class UkladRownanLiniowych {
  
    Macierz A;
    Wektor b;
  public:
    UkladRownanLiniowych() {}                             //domyślny konstruktor
    UkladRownanLiniowych(Macierz & Mac, Wektor & Wek) { A = Mac; b = Wek; };    //konstruktor: wpisuje Mac do A oraz Wek do b
    Wektor policz_wynik() const;                                //oblicza wektor wynikowy i zwraca go
    
    Wektor & setWek() { return b; }
    Wektor getWek() const { return b; }
    Macierz & setMac() { return A; }
    Macierz getMac() const { return A; }
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown);


#endif
