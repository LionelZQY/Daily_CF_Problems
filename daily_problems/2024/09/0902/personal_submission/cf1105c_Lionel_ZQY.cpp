#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve(){
	i64 la, ra, ta, lb, rb, tb;
	cin >> la >> ra >> ta >> lb >> rb >> tb;

	if(la > lb){
		swap(la,lb);
		swap(ra,rb);
		swap(ta,tb);
	}

	i64 m = gcd(ta, tb);

	i64 t = lb - ((lb - la) % m);
	ra = t + (ra - la);
	la = t;

	cout << max({0LL, min(ra, rb) - max(la, lb) + 1, min(ra + m ,rb) - max(la + m, lb) + 1}) << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
