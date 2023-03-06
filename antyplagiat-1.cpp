#include <iostream>
#include <string>
#include <set>
using namespace std;

void UsunBialeZnaki(string &napis_zrodlo){
 int i;
 string napis_bez_bialych;
 napis_bez_bialych = "";
 
 for (i=0; i<(int)napis_zrodlo.size(); ++i) {
    if ( isspace( napis_zrodlo[i] ) > 0 )
	   continue;
    //tu jestemy czyli literka nie jest bialym znakiem
	napis_bez_bialych += napis_zrodlo[i];
 }
 napis_zrodlo = napis_bez_bialych;
}

bool CzyString1ZLewejStrony(const string &s1, const string &s2) {
 if ( s1.size() != s2.size() )
    return s1.size() > s2.size();
// jesli sa rownej dlugosci
 return s1 < s2; 
}

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

 string linia;	
 set<string> tekst_oryginalny;
 set<string, bool (*)(const string &, const string &)> 
                             linie_plagiatow(CzyString1ZLewejStrony);
 set<string>::iterator it;
 
 getline(cin, linia); //Wczytujemy TEXT1
 while ( getline(cin, linia) ) {
    UsunBialeZnaki(linia);
    if (linia == "TEXT2")
       break;
    if ( linia.size() == 0 )
       continue;    
    tekst_oryginalny.insert(linia);
 }

 while ( getline(cin, linia) ) {
    UsunBialeZnaki(linia); 
    if ( linia.size() == 0 )
       continue;
    if ( tekst_oryginalny.find(linia) != tekst_oryginalny.end() )
	   linie_plagiatow.insert(linia); 
 }

 for (it=linie_plagiatow.begin(); it!=linie_plagiatow.end(); ++it)
    cout << *it << endl; 
 
  return 0;
}
