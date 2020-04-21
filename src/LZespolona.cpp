#include <cmath>
#include <cstdlib>
#include "LZespolona.hh"

using namespace std;

ostream & operator <<(ostream & wypisz, const LZespolona & liczba)    //wyświetlenie liczby zespolonej
{
  wypisz << "(" << liczba.getRe() << showpos << liczba.getIm() << noshowpos << "i)";
  
  return wypisz;
}

istream & operator >>(istream & wczytaj, LZespolona & liczba)    //wczytuje liczbę zespoloną
{
  char WczytZnaki[100];             //tablica trochę większa dgyby ktoś wpisał za dużo znaków

  wczytaj >> WczytZnaki[0];
  if(WczytZnaki[0] != '(')         //sprawdza czy pierwszy znak to '('
  {
    cin.setstate(ios::failbit);       //ustaw flagę błędu
    return wczytaj;
  }

  wczytaj >> liczba.setRe() >> liczba.setIm();

  wczytaj >> WczytZnaki;         //wczytanie znaków 'i)'   
  if(WczytZnaki[0] != 'i' || WczytZnaki [1] != ')' || WczytZnaki[2] != '\0')
  {                                                
    cin.setstate(ios::failbit);              //ustaw flagę błędu
  }
          
  return wczytaj;
} 


LZespolona  LZespolona::operator + (const LZespolona & Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = re + Skl2.re;
  Wynik.im = im + Skl2.im;
  return Wynik;
}

LZespolona LZespolona::operator - (const LZespolona & Skl2) const   //realizuje odejmowanie dwóch liczb zespolonych
{
  LZespolona  Wynik;

  Wynik.re = re - Skl2.re;
  Wynik.im = im - Skl2.im;
  return Wynik;
}

LZespolona  LZespolona::operator * (const LZespolona & Skl2) const    //realizuje mnożenie dwóch liczb zespolonych
{
  LZespolona  Wynik;

  Wynik.re = re * Skl2.re - im * Skl2.im;
  Wynik.im = re * Skl2.im + im * Skl2.re;
  return Wynik;
}

LZespolona LZespolona::operator * (double liczba) const
{
  LZespolona Wynik;

  Wynik.re = re * liczba;
  Wynik.im = im * liczba;

  return Wynik;
}


/*!
 * Poniższe funkcje realizują operację dzielenia dwóch liczb zespolonych
 */

LZespolona LZespolona::Sprzezenie() const    //Obliczenie sprzeżenia liczby aby obliczyć wynik dzielenia
{
  LZespolona liczba = *this;
  liczba.im = -liczba.im;
  return liczba;
}


double LZespolona::Modul2() const      //Obliczenie modułu liczby aby obliczyć wynik dzielenia
{
  return re * re + im * im;
}

LZespolona LZespolona::operator / (double Skl2) const   //obliczenie wyniku dzielenia liczby zespolonej przez liczbę rzeczywistą
{
  LZespolona Wynik;

  Wynik.re = re / Skl2;
  Wynik.im = im / Skl2;

  return Wynik;
}

LZespolona LZespolona::operator / (const LZespolona & Skl2) const    //finalne obliczenie ilorazu
{
  if(Skl2.re == 0 && im == 0)         //warunek asercji
  {
    cerr << "Błąd fatalny. Dzielenie przez zero\n";
    abort();
  }
  LZespolona  Wynik;

  Wynik = *this * Skl2.Sprzezenie();
  Wynik = Wynik / Skl2.Modul2();
  

  return Wynik;
}

bool LZespolona::operator == (double liczba) const
{
  if(re == liczba && im == 0)
    return 1;
  return 0;
}

void LZespolona::operator = (double liczba)
{
  re = liczba;
  im = 0;
}


double fabs(const LZespolona & liczba)
{
  return liczba.Modul2();
}
