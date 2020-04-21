#include "Macierz.hh"
#include <cmath>
#include <algorithm>
#include <cassert>



void Macierz::zamien_kolumny(unsigned int a, unsigned int b)
{
    if(a < ROZMIAR && b < ROZMIAR)
        std::swap(kolumny[a], kolumny[b]);
}

double & Macierz::operator ()(unsigned int a, unsigned int b) 
{
    assert(a < ROZMIAR && b < ROZMIAR);
    return kolumny[b][a]; 
}

double Macierz::operator ()(unsigned int a, unsigned int b) const 
{
    assert(a < ROZMIAR && b < ROZMIAR);
    return kolumny[b][a];
}


double Macierz::wyznacznik() const
{
    Macierz pom = *this;
    double parzystosc = 1;           //parzystosc zamian kolumn wpływa na znak wyznacznika
    int nr_do_zam = 0;              //indeks kolumny z która ma zostać zamieniona kolumna i
    double iloraz;                  //zmienna pomocnicza do obliczania ilorazu dwóch kolumn
    double wyznacznik = 1;

    for(int i = 0; i < ROZMIAR; i++)               //kolejne indeksy kolumn
    {
        nr_do_zam = i+1;
       
        while(pom(i,i) < pow(0.1, 12) && pom(i,i) > -pow(0.1, 12))             //gdy pom(i,i)==0
        {
            if(nr_do_zam == ROZMIAR)            //wyznacznik równy zero gdy w pierwszej kolumnie same zera
                return 0;

            else if(pom(i, nr_do_zam) > pow(0.1, 12) || pom(i, nr_do_zam) < -pow(0.1, 12))  //gdy wiersz do zam nie ma 0 na pierwszej ważnej pozycji
            {
                pom.zamien_kolumny(nr_do_zam, i);
                parzystosc = -parzystosc;
            }
            nr_do_zam++;
        }
        wyznacznik *= pom(i,i);

        for(int j = i+1; j < ROZMIAR; j++)             //kolejne kolumny od ktorych odejmujemy kolumne i
        {
            iloraz = pom(i,j) / pom(i,i);                   
            for(int k = 0; k < ROZMIAR; k++)           //kolejne kolumny
                pom(k,j) -= pom(k,i)*iloraz;
        }
    }
    wyznacznik *= parzystosc;

    return wyznacznik;
}


Wektor Macierz::operator *(const Wektor &Wek) const
{
    Wektor pom;
    double skl_pom = 0;

    for(int w = 0; w < ROZMIAR; w++)
    {
        for(int k = 0; k < ROZMIAR; k++)
            skl_pom += kolumny[k][w] * Wek[k];

        pom[w] = skl_pom;
        skl_pom = 0;  
    }

    return pom;
}

Macierz Macierz::wstaw_kolumne(const Wektor & Wek, unsigned int kolumna) const
{
    assert(kolumna < ROZMIAR);
    Macierz pom = *this;

    for(int i = 0; i < ROZMIAR; i++)
        pom(i, kolumna) = Wek[i];
    
    return pom;
}


std::istream & operator >> (std::istream &Strm, Macierz &Mac)
{
    for(int a = 0; a < ROZMIAR; a++)
        for(int b = 0; b < ROZMIAR; b++)
            Strm >> Mac(b,a);                 //bo macierz Mac w pliku to macierz transponowana
    
    return Strm;
}

std::ostream & operator << (std::ostream &Strm, const Macierz &Mac)
{
    for(int a = 0; a < ROZMIAR; a++)
    {
        Strm << "\t";
        for(int b = 0; b < ROZMIAR; b++)
            Strm << Mac(a,b) << "   ";
        Strm << std::endl;
    }
    
    return Strm;
}
