#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include "SWektor.hh"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>


/*
    Klasa opisuje Macierz kwadratową o rozmiarze ROZMIARxROZMIAR.
    kolumny - kolejne kolumny składowe Macierzy
 */
template<typename Typ, int Rozmiar>
class SMacierz {

    SWektor<Typ, Rozmiar> kolumny[Rozmiar];
    void zamien_kolumny(unsigned int a, unsigned int b);            //zamienia kolumne a z kolumna b
  public:
    Typ & operator ()(unsigned int a, unsigned int b);           //zwraca referencję do elementu Mac(a,b)
    Typ operator ()(unsigned int a, unsigned int b) const;       //zwraca wartość do elementu Mac(a,b)
    Typ wyznacznik() const;                                      //zwraca wyznacznik Macierzy
    SWektor<Typ, Rozmiar> operator *(const SWektor<Typ, Rozmiar> & Wek) const;                    //zwraca wektor wynikowy mnożenia macierzy przez wektor
    SMacierz<Typ, Rozmiar> wstaw_kolumne(const SWektor<Typ, Rozmiar> & Wek, unsigned int kolumna) const;   //zwraca macierz po zamianie
                                                                             //kolumny 'kolumna' Macierzy z wektorem Wek 

};

template<typename Typ, int Rozmiar>
void SMacierz<Typ, Rozmiar>::zamien_kolumny(unsigned int a, unsigned int b)
{
    if(a < Rozmiar && b < Rozmiar)
        std::swap(kolumny[a], kolumny[b]);
}

template<typename Typ, int Rozmiar>
Typ & SMacierz<Typ, Rozmiar>::operator ()(unsigned int a, unsigned int b) 
{
    assert(a < Rozmiar && b < Rozmiar);
    return kolumny[b][a]; 
}

template<typename Typ, int Rozmiar>
Typ SMacierz<Typ, Rozmiar>::operator ()(unsigned int a, unsigned int b) const 
{
    assert(a < Rozmiar && b < Rozmiar);
    return kolumny[b][a];
}


template<typename Typ, int Rozmiar>
Typ SMacierz<Typ, Rozmiar>::wyznacznik() const
{
    SMacierz<Typ, Rozmiar> pom = *this;
    double parzystosc = 1;           //parzystosc zamian kolumn wpływa na znak wyznacznika
    int nr_do_zam = 0;              //indeks kolumny z która ma zostać zamieniona kolumna i
    Typ iloraz;                  //zmienna pomocnicza do obliczania ilorazu dwóch kolumn
    Typ wyznacznik = 1;

    for(int i = 0; i < Rozmiar; i++)               //kolejne indeksy kolumn
    {
        nr_do_zam = i+1;
       
        while(fabs(pom(i,i)) < pow(0.1, 12))             //gdy pom(i,i)==0
        {
            if(nr_do_zam == Rozmiar)            //wyznacznik równy zero gdy w pierwszej kolumnie same zera
                return 0.0;

            else if(!(fabs(pom(i, nr_do_zam)) < pow(0.1, 12)))  //gdy wiersz do zam nie ma 0 na pierwszej ważnej pozycji
            {
                pom.zamien_kolumny(nr_do_zam, i);
                parzystosc = -parzystosc;
            }
            nr_do_zam++;
        }
        wyznacznik = wyznacznik * pom(i,i);

        for(int j = i+1; j < Rozmiar; j++)             //kolejne kolumny od ktorych odejmujemy kolumne i
        {
            iloraz = pom(i,j) / pom(i,i);                   
            for(int k = 0; k < Rozmiar; k++)           //kolejne kolumny
                pom(k,j) = pom(k, j) - pom(k,i)*iloraz;
        }
    }
    wyznacznik = wyznacznik * parzystosc;

    return wyznacznik;
}


template<typename Typ, int Rozmiar>
SWektor<Typ, Rozmiar> SMacierz<Typ, Rozmiar>::operator *(const SWektor<Typ, Rozmiar> &Wek) const
{
    SWektor<Typ, Rozmiar> pom;
    Typ skl_pom;
    skl_pom = 0;

    for(int w = 0; w < Rozmiar; w++)
    {
        for(int k = 0; k < Rozmiar; k++)
            skl_pom = skl_pom + kolumny[k][w] * Wek[k];

        pom[w] = skl_pom;
        skl_pom = 0;  
    }

    return pom;
}

template<typename Typ, int Rozmiar>
SMacierz<Typ, Rozmiar> SMacierz<Typ, Rozmiar>::wstaw_kolumne(const SWektor<Typ, Rozmiar> & Wek, unsigned int kolumna) const
{
    assert(kolumna < Rozmiar);
    SMacierz<Typ, Rozmiar> pom = *this;

    for(int i = 0; i < Rozmiar; i++)
        pom(i, kolumna) = Wek[i];
    
    return pom;
}



/*
    Funkcja wczytująca Macierz:
    Dane wejściowe:
      Strm - strumień wejściowy
      Mac - wczytywana macierz
    Wartość zwracana:
      &Strm
 */
template<typename Typ, int Rozmiar>
std::istream & operator >> (std::istream &Strm, SMacierz<Typ, Rozmiar> &Mac)
{
    for(int a = 0; a < Rozmiar; a++)
        for(int b = 0; b < Rozmiar; b++)
            Strm >> Mac(b,a);                 //bo macierz Mac w pliku to macierz transponowana
    
    return Strm;
}


/*
    Funkcja wypisująca Macierz:
    Dane wejściowe:
      Strm - strumień wyjściowy
      Mac - wypisywana macierz
    Wartość zwracana:
      &Strm
 */
template<typename Typ, int Rozmiar>
std::ostream & operator << (std::ostream &Strm, const SMacierz<Typ, Rozmiar> &Mac)
{
    for(int a = 0; a < Rozmiar; a++)
    {
        Strm << "\t";
        for(int b = 0; b < Rozmiar; b++)
            Strm << Mac(a,b) << "   ";
        Strm << std::endl;
    }
    
    return Strm;
}


#endif
