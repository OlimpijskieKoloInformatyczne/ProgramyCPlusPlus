#include <iostream>
#include <vector>
using namespace std;

const int MAX_LAMPKA = 60;

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 
 int liczba_pytan, i, numer_lampki;	
 long long akt_maska, wartosc_lampek, zapalenie;
 vector<long long> maski;	
 
 cin >> liczba_pytan;

 maski.resize(61,0);
 
 akt_maska = 1;
 for (i=0; i<MAX_LAMPKA; ++i) {
 	maski[i] = akt_maska;
 	akt_maska = akt_maska << 1;
 }

 for (i=1; i<=liczba_pytan; ++i) {
    cin >> wartosc_lampek >> numer_lampki;
    zapalenie = wartosc_lampek & maski[numer_lampki];
cout << wartosc_lampek << " " << numer_lampki << " " << maski[numer_lampki] << " "
<< zapalenie << endl;
    if ( zapalenie > 0 )
       cout << "DZIALA!" << endl;
    else
       cout << "NAPRAW!" << endl;
 }
	
 return 0;
}