//https://codeforces.com/problemset/problem/242/B
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
	int l, r;
	int index = 1;
	int minl = INT_MAX, maxr = INT_MIN;
	int al[n + 1], ar[n + 1];
	fori (i, 1, n) {
		cin >> al[i] >> ar[i];
		if (al[i] <= minl && ar[i] >= maxr) {
			index = i;
		}
		minl = min(al[i], minl);
		maxr = max(ar[i], maxr);
	}
	if (al[index] <= minl && ar[index] >= maxr) {
		cout << index;
	} else {
		cout << -1;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


