//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=499
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
#define MAX 1001
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

struct Edge {
	int source;
	int target;
	int weight;
	Edge(int source = 0, int target = 0, int weight = 0) {
		this->source = source;
		this->target = target;
		this->weight = weight;
	}
};
const int INF = 1e9;
vector<int> dist(MAX, INF);
vector<int> path(MAX, -1);
vector<Edge> graph;
int n, m;

void clear() {
	fill(dist.begin(), dist.end(), INF);
	fill(path.begin(), path.end(), -1);
	graph.clear();
}

bool BellmanFord(int s) {
	int u, v, w;
	dist[s] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < m; j++) {
			u = graph[j].source;
			v = graph[j].target;
			w = graph[j].weight;
			if (dist[u] != INF && (dist[u] + w < dist[v])) {
				dist[v] = dist[u] + w;
				path[v] = u;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		u = graph[i].source;
		v = graph[i].target;
		w = graph[i].weight;
		if (dist[u] != INF && (dist[u] + w < dist[v])) {
			return true;
		}
	}
	return false;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		clear();
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w;
			cerr << u << " " << v << " " << w << endl;
			graph.pb(Edge(u, v, w));
		}
		if (BellmanFord(0)) {
			cout << "possible" << endl;
		} else {
			cout << "not possible" << endl;
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

