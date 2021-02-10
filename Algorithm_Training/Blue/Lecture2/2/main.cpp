//https://codeforces.com/problemset/problem/387/B
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
	int n, m; cin >> n >> m;
	int a[n], b[m];
	int pos = min(n, m);

	fori (i, 0, n - 1) {
		cin >> a[i];
	}
	fori (i, 0, m - 1) {
		cin >> b[i];
	}

	bool ok;
	for (int i = pos; i >= 0; i--) {
		ok = false;
		for (int j = 0; j < i; j++) {
			if (a[j] > b[m - i + j]) {
				ok = true;
			}
		}
		if (!ok) {
			cout << n - i;
			return;
		}
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

