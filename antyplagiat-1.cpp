#include <iostream>
using namespace std;

void UsunBialeZnaki(string &napis_zrodlo){
 int i;
 string napis_bez_bialych;
 napis_bez_bialych = "";
 
 for (i=0; i<(int)napis_zrodlo.size(); ++i) {
    if ( isspace( napis_zrodlo[i] ) > 0 )
	   continue;
	napis_bez_bialych += napis_zrodlo[i];
 }
 napis_zrodlo = napis_bez_bialych;
}


int main() {
 string linia;	
 linia = "Ala ma	kota   ";
 cout << linia << endl;
 UsunBialeZnaki(linia);
 cout << linia << endl;
 
 cout << linia << endl;
 
 return 0;
}
