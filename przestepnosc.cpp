#include <iostream>
using namespace std;

int main() {
 int rok;

 cin >> rok;
 
 if ( (rok%100) == 0)
    if ( (rok%400) != 0) {
	   cout << "NIE" << endl; 
       return 0;
 	}

 if ( (rok%4) == 0) {
    cout << "TAK" << endl; 
    return 0;
 }

 cout << "NIE" << endl; 

 return 0;
}


