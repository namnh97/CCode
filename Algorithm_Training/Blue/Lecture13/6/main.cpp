//https://www.hackerrank.com/challenges/minimum-loss/problem
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
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
	pii a[n];
	for (int i = 0; i < n; i++) {
		a[i].first = i;
		cin >> a[i].second;
	}
	sort(a, a + n, [&](const pii& a, const pii& b) {
		return a.second > b.second;
	});
	ll res = LONG_MAX;
	for (int i = 1; i < n; i++) {
		if (a[i].first > a[i - 1].first) {
			res = min(res, a[i - 1].second - a[i].second);
		}
	}
	cout << res;
}



int main(int argc, char** argv){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}



