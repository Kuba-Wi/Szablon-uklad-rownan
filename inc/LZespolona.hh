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

    /*! 
     *  Metoda oblicza sprzężenie liczby zespolonej
     *  Argumenty: Brak
     *  Zwraca:    sprzężenie liczby zespolonej
     */
    LZespolona Sprzezenie() const;

  public:
    /*!
     * Konstruktor, przypisuje r do re, i do im:
     * Argumenty: 
     * r - składowa rzeczywista
     * i - składowa urojona
     * Wartość zwracana: Brak
     */
    LZespolona(double r=0, double i=0) { re = r; im = i; }

    /*! 
     *  Metoda realizuje dzielenie liczby zespolonej przez liczbę rzeczywistą
     *  Argumenty:
     *  Skl1 - liczba zespolona
     *  Skl2 - liczba rzeczywista
     *  Zwraca:  liczba zespolona po wykonaniu dzielenia
     */
    LZespolona operator / (double Skl2) const;

    /*!
     * Metoda oblicza moduł liczby zepolonej podniesiony do kwadratu
     * Argumenty:   liczba - liczba zespolona
     * Zwraca:      wartość modułu podniesionego do kwadratu (liczba rzeczywista)
     */
    double Modul2() const;

    /*!
     * Metoda pozwala ustawić wartość re:
     * Argumenty: Brak
     * Zwraca: referencję do re
     */
    double & setRe() { return re; }
    /*!
     * Metoda pozwala ustawić wartość im:
     * Argumenty: Brak
     * Zwraca: referencję do im
     */
    double & setIm() { return im; }
    /*!
     * Metoda pozwala odczytać wartość re:
     * Argumenty: Brak
     * Zwraca: re
     */
    double getRe() const { return re; }
    /*!
     * Metoda pozwala odczytać wartość im:
     * Argumenty: Brak
     * Zwraca: im
     */
    double getIm() const { return im; }


    /*!
     * Realizuje dodanie dwoch liczb zespolonych.
     * Argumenty:
     *    Skl1 - pierwszy skladnik dodawania,
     *    Skl2 - drugi skladnik dodawania.
     * Zwraca:
     *    Sume dwoch skladnikow przekazanych jako parametry.
     */
    LZespolona  operator + (const LZespolona & Skl2) const;


    /*!
     * Realizuje odejmowanie dwoch liczb zespolonych.
     * Argumenty:
     *    Skl1 - pierwszy skladnik odejmowania,
     *    Skl2 - drugi skladnik odejmowania.
     * Zwraca:
     *    Różnicę dwoch skladnikow przekazanych jako parametry.
     */
    LZespolona  operator - (const LZespolona & Skl2) const;


    /*!
     * Realizuje mnożenie dwoch liczb zespolonych.
     * Argumenty:
     *    Skl1 - pierwszy skladnik mnożenia,
     *    Skl2 - drugi skladnik mnożenia.
     * Zwraca:
     *    iloczyn dwoch skladnikow przekazanych jako parametry.
     */
    LZespolona  operator * (const LZespolona & Skl2) const;

    /*!
     * Metoda realizuje mnożenie liczby zespolonej przez liczbę rzeczywistą.
     * Argumenty: liczba - liczba rzeczywista
     * Zwraca:  liczbę zespoloną po wykonaniu mnożenia
     */
    LZespolona operator * (double liczba) const;

    /*!
     * Realizuje dzielenie dwoch liczb zespolonych.
     * Argumenty:
     *    Skl1 - pierwszy skladnik dzielenia,
     *    Skl2 - drugi skladnik dzielenia.
     * Zwraca:
     *    iloraz dwoch skladnikow przekazanych jako parametry.
     */
    LZespolona  operator / (const LZespolona & Skl2) const;
};

/*!
 * Funkcja wypisuje liczbę zespoloną:
 * Argumenty:
 * wypisz - strumień wyjściowy
 * liczba - liczba zespolona
 * Zwraca:
 * referencję do wypisz
 */
std::ostream & operator <<(std::ostream & wypisz, const LZespolona & liczba);

/*!
 * Funkcja wczytuje liczbę zespoloną:
 * Argumenty:
 * wczytaj - strumien wejściowy
 * liczba - liczba zespolona
 * Zwraca:
 * referencję do wczytaj
 */
std::istream & operator >>(std::istream & wczytaj, LZespolona & liczba);

/*!
 * Funkcja liczy moduł liczby zespolonej.
 * Argumenty:
 * liczba - liczba zespolona
 * Zwraca:
 * moduł liczby zespolonej
 */
double fabs(const LZespolona & liczba);


#endif
