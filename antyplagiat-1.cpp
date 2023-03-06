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


int main() {
 string linia;	
 set<string> tekst_oryginalny;
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

 for (it=tekst_oryginalny.begin(); it!=tekst_oryginalny.end(); ++it)
    cout << *it << endl; 

  return 0;
}

