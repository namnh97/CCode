//https://codeforces.com/problemset/problem/279/B
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
void debugOut() {
	cerr << endl;
}

void solve() {
	int n, t; cin >> n >> t;
	int a[n + 2], sum[n + 2];
	sum[0] = 0;
	fori (i, 1, n) {
		cin >> a[i];
		sum[i] = (sum[i - 1] + a[i]);
	}
	int j = n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			if (sum[j] - sum[i - 1] <= t) {
				ans = max(ans, j - i + 1);
				break;
			}
		}
	}
	cout << ans;
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

