#include "do_testu.hh"

using namespace std;
template class SWektor<LZespolona, ROZMIAR>;
template class SWektor<double, ROZMIAR>;
template double SWektor<LZespolona, ROZMIAR>::dlugosc() const;
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

  cout << "Rozwiązanie x = (x1, x2, x3):\n\n\t";
  cout << Wynik << endl;

  blad = A * Wynik - b;

  cout << "Wektor błędu Ax-b: ";
  cout << blad << endl;
  cout << "Dlugosc wektora błędu |Ax-b|: ";
  cout << blad.dlugosc() << endl;

}

template void uklad_rownan<double, ROZMIAR>();
template void uklad_rownan<LZespolona, ROZMIAR>();
//template double SWektor<double, ROZMIAR>::dlugosc() const;
//template double SWektor<LZespolona, ROZMIAR>::dlugosc() const;