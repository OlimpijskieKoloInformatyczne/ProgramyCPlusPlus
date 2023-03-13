#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
 priority_queue<string> lista;
 
 lista.push("byc");
 lista.push("albo"); 
 lista.push("nie"); 
 lista.push("byc"); 
 
 while (lista.size() > 0) {
    cout << lista.top() << " ";
    lista.pop();
 }

 return 0;
}
