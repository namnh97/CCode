//https://codeforces.com/problemset/problem/557/B
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
	int n, w; cin >> n >> w;
	int a[2 * n];
	fori (i, 0, 2 * n - 1) {
		cin >> a[i];
	}
	sort(a, a + 2 * n);
	double m = min(1.0 * a[0], 1.0 * a[n] / 2);
	double total = 3 * m *n; 
	cout << setprecision(9) << min(total, 1.0 * w);
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

