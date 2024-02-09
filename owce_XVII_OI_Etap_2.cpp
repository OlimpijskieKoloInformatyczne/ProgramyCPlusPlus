#include <bits/stdc++.h>
using namespace std;

#define fi first
#define nd second

typedef pair<int, int> PII;

constexpr int M = 607;

int n, k, m;
PII s[M], o[20007];

int dp[M][M];
bool zla[M][M]; //czy na krawedzi jest owca
int ile_t[M][M]; //ile owiec w trojkacie (i, j, j+1)
int ile_w[M][M]; //ile owiec w wielokacie( (i, j) - brzegowym

PII minuz(PII x, PII y){
	x.fi -= y.fi;
	x.nd -= y.nd;
	return x;
}

int dist(PII a, PII b){
	a = minuz(a,b);
	return a.fi*a.fi + a.nd*a.nd;
}

int cross(PII a, PII b, PII c){
	a = minuz(a,c);
	b = minuz(b,c);
	return a.fi*b.nd - b.fi*a.nd;
}

vector<int> v;
PII act;

struct comp{
	bool operator()(const int & t1, const int & t2)const{
		PII a, b;
		if(t1 < 0) a = s[t1+n]; else a = o[t1];
		if(t2 < 0) b = s[t2+n]; else b = o[t2];
		int tmp = cross(a,b,act);
		if(tmp == 0) return dist(a,act) < dist(b,act);
		else return tmp < 0; 
	}
};

void prep(){
	for(int i=0; i<k; i++) v.push_back(i);
	for(int i=0; i<n; i++) v.push_back(i-n);
	for(int i=0; i<n; i++){
		act = s[i];
		sort(v.begin(), v.end(), comp());
		int bok = v[1]+n, ile = 0;
		for(int k=2; k<v.size(); k++){
			if(v[k] < 0){
				int tmp = v[k]+n;
				//ile jest owiec
				ile_t[i][bok] = ile;
				//nowy trojkat
				ile = 0;
				bok = tmp;
			}
			else{
				if(cross(o[v[k]],s[(bok+1)%n],s[i]) == 0) zla[i][(bok+1)%n] = zla[(bok+1)%n][i] = 1;
				ile++;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int d=2; d<n-1; d++){
			ile_w[i][(i+d)%n] = ile_w[i][(i+d-1)%n] + ile_t[i][(i+d-1)%n];
		}
	}
}

bool bad(int a, int b, int c){
	if(zla[a][b] | zla[a][c] | zla[b][c]) return 1;
	return (ile_w[a][c] - ile_w[a][b] - ile_w[b][c]) % 2;
}

void init(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			dp[i][j] = 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> k >> m;
	
	for(int i=0; i<n; i++) cin >> s[i].fi >> s[i].nd;
	for(int i=0; i<k; i++) cin >> o[i].fi >> o[i].nd;	
	
	init();
	
	prep();
	
	for(int i=2; i<=n-1; i++){ //dlugosc
		for(int j=0; j<n-i; j++){ //poczatek
			dp[j][(j+i)%n] = 0;
			for(int k=j+1; k<=i+j-1; k++){ //trzeci wierzcholek na ktorym budujemy trojkat (j,k,j+i)
				if(bad(j,k%n,(j+i)%n)) continue;
				dp[j][(j+i)%n] += dp[j][k]*dp[k%n][(j+i)%n]%m;
				dp[j][(j+i)%n] %= m;
			}
		}
	}
	
	cout << dp[0][n-1] << '\n';
			
	return 0;
}
