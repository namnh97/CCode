//https://codeforces.com/problemset/problem/161/A
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

int n, m, x, y;
void solve() {
	cin >> n >> m >> x >> y;
	int a[n], b[m];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int i = 0, j = 0;
	vector<int> resa, resb;
	while (i < n && j < m) {
		if (a[i] - x > b[j]) {
			j++;
		}
		else if (a[i] + y < b[j]) {
			i++;
		} else {
			resa.pb(++i);
			resb.pb(++j);
		}
	}
	cout << resa.size() << endl;
	for (int i = 0; i < (int) resa.size(); i++) {
		cout << resa[i] << " " << resb[i] << endl;
	}
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

