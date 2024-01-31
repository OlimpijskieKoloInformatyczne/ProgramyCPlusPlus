#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(a,b) for (int a = 0; a < (b); ++a)
#define pb push_back
#define all(t) t.begin(), t.end()

struct Zdarzenie
{
	int x, dol, gora, ile_dodajemy;
	bool operator < (const Zdarzenie &zdarzenie) const
	{
		if(x == zdarzenie.x) return ile_dodajemy > zdarzenie.ile_dodajemy;
		return x < zdarzenie.x;
	}
};

const int base = (1<<19), rozmiar_drzewa = base * 2;
int n = 0, x_1 = 0, x_2 = 0, y_1 = 0, y_2 = 0, wyn = 0;
vector<Zdarzenie> Z;
int tree[rozmiar_drzewa];
int tree2[rozmiar_drzewa];

inline void push(int v)
{
	tree[v*2] += tree2[v], tree[v*2+1] += tree2[v], tree2[v*2] += tree2[v], tree2[v*2+1] += tree2[v], tree2[v] = 0;
}

inline void update(int v, int l_zap, int p_zap, int l_kontrolowana, int p_kontrolowana, int val)
{
	if(p_kontrolowana < l_zap or l_kontrolowana > p_zap) return;
	if(l_kontrolowana >= l_zap and p_kontrolowana <= p_zap)
	{
		tree[v] += val, tree2[v] += val;
		return;
	}
	int mid = (l_kontrolowana+p_kontrolowana) / 2;
	push(v);
	update(v*2,l_zap,p_zap,l_kontrolowana,mid,val);
	update(v*2+1,l_zap,p_zap,mid+1,p_kontrolowana,val);
	tree[v] = max(tree[v*2],tree[v*2+1]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	rep(i,n)
	{
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		y_1 += 2e5, y_2 += 2e5;
		Z.pb({x_1,y_1,y_2,1});
		Z.pb({x_2,y_1,y_2,-1});
	}

	sort(all(Z));
	for(auto v : Z)
	{
		update(1,v.dol,v.gora,0,base-1,v.ile_dodajemy);
		wyn = max(wyn,tree[1]);
	}

	cout << wyn << '\n';

	return 0;
}