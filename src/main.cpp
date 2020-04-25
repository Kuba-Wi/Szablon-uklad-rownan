#include <iostream>
#include "SWektor.hh"
#include "SMacierz.hh"
#include "SUkladRownanLiniowych.hh"
#include "LZespolona.hh"
#include "rozmiar.h"



using namespace std;


template<typename Typ, int Rozmiar>
void uklad_rownan() {

  SMacierz<Typ, Rozmiar> A;
  SWektor<Typ, Rozmiar> b;
  SWektor<Typ, Rozmiar> Wynik;
  SWektor<Typ, Rozmiar> blad;

  SUkladRownanLiniowych<Typ, Rozmiar> UklRown;

  cin >> UklRown;
  cout << UklRown;

  A = UklRown.getMac();
  b = UklRown.getWek();

  Wynik = UklRown.policz_wynik(); 

  cout << "Rozwiązanie x = (x1, x2, x3, x4, x5):\n\n\t";
  cout << Wynik << endl;

  blad = A * Wynik - b;

  cout << "Wektor błędu Ax-b: ";
  cout << blad << endl;
  cout << "Dlugosc wektora błędu |Ax-b|: ";
  cout << blad.dlugosc() << endl;

}


int main() {

  char rodzaj_ukl;
  cin >> rodzaj_ukl;
  
  if(rodzaj_ukl == 'r')
    uklad_rownan<double, ROZMIAR>();
  else if(rodzaj_ukl == 'z')
    uklad_rownan<LZespolona, ROZMIAR>();
  else
    cout << "Zły identyfikator układu.\n";
  
}
