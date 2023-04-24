#include <iostream>
#include <vector> 
#include <algorithm>  
using namespace std;

const int ILE_WARTOSCI = 1000;

int main() {
 vector<int> wartosci;
 int i;
 
 wartosci.resize(ILE_WARTOSCI+1);

 for (i=0; i<ILE_WARTOSCI; ++i)
    wartosci[i] = i;
 wartosci[ILE_WARTOSCI] = ILE_WARTOSCI+100; //straznik

 cout << "a1: Wypelniona kolejnymi liczbami zes straznikiem" << endl;
 for (i=0; i<=ILE_WARTOSCI; ++i)
    cout << wartosci[i] << " ";
 cout << endl;

 sort(wartosci.begin(), wartosci.end() );

 cout << "a2: Po posrtowaniu" << endl;
 for (i=0; i<=ILE_WARTOSCI; ++i)
    cout << wartosci[i] << " ";
 cout << endl;

 
 return 0;
}
