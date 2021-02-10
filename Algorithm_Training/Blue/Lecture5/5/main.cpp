//https://codeforces.com/problemset/problem/580/C
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

const int MAX = 100001;
int n, m, a[MAX], ans;
int cnt[MAX];
bool vis[MAX];
vector<int> vec[MAX];


int bfs(int x) {
	memset(vis, false, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	int ans = 0;
	vis[x] = true;
	if(a[x] == 1) cnt[x] = 1;
	queue<int> q;
	q.push(x);

	while(!q.empty()) {
		int u = q.front(); q.pop();
		for (auto &it : vec[u]) {
			if (vis[it] == false) {
				vis[it] = true;
				if (a[it] == 1) {
					cnt[it] = cnt[u] + 1;
				}
				if (cnt[it] <= m) {
					if (vec[it].size() == 1) {
						ans++;
					} else {
						q.push(it);
					}
				}
			}
		}
	}
	return ans;
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].pb(v);
		vec[v].pb(u);
	}
	int ans = bfs(1);
	cout << ans;
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

