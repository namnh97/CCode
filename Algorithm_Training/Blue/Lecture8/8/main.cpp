//https://www.spoj.com/problems/SAMER08A/#:~:text=SAMER08A%20%2D%20Almost%20Shortest%20Path&text=He%20defines%20the%20almost%20shortest,starting%20point%20to%20the%20destination.
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 501;
const int INF = 1e9;

struct Edge {
	int u, v, c;
};

vector<pii> graph1[MAX], graph2[MAX], graph[MAX];
int nVertexed, nEdges, src, des;

vector<int> dijkstra(int src, vector<pii> (&graph)[MAX]) {
	vector<int> dist(MAX, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({src, 0});
	dist[src] = 0;

	while (!pq.empty()) {
		pii top = pq.top(); pq.pop();
		int u = top.first;
		int w = top.second;
		if (dist[u] != w) continue;
		for (auto &it : graph[u]) {
			int v = it.first;
			int c = it.second;
			if (dist[v] > w + c) {
				dist[v] = w + c;
				pq.push({v, dist[v]});
			}
		}
	}
	return dist;
}

void solve() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> nVertexed >> nEdges && nVertexed != 0 && nEdges != 0) {
		cin >> src >> des;
		for (int i = 0; i < MAX; i++) {
			graph1[i].clear();
			graph2[i].clear();
			graph[i].clear();
		}

		for (int i = 0; i < nEdges; i++) {
			int u, v, c; cin >> u >> v >> c;
			graph1[u].pb({v, c});
			graph2[v].pb({u, c});
			
		}
		vector<int> distS = dijkstra(src, graph1);
		vector<int> distT = dijkstra(des, graph2);
		int shortestPath = distS[des];

		for (int u = 0; u < nVertexed; u++) {
			for (auto &it : graph1[u]) {
				int v = it.first;
				int c = it.second;
				if (shortestPath == distS[u] + c + distT[v]) {
					continue;
				}
				graph[u].pb({v, c});
			}
		}
		vector<int> dist = dijkstra(src, graph);

		if (dist[des] == INF) {
			cout << -1 << endl;
		} else {
			cout << dist[des] << endl;
		}
	}
}


int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
	freopen(argv[1], "r", stdin);
	#endif
	solve();
	return 0;
}

