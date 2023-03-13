#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct typ_darczynca {
 int zlotowki;
 int dolary;
 string nazwisko;
};

bool CzyDarczynca1ZLewejStrony(const typ_darczynca &d1, const typ_darczynca &d2) {
 int kwota_1, kwota_2;
 kwota_1 = 4*d1.dolary + d1.zlotowki; 
 kwota_2 = 4*d2.dolary + d2.zlotowki; 
//wiekszy ten ktory wplacil wiecej ogolnie - po przeliczeniu na zlotowki
 if ( kwota_1 != kwota_2 ) {
    return kwota_1 < kwota_2;
 }
//wplacili tyle samo 
//wiekszy ten ktory wplacil wiecej dolarow
 if ( d1.dolary != d2.dolary ) {
    return d1.dolary < d2.dolary;
 }
//wplacili tyle samo po przeliczeniu na zltoowki iw placili tyle samo dolarow
//z lewej strony ten o alfabetycznie starszym nazwisku
//na topie bedzie mniejsze nazwisk o z prawej mniejsze nazwiska a zlewej wieksze
 return d1.nazwisko > d2.nazwisko; 
}

int main() {
// priority_queue<typ_darczynca> wplaty;
 priority_queue<typ_darczynca, vector<typ_darczynca>, 
 bool (*)(const typ_darczynca &, const typ_darczynca &)> 
                wplaty(CzyDarczynca1ZLewejStrony);
 int liczba_wplat, i;
 typ_darczynca akt_wplata, najlepsza_wplata;
 
 cin >> liczba_wplat; 
 for (i=1; i <= liczba_wplat; ++i) { 
    cin >> akt_wplata.zlotowki >> akt_wplata.dolary >> akt_wplata.nazwisko;
    wplaty.push(akt_wplata);
    najlepsza_wplata = wplaty.top();
    cout << najlepsza_wplata.nazwisko << " " << najlepsza_wplata.dolary << " " << 
	        najlepsza_wplata.zlotowki << endl;
 }	
 
 return 0;
}
