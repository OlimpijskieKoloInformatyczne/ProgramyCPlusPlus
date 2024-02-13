#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

 
 int ile_liczb, i;
 int ile_nieparzystych, ile_w_serii;
 vector<int> liczby;
 
 cin >> ile_liczb;
 liczby.resize(ile_liczb, 0);
 
 for (i=0; i<ile_liczb; ++i)
    cin >> liczby[i];
 liczby.push_back(1'000'010);
 
 sort(liczby.begin(), liczby.end());
 
 ile_nieparzystych = 0;
 ile_w_serii = 1;
 for (i=1; i<liczby.size(); ++i) {
    if (liczby[i] != liczby[i-1]) {
    	if ( (ile_w_serii%2) == 1)
    	   ++ile_nieparzystych;
    	if (ile_nieparzystych > 1) {
    	   cout << "NIE" << endl;
    	   return 0;
		}
		ile_w_serii = 1;
		continue;
	}
	++ile_w_serii;
 }
 
 cout << "TAK" << endl; 
      
 return 0;
}

