#include <cstdlib>
#include <cmath>
#include "UkladRownanLiniowych.hh"


Wektor UkladRownanLiniowych::policz_wynik() const
{
    Macierz pom;
    Wektor Wynik;
    double wyznacznik_gl;
    double wyznacznik[ROZMIAR];

    wyznacznik_gl = A.wyznacznik();

    if(wyznacznik_gl < pow(0.1, 12) && wyznacznik_gl > -pow(0.1, 12))    //gdy wyznacznik_gl==0
    {
        std::cout << "Wyznacznik główny równy zero.\n";
        std::cout << "Koniec programu.\n";

        exit(EXIT_SUCCESS);
    }

    for(int i = 0; i < ROZMIAR; i++)
    {
        pom = A.wstaw_kolumne(b, i);
        wyznacznik[i] = pom.wyznacznik();
    }

    for(int i = 0; i < ROZMIAR; i++)
        Wynik[i] = wyznacznik[i]/wyznacznik_gl; 

    return Wynik;   
}


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Strm >> UklRown.setMac();
    Strm >> UklRown.setWek();

    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{
    Strm << "\nMacierz A:\n\n";
    Strm << UklRown.getMac() << std::endl << std::endl;

    Strm << "Wektor wyrazów wolnych b:\n\n\t";
    Strm << UklRown.getWek() << std::endl << std::endl;

    return Strm;
}
