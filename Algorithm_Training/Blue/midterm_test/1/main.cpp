#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
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
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		queue<pii> jobs;
		vector<int> sorted;
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp;
			jobs.push({tmp, i});
			sorted.pb(tmp);
		}
		sort(sorted.begin(), sorted.end(), greater<int>());
		int res = 0;
		while (!jobs.empty()) {
			pii t = jobs.front(); jobs.pop();
			if (t.first == sorted[0]) {
				res++;
				sorted.erase(sorted.begin());
				if (t.second == m) break;
			} else {
				jobs.push(t);
			}
		}
		while (!jobs.empty()) jobs.pop();
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
