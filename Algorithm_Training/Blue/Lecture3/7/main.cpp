// https://codeforces.com/problemset/problem/149/A
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
	int k, a[12];
	cin >> k;
	int impossible = 0;
	fori (i, 0, 11) {
		cin >> a[i];
		impossible += a[i];
	}
	sort(a, a + 12, greater<int>());
	int res = 0;
	fori (i, 0, 11) {
		if (k <= 0) break;
		k -= a[i];
		res++;
	}
	cout << (k <= 0) ? res : -1;
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

