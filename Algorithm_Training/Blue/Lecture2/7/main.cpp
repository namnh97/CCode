//https://codeforces.com/problemset/problem/892/B
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
	fori (i, 0, n - 1) {
		cin >> a[i];
	}
	int j = n - 1;
	int cnt = 0;
	int killPos;
	for (int i = n - 1; i >= 0; i--) {
		j = min(j, i);
		killPos = max(0, i - a[i]);
		if (killPos < j) {
			cnt += (j - killPos);		
			j = killPos;
		}
	}
	cout << n - cnt;
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

