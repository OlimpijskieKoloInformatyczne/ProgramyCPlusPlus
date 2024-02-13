#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 
 int ile_liczb, akt_liczba, ile_nieparzystych, i;
 vector<int> ile_razy_liczba;
 ile_razy_liczba.resize(1'000'007,0);
 
 cin >> ile_liczb;
 
 ile_nieparzystych = 0;
 for (i=0; i<ile_liczb; ++i) {
    cin >> akt_liczba;
    ++ile_razy_liczba[akt_liczba];
   	if ( (ile_razy_liczba[akt_liczba]%2) == 1)
	   ++ile_nieparzystych;
	else
	   --ile_nieparzystych;
 }

 if (ile_nieparzystych > 1) {
    cout << "NIE" << endl;
	return 0;
 }

 cout << "TAK" << endl;  
 return 0;
}

