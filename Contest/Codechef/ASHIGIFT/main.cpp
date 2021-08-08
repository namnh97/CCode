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

bool check(ll req, vector<pair<int, int>> &dishs, vector<pair<int, pair<int, int>>> &clans) {
	int i = 0, j = 0;
	while (i < (int)dishs.size() && j < (int)clans.size()) {
		if (dishs[i].first < clans[i].first) {
			req -= dishs[i].second;
			i++;
			if (req < 0) return false;
		} else {
			if (clans[j].second.first <= req) {
				req += clans[j].second.second;
			}
			j++;
		}
	}
	while (i < dishs.size()) {
		req -= dishs[i].second;
		i++;
		if (req < 0) return false;
	}
	return (req >= 1);
}
void solve() {
	int t, n, x, b;
	int xi, yi;
	cin >> t;
	vector<pair<int, int>> dishs;
	vector<pair<int, pair<int, int>>> clans;
	while (t--) {
		cin >> n;
		dishs.clear();
		clans.clear();
		cin >> x;
		cin >> b;
		ll req = 1;
		for (int i = 0; i < b; i++) {
			cin >> xi >> yi;
			dishs.pb({xi, yi});
			req += yi;
		}
		int c; cin >> c;
		for (int i = 0; i < c; i++) {
			int p, q, r; cin >> p >> q >> r;
			clans.pb({p, {q, r}});
		}
		sort(dishs.begin(), dishs.end());
		sort(clans.begin(), clans.end());
		ll left = 0, ans = req, right = req;
		while (left <= right) {
			ll mid = left + (right - left) / 2;
			if (check(mid, dishs, clans)) {
				ans = min(ans, mid);
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		cout << ans << endl;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


