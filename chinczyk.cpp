#include <iostream>
using namespace std;

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

 int i, liczba_rzutow, akt_rzut, liczba_szostek;
 
 cin >> liczba_rzutow;
 
 liczba_szostek = 0;
 for (i=1; i<=liczba_rzutow; ++i) {
    cin >> akt_rzut;
    if  (akt_rzut == 6) 
	   ++liczba_szostek;
 }
 
 cout << liczba_szostek << endl;

 return 0;
}

