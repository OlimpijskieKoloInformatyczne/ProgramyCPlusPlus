#include <iostream>
using namespace std;

int main() {
 
 int stan_konta, kwota_przelewu;

 cin >> stan_konta >> kwota_przelewu;
 
 if ( kwota_przelewu > stan_konta ) {
    cout << "NO MONEY!" << endl;
    return 0;
 }

 stan_konta -= kwota_przelewu;

 cout << stan_konta << endl;
 
 return 0;
}