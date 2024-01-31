#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(a,b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define all(t) t.begin(), t.end()

const int MAXN = 2003;
int n = 0, r = 0, y = 0, x = 0, l = 0;
ll wyn = 0;
vector<vector<ll>> S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r;

	S.assign(MAXN,{});
	rep(i,MAXN) S[i].assign(MAXN,0);

	rep(i,n)
	{
		rep(j,n) 
		{
			cin >> x;
			S[i+j+1][j-i+(n-1)+1] = x;
		}
	}

	rep(i,MAXN)
	{
		rep(j,MAXN)
		{
			if(i == 0 and j == 0) S[i][j] = S[i][j];
			else if(i == 0) S[i][j] = S[i][j] + S[0][j-1];
			else if(j == 0) S[i][j] = S[i][j] + S[i-1][0];
			else S[i][j] = S[i][j] + S[i-1][j] + S[i][j-1] - S[i-1][j-1];
		}
	}

	
	while(r--)
	{
		cin >> y >> x >> l;
		--y, --x;
		int y_wsp = x+y+1, x_wsp = x-y+(n-1)+1, x_1 = max(1,x_wsp - l), x_2 = min(MAXN-1,x_wsp + l), y_1 = max(1,y_wsp - l), y_2 = min(MAXN-1,y_wsp + l);
		wyn = S[y_2][x_2] - S[y_2][x_1-1] - S[y_1-1][x_2] + S[y_1-1][x_1-1];
		cout << wyn << '\n';
	} 

	return 0; 
}