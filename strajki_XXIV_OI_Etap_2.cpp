#include <bits/stdc++.h>
using namespace std;

constexpr int M = 5e5+7;
constexpr int BASE = 1<<19;

int T[2*BASE]; //drzewo - suma, ile moich sasiadow strajkuje
int parent[M], tim[M], min_tim[M], max_tim[M]; //ojciec, jaki mam numer, min/max_numer syna-zeby szybko dodawac na przedziale
bool lisc[M]; //czy lisc

vector<int> G[M];
int n, m;

int tajm;
void DFS(int v, int p){
	parent[v] = p;
	min_tim[v] = tajm+1;
	for(auto i : G[v]){
		if(i == p) continue;
		tim[i] = ++tajm;
	}
	if(G[v].size() == 1 && v != 1) lisc[v] = 1;
	else max_tim[v] = tajm;
	
	for(auto i : G[v]){
		if(i == p) continue;
		DFS(i, v);
	}
}

void add(int a, int b, int w){
	a += BASE-1;
	b += BASE+1;
	
	while(a/2 != b/2){
		if(a % 2 == 0) T[a+1] += w;
		if(b % 2 == 1) T[b-1] += w;
		a/=2; b/=2;
	}
}

int query(int v){
	int res = 0;
	v = tim[v] + BASE;
	
	while(v > 0){
		res += T[v];
		v/=2;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	DFS(1, 0);
	
	cin >> m;
	
	int ans = 1;
	for(int i=0; i<m; i++){
		int z;
		cin >> z;
		
		if(z > 0){
			if(lisc[z] != 1) add(min_tim[z], max_tim[z], 1); //synowie
			if(z != 1) add(tim[parent[z]], tim[parent[z]], 1); //ojciec
		
			ans += G[z].size()-1; //-1 bo to byla 1 spojna
			ans -= query(z); //juz policzone
		}
		else{
			z = abs(z);
			if(lisc[z] != 1) add(min_tim[z], max_tim[z], -1);
			if(z != 1) add(tim[parent[z]], tim[parent[z]], -1);
						
			ans -= G[z].size()-1;
			ans += query(z); //te dalej sa odciete
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
