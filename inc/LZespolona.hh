#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include<iostream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class  LZespolona {
    double   re;    /*! Pole repezentuje czesc rzeczywista. */
    double   im;    /*! Pole repezentuje czesc urojona. */

    /* 
-    Metoda oblicza sprzężenie liczby zespolonej
     Argumenty: Brak
-    Zwraca:    sprzężenie liczby zespolonej
    */
    LZespolona Sprzezenie() const;


    /* 
-    Metoda realizuje dzielenie liczby zespolonej przez liczbę rzeczywistą
-    Argumenty:
-      Skl1 - liczba zespolona
-      Skl2 - liczba rzeczywista
-    Zwraca:  liczba zespolona po wykonaniu dzielenia
  */
    LZespolona operator / (double Skl2) const;
  public:
    LZespolona(double r=0, double i=0) { re = r; im = i; }

     /* 
-    Metoda oblicza moduł liczby zepolonej podniesiony do kwadratu
-    Argumenty:   liczba - liczba zespolona
-    Zwraca:      wartość modułu podniesionego do kwadratu (liczba rzeczywista)
  */
    double Modul2() const;
    double & setRe() { return re; }
    double & setIm() { return im; }
    double getRe() const { return re; }
    double getIm() const { return im; }


/*!
- * Realizuje dodanie dwoch liczb zespolonych.
- * Argumenty:
- *    Skl1 - pierwszy skladnik dodawania,
- *    Skl2 - drugi skladnik dodawania.
- * Zwraca:
- *    Sume dwoch skladnikow przekazanych jako parametry.
*/
LZespolona  operator + (const LZespolona & Skl2) const;


/*!
- * Realizuje odejmowanie dwoch liczb zespolonych.
- * Argumenty:
- *    Skl1 - pierwszy skladnik odejmowania,
- *    Skl2 - drugi skladnik odejmowania.
- * Zwraca:
- *    Różnicę dwoch skladnikow przekazanych jako parametry.
*/
LZespolona  operator - (const LZespolona & Skl2) const;


/*!
- * Realizuje mnożenie dwoch liczb zespolonych.
- * Argumenty:
- *    Skl1 - pierwszy skladnik mnożenia,
- *    Skl2 - drugi skladnik mnożenia.
- * Zwraca:
- *    iloczyn dwoch skladnikow przekazanych jako parametry.
*/
LZespolona  operator * (const LZespolona & Skl2) const;

LZespolona operator * (double liczba) const;


/*!
- * Realizuje dzielenie dwoch liczb zespolonych.
- * Argumenty:
- *    Skl1 - pierwszy skladnik dzielenia,
- *    Skl2 - drugi skladnik dzielenia.
- * Zwraca:
- *    iloraz dwoch skladnikow przekazanych jako parametry.
*/
LZespolona  operator / (const LZespolona & Skl2) const;

bool operator == (double liczba) const;

void operator = (double liczba);

};


std::ostream & operator <<(std::ostream & wypisz, const LZespolona & liczba);

std::istream & operator >>(std::istream & wczytaj, LZespolona & liczba);

double fabs(const LZespolona & liczba);


#endif
