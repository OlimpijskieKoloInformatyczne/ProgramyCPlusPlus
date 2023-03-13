#include <iostream>
#include <queue>
using namespace std;

int main() {
// priority_queue<int, vector<int>, greater<int> > wplaty_na_gorze_MIN;

 priority_queue< int > wplaty_na_gorze_MAX;
 int datek;

 datek = 40;
 wplaty_na_gorze_MAX.push(datek); 
 datek = 80;
 wplaty_na_gorze_MAX.push(datek); 
 datek = 30;
 wplaty_na_gorze_MAX.push(datek); 

 wplaty_na_gorze_MAX.pop(); //usun MAX 
 wplaty_na_gorze_MAX.pop(); //usun MAX 
 wplaty_na_gorze_MAX.pop(); //usun MAX 
 if (wplaty_na_gorze_MAX.size() > 0) {
    wplaty_na_gorze_MAX.pop(); //usun MAX 
 } else {
    cout << "DLACZEGO kazesz mi usunac element jak kolejka PUSTA!!!!!!!!!!!" << endl; 
 }
 if (wplaty_na_gorze_MAX.size() > 0) {
    cout <<  wplaty_na_gorze_MAX.top() << endl;
 } else {
    cout <<  "Sorry - nie ma najwiekszego!!!" << endl;
 }
//nasza kolejka jest pusta 
 
 cout << wplaty_na_gorze_MAX.pop();
 return 0;
}
