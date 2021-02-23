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
const int MAX = 20000;

int t;
int a[MAX], b[MAX];
int q, k;
int query, cur;

void solve() {
	cin >> t;
	while (t--) {
		cin >> k >> q;
		vector<pair<int, int>> queries;
		fori(i, 1, k) {
			cin >> a[i];
		}
		fori(i, 1, k) {
			cin >> b[i];
		}
		fori(i, 1, q) {
			int tmp; cin >> tmp;
			queries.pb({tmp, i});
		}
		//sort a, b arrays and queries
		sort(a + 1, a + k + 1);
		sort(b + 1, b + k + 1);
		sort(queries.begin(), queries.end(), [](pair<int, int> a, pair<int, int> b) {
			return a.first < b.first;
		});
		priority_queue<pair<ll, int>> sums;
		int ptr[MAX];
		fori(i, 1, k) {
			ptr[i] = 1;
			sums.push({-a[i] - b[1], i});
		}
		int ans[MAX];
		int count = 0;
		int cur, x;
		for (int i = 0; i < (int)queries.size(); i++) {
			while (count <= queries[i].first) {
				cur = abs(sums.top().first);
				x = sums.top().second;
				debug(cur, a[x], b[ptr[x]]);
				debugOut();
				ptr[x]++;
				sums.pop();
				if (ptr[x] <= k) {
					sums.push({-a[x] - b[ptr[x]], x});
				}
				count++;
			}
			ans[queries[i].second] = cur;
		}
		fori (i, 1, q) {
			cout << ans[i] << endl;
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


