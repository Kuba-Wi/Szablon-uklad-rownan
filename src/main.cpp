#include <iostream>
#include "SWektor.hh"
#include "SMacierz.hh"
#include "SUkladRownanLiniowych.hh"
#include "LZespolona.hh"
#include "rozmiar.h"



using namespace std;

void uklad_zespolony() {
  
  SMacierz<LZespolona, ROZMIAR> A;
  SWektor<LZespolona, ROZMIAR> b;
  SWektor<LZespolona, ROZMIAR> Wynik;
  SWektor<LZespolona, ROZMIAR> blad;

  SUkladRownanLiniowych<LZespolona, ROZMIAR> UklRown;

  cin >> UklRown;
  cout << UklRown;

  A = UklRown.getMac();
  b = UklRown.getWek();

  Wynik = UklRown.policz_wynik(); 

  cout << "Rozwiązanie x = (x1, x2, x3):\n\n\t";
  cout << Wynik << endl;

  blad = A * Wynik - b;

  cout << "Wektor błędu Ax-b: ";
  cout << blad << endl; 
  cout << "Dlugosc wektora błędu |Ax-b|: ";
  cout << blad.dlugosc() << endl;
}

void uklad_rzeczywisty() {

  SMacierz<double, ROZMIAR> A;
  SWektor<double, ROZMIAR> b;
  SWektor<double, ROZMIAR> Wynik;
  SWektor<double, ROZMIAR> blad;

  SUkladRownanLiniowych<double, ROZMIAR> UklRown;

  cin >> UklRown;
  cout << UklRown;

  A = UklRown.getMac();
  b = UklRown.getWek();

  Wynik = UklRown.policz_wynik(); 

  cout << "Rozwiązanie x = (x1, x2, x3):\n\n\t";
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
    uklad_rzeczywisty();
  else if(rodzaj_ukl == 'z')
    uklad_zespolony();
  else
    cout << "Zły identyfikator układu.\n";
  
}
