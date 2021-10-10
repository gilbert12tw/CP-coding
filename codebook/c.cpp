#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma loop-opt(on)
#define pb push_back
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define int long long
#define pii pair<int, int>
#define inf 1e9
#define mod 1000000007
#define F first
#define S second
#define wopen(x) freopen((x),"w",stdout)
#define ropen(x) freopen((x),"r",stdin)
#define de(x) cout << #x << " = " << x << ' '
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int x[10], y[10];

signed main() {
	IO;
	for(int i = 1; i <= 6; i++) 
		cin >> x[i] >> y[i];
	if(x[3] <= x[1] and y[3] <= y[1] and x[4] >= x[2] and y[4] >= y[2]) cout << "NO\n";
	else if(x[5] <= x[1] and y[5] <= y[1] and x[6] >= x[2] and y[6] >= y[2]) cout << "NO\n";
	else if(x[3] <= x[1] and x[5] <= x[1] and x[4] >= x[2] and x[6] >= x[2] and 
			((y[4] >= y[2] and y[5] <= y[1] and y[6] >= y[3]) or (y[6] >= y[2] and y[3] <= y[1] and y[5] <= y[4]))) cout << "NO\n";
	else if(y[4] >= y[2] and y[3] <= y[1] and y[6] >= y[2] and y[5] <= y[1] and 
			((x[3] <= x[1] and x[4] >= x[5] and x[6] >= x[2]) or (x[5] <= x[1] and x[6] >= x[3] and x[4] >= x[2]))) cout << "NO\n";
	else cout << "YES\n";
}
