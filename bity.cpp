#include <iostream>
using namespace std;

int main() {
 int liczba1, liczba2, wynik_and, wynik_or, wynik_xor;

 liczba1 = 45;
 liczba2 = 14;

 wynik_and = liczba1 & liczba2; //AND 
 cout << wynik_and << endl;
 
 wynik_or = liczba1 | liczba2; //AND 
 cout << wynik_or << endl;

 wynik_xor = liczba1 ^ liczba2; //AND 
 cout << wynik_xor << endl;

 return 0;
}