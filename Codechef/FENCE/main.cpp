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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
	int t; cin >> t;
	int n, m, k;
	while (t--) {
		cin >> n >> m >> k;
		int res = 0;
		int x[n], y[m];
		set<pair<int, int>> have;
		for (int i = 1; i <= k; i++) {
			cin >> x[i] >> y[i];
			if (have.find({x[i], y[i]}) != have.end()) {
				assert(0);
			}
			have.insert({x[i], y[i]});
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j < 4; j++) {
				pair<int, int> p = {x[i] + dx[j], y[i] + dy[j]};
				if (have.find(p) == have.end()) {
					res++;
				}
			}
		}
		cout << res << endl;
	}
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


