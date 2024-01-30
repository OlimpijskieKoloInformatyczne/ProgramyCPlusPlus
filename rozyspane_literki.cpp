#include <iostream>
#include <vector>
using namespace std;

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

 int ile_na_wejsciu, ilosc_malych_liter, numer_znaku, i;
 char akt_znak;
 vector<int> ile_razy_znak;

 ilosc_malych_liter = 'z' - 'a' + 1;
 ile_razy_znak.resize(ilosc_malych_liter, 0);

 cin >> ile_na_wejsciu;
 for (i=0; i<ile_na_wejsciu; ++i) {
    cin >> akt_znak;
    numer_znaku = akt_znak - 'a';
    ++ile_razy_znak[numer_znaku];
 }

 for (i=0; i<ilosc_malych_liter; ++i) {
    if ( ile_razy_znak[i] > 0 ) {
       akt_znak = 'a' + i;
       cout << akt_znak << ": " << ile_razy_znak[i] << endl;
	}
 }
      
 return 0;
}

