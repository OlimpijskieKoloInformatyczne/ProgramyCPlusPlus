#include <iostream>
#include <vector>
using namespace std;

int main() {
 vector<int> wzrosty;
 int i;
 int szukany_wzrost, znaleziony_wzrost;

 wzrosty.resize(20);
 wzrosty[1] = 190; 
 wzrosty[2] = 160; 
 wzrosty[3] = 170; 
 wzrosty[4] = 200; 
 wzrosty[5] = 180; 

 szukany_wzrost = 180;
 znaleziony_wzrost = -1;
 for (i=1; i<=5; ++i) {
    if ( szukany_wzrost == wzrosty[i] )
       znaleziony_wzrost = szukany_wzrost;
 }
 if ( szukany_wzrost == znaleziony_wzrost )
    cout << "MAM!" << endl; 
 else
    cout << "SORRY GREGORRY!" << endl; 
 
 
 return 0;
}