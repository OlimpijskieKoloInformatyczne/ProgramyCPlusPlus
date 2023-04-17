#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
 vector<int> wzrosty;
 vector<int>::iterator it;
 int i;
 int szukany_wzrost, znaleziony_wzrost;

 wzrosty.resize(20);
 wzrosty[1] = 190; 
 wzrosty[2] = 160; 
 wzrosty[3] = 170; 
 wzrosty[4] = 200; 
 wzrosty[5] = 180; 

sort( wzrosty.begin()+1, wzrosty.begin()+5+1 );
 it = lower_bound(wzrosty.begin()+1, wzrosty.begin()+5+1, 170);
 cout << *it << endl; 
 return 0;
}