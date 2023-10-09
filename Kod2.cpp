#include <iostream>
using namespace std;

int main() {
 
 int stan_konta, kwota_przelewu;

 stan_konta = 10;
 kwota_przelewu = 17;
 
 if (kwota_przelewu > stan_konta)
   cout << "NO MONEY!" << endl;


 return 0;
}