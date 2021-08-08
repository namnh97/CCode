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


bool cmp(const pair<int, int> &a, const pair<int, int>  &b) {
	return a.second < b.second;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int ,int>> a, b;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		a.pb(mp(i, tmp));
	}
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		b.pb(mp(i, tmp));
	}
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	for(auto &it : a) {
		debug(it.first, it.second);
	}
	for (int i = 0; i < m; i++) {
		cout << a[0].first << " " << b[i].first << endl;
	}
	for (int i = 1; i < n; i++) {
		cout << a[i].first << " " << b[m - 1].first << endl;
	}
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


