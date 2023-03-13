#include <iostream>
#include <queue>
using namespace std;

int main() {
 priority_queue< int > wplaty_na_gorze_MAX;
 priority_queue<int, vector<int>, greater<int> > wplaty_na_gorze_MIN;
 int datek;

 datek = 40;
 wplaty_na_gorze_MAX.push(datek); 
 datek = 80;
 wplaty_na_gorze_MAX.push(datek); 
 datek = 30;
 wplaty_na_gorze_MAX.push(datek); 
 
 cout << wplaty_na_gorze_MAX.top() << endl;
 
 return 0;
}

