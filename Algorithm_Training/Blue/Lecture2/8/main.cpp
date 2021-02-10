//https://codeforces.com/problemset/problem/6/C
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
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i = 0, j = n - 1;
	int alice = 0, bob = 0;
	int cnt = 0;
	while (i <= j) {
		if (alice <= bob) {
			alice += a[i++];
			cnt++;
		} else {
			bob += a[j--];
		}
	}
	cout << cnt << " " << n - cnt;
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

