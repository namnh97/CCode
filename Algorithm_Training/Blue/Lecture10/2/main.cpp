//https://lightoj.com/problem/extended-traffic
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
using namespace std;

// #define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) {
// 	cerr << *it << " = " << a << endl;
// 	err(++it, args...);
// }
// void debugOut() {
// 	cerr << endl;
// }

const int MAX = 201;
const int INF = 1e9;
struct Edge {
	int src;
	int des;
	ll cost;
	Edge(int src = 0, int des = 0, ll cost = 0) {
		this->src = src;
		this->des = des;
		this->cost = cost;
	}
};

vector<ll> dist(MAX, INF);
vector<int> path(MAX, -1);
vector<Edge> graph;
int n, m;


void clear() {
	for (int i = 0; i < MAX; i++) {
		dist[i] = INF;
		path[i] = -1;
	}
	graph.clear();
}


bool BellmanFord(int src) {
	int u, v;
	ll w;
	dist[src] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < m; j++) {
			u = graph[j].src;
			v = graph[j].des;
			w = graph[j].cost;
			if (dist[u] != INF && (dist[u] + w < dist[v])) {
				dist[v] = dist[u] + w;
				path[v] = u;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		u = graph[i].src;
		v = graph[i].des;
		w = graph[i].cost;
		if (dist[u] != INF && (dist[u] + w < dist[v])) {
			return false;
		}
	}
	return true;}

void solve() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ":" << endl;
		clear();
		cin >> n;
		int a[n + 1];
		fori (i, 1, n) {
			cin >> a[i];
		}
		cin >> m;
		fori (i, 1, m) {
			int u, v; cin >> u >> v;
			ll tmp = a[v] - a[u];
			graph.pb(Edge(u, v, tmp * tmp * tmp));
		}
		int q; cin >> q;
		BellmanFord(1);
		while (q--) {
			int des; cin >> des;
			if (dist[des] > 2 && dist[des] != INF) cout << dist[des] << endl;
			else cout << "?" << endl;
		}
	}
}



int main(void){
	// #ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
	// #endif
	solve();
	return 0;
}

