#include <iostream>
#include <vector> 
using namespace std;

const int ILE_WARTOSCI = 10000;
const int ILE_PYTAN = 100000;

int main() {
 vector<int> wartosci;
 int i, szukana_wartosc, index;
 
 wartosci.resize(ILE_WARTOSCI+1);

 for (i=0; i<ILE_WARTOSCI; ++i)
    wartosci[i] = i;
 wartosci[ILE_WARTOSCI] = ILE_WARTOSCI+100; //straznik

 for (i=0; i<ILE_PYTAN; ++i) {
    szukana_wartosc = i;
    for (index=0; index<=ILE_WARTOSCI; ++index) {
       if (wartosci[index] >= szukana_wartosc)
	      break; 
	}
 }
 
 return 0;
}

