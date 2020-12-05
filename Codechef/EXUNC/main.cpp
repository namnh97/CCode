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

const int MAX = 1e5;
void solve() {
	int n, m; cin >> n >> m;
	int *a = new int[n + 5];
	a[0] = MAX;
	set<int> start;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//a[i + 1] is not disible a[i]
		if (a[i] % a[i - 1] != 0) { 
			start.insert(i);
		}
	}
	a[n + 1] = MAX;
	while (m--) {
		int t; cin >> t;
		int ind;
		if (t == 1) {
			cin >> ind;
			int val; cin >> val; 
			a[ind] = val;
			if (a[ind] % a[ind - 1] != 0) {
				start.insert(ind);
			} else {
				start.erase(ind);
			}
			if (a[ind + 1] % a[ind] != 0) {
				start.insert(ind + 1);
			} else {
				start.erase(ind + 1);
			}
		} else {
			cin >> ind;
			set<int>::iterator res = upper_bound(start.begin(), start.end(), ind);
			res--;
			cout << *res << endl;
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


