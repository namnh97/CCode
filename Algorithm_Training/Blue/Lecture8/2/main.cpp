//https://www.spoj.com/problems/MICEMAZE/
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define pii pair<int, int>
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

const int MAX = 101;
vector<pii> edge[MAX];
int dist[MAX];
int n, e, t, m;

struct Compare {
	bool operator() (const pii &a, const pii &b) const {
		return a.second > b.second;
	}
};

void dijkstra(int source) {
	for (int i = 0; i < MAX; i++) {
		dist[i] = INT_MAX;
	}

	priority_queue<pii, vector<pii>, Compare> pq;
	pq.push({source, 0});
	dist[source] = 0;
	while (!pq.empty()) {
		int u = pq.top().first;
		int w = pq.top().second;
		pq.pop();
		if (dist[u] != w) continue;
		for (int i = 0; i < (int)edge[u].size(); i++) {
			int v = edge[u][i].first;
			int cost = edge[u][i].second;
			if (dist[v] > w + cost) {
				dist[v] = w + cost;
				pq.push({v, dist[v]});
			}
		}
	}
}

void solve() {
	cin >> n >> e >> t >> m;
	fori (i, 1, m) {
		int a, b, cost;
		cin >> a >> b >> cost;
		edge[b].pb({a, cost});
	}
	dijkstra(e);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] <= t) ans++;
	}
	cout << ans;
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

