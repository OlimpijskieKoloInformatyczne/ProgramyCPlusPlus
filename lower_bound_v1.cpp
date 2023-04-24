#include <iostream>
#include <vector> 
#include <algorithm>  
using namespace std;

const int ILE_WARTOSCI = 2;
const int ILE_PYTAN = 10;

int main() {
 vector<int> wartosci;
 vector<int>::iterator it;
 int i, szukana_wartosc, index;
 
 wartosci.resize(ILE_WARTOSCI+1);

 for (i=0; i<ILE_WARTOSCI; ++i)
    wartosci[i] = i;
 wartosci[ILE_WARTOSCI] = ILE_WARTOSCI+100; //straznik

 cout << "a1: Wypelniona kolejnymi liczbami zes straznikiem" << endl;
 for (i=0; i<=ILE_WARTOSCI; ++i)
    cout << wartosci[i] << " ";
 cout << endl;

 sort(wartosci.begin(), wartosci.end() );

 cout << "a2: Po posortowaniu" << endl;
 for (i=0; i<=ILE_WARTOSCI; ++i)
    cout << wartosci[i] << " ";
 cout << endl;

 for (i=0; i<ILE_PYTAN; ++i) {
    szukana_wartosc = i;
    it = lower_bound (wartosci.begin(), wartosci.begin()+ILE_WARTOSCI, szukana_wartosc);
    index = it - wartosci.begin();
    cout << "Szukamy: " << szukana_wartosc << ", Znaleziono na index: " << index << ", wartosc: " << wartosci[index] << endl;
 }

 
 return 0;
}
