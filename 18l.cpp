#include <iostream>
#include <queue>
using namespace std;

//pamietamy o & - mniejsza zloznosc, const by nie zmienic
bool CzyWzrost1ZLewejStrony(const int &w1, const int &w2) {
 return w1 > w2;
}

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

 priority_queue<int, vector<int>, bool (*)(const int &, const int &)> 
                wzrosty_MIN(CzyWzrost1ZLewejStrony);
 priority_queue<int> wzrosty_MAX;
 vector<int> ile_wzrostow;
 int ile_pytan, i;
 int akt_wzrost, akt_MAX, akt_MIN;
 char znak;

 ile_wzrostow.resize(1000007,0);

 cin >> ile_pytan;
 for (i=1; i <= ile_pytan; ++i) {
    cin >> znak;
    if ( znak == 'z' ) {
       cin >> akt_wzrost;
       wzrosty_MIN.push(akt_wzrost);
       wzrosty_MAX.push(akt_wzrost);
       ++ile_wzrostow[akt_wzrost];
       continue;
	}
    if ( znak == 'u' ) {
       cin >> akt_wzrost;
       if ( ile_wzrostow[akt_wzrost] == 0 )
          continue;
       --ile_wzrostow[akt_wzrost]; 
       continue;
	}
//jesli tu jestemy to znaczy ze mamy polecenie
//r - roznica - wypisz roznice
    while (true) {
       if ( wzrosty_MAX.size() > 0 )	
          akt_MAX = wzrosty_MAX.top();
       else   
          akt_MAX = 0;
       if (akt_MAX == 0)
	      break; 
       if (ile_wzrostow[akt_MAX] > 0)
	      break; 
       wzrosty_MAX.pop();
	} 	
    while (true) {
       if ( wzrosty_MIN.size() > 0 )	
          akt_MIN = wzrosty_MIN.top();
       else   
          akt_MIN = 0;
       if (akt_MIN == 0)
	      break; 
       if (ile_wzrostow[akt_MIN] > 0)
	      break; 
       wzrosty_MIN.pop();
	} 
	if ( akt_MAX > 0 )
	   cout << akt_MAX - akt_MIN << endl;
	else
	   cout << "PUSTO!" << endl;
 }
 cout << endl; 

 return 0;
}


