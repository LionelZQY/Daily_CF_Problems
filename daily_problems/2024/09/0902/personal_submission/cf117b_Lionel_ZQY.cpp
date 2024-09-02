#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 num = 1000000000;

void solve(){
	i64 s1, s2, mod;
	cin >> s1 >> s2 >> mod;

	vector<i64> mp(mod + 1, -1);
	vector<bool> ok(mod + 1);

	for(i64 i = 0; i <= min(s1, mod); i++){
		i64 idx = i * num % mod;
		if(mp[idx] == -1) mp[idx] = i;
		else mp[idx] = min(mp[idx], i);
	}

	for(i64 i = 0; i <= min(s2, mod); i++){
		i64 idx = i % mod;
		ok[(mod - idx) % mod] = true;
	}

	i64 win = 2, ans = 1e18;
	for(int i = 0; i < mod; i++){
		if(mp[i] == -1) continue;
		if(!ok[i]){
			win = 1;
			ans = min(ans, mp[i]);
		}
	}

	cout << win << " ";
	vector<int> res;
	if(win == 1){
		for(int i = 1; i <= 9; i++){
			res.push_back(ans % 10);
			ans /= 10;
		}
		reverse(res.begin(), res.end());
		for(auto x : res){
			cout << x;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t = 1;
	while(t--){
		solve();
	}
	return 0;
}
