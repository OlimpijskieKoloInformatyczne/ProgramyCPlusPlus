#include <iostream>
#include <vector>
using namespace std;

const int MAX_LAMPKA = 60;

int main() {
 int liczba_pytan, i, numer_lampki;	
 long long akt_maska;
 vector<long long> maski;	
 
 cin >> liczba_pytan;

 maski.resize(60,0);
 
 akt_maska = 1;
 for (i=0; i<MAX_LAMPKA; ++i) {
 	maski[i] = akt_maska;
 	akt_maska = akt_maska << 1;
 }

 for (i=0; i<MAX_LAMPKA; ++i) {
 	cout << maski[i] << " ";
 }
 cout << endl;

 
 return 0;
}
