#include <iostream>
#include <vector>       
using namespace std;

const int ILE_WARTOSCI = 2;

int main() {
 vector<int> wartosci;
 int i;
 
 wartosci.resize(ILE_WARTOSCI+1);

 for (i=0; i<ILE_WARTOSCI; ++i)
    wartosci[i] = i;
 wartosci[ILE_WARTOSCI] = ILE_WARTOSCI+100; //straznik

 cout << "a1: Wypelniona kolejnymi liczbami zes traznikiem" << endl;
 for (i=0; i<=ILE_WARTOSCI; ++i)
    cout << wartosci[i] << " ";
 cout << endl;
 
 return 0;
}
