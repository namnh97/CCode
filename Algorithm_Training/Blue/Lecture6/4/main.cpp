//https://www.urionlinejudge.com.br/judge/en/problems/view/1610
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

const int MAX = 10001;
int t, m, n, a, b;
int visited[MAX];
vector<int> adj[MAX];

bool dfs(int u) {
	visited[u] = 1;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (visited[v] == 1) return true;
		else if (visited[v] == 0) {
			if (dfs(v)) {
				return true;
			}
		}
	}
	visited[u] = 2;
	return false;
}

void clear() {
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < MAX; i++) {
		adj[i].clear();
	}
}

void solve() {
	cin >> t;
	while (t--) {
		clear();
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adj[a].pb(b);
		}
		bool loop = false;
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0) {
				loop = dfs(i);
				if (loop) break;
			}
		}
		cout << (loop ? "YES" : "NO") << endl;
	}
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

