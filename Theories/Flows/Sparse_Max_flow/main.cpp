#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

struct Edge {
	int u, v;
	long long cap, flow; //capacity and flow
	Edge() {}
	Edge(int u, int v, long long cap) : u(u), v(v), cap(cap), flow(0) {}
};


struct Dinic {
	int N;
	vector<Edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;
	Dinic(int N) : N(N), E(0), g(N), d(N), pt(N) {}
	void addEdge(int u, int v, long long cap) { 
		if (u != v) { 
			E.emplace_back(Edge(u, v, cap));
			g[u].emplace_back(E.size() - 1);
			E.emplace_back(Edge(v, u, 0));
			g[v].emplace_back(E.size() - 1);
		}
	}

	bool BFS(int S, int T) {
		queue<int> q({S});
		fill(d.begin(), d.end(), N + 1);
		d[S] = 0;
		while (!q.empty()) { 
			int u = q.front(); q.pop();
			if (u == T) break;
			for (int k : g[u]) {
				Edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
					d[e.v] = d[e.u] + 1;
					q.emplace(e.v);
				}
			}
		}
		return d[T] != N + 1;
	}
	long long DFS(int u, int T, long long flow = -1) {
		if (u == T || flow == 0) return flow;
		for (int &i = pt[u]; i < (int)g[u].size(); i++) {
			Edge &e = E[g[u][i]];
			Edge &oe = E[g[u][i] ^ 1];
			if (d[e.v] == d[e.u] + 1) {
				long long amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (long long pushed = DFS(e.v, T, amt)) { 
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	long long maxFlow(int S, int T) { 
		long long total = 0;
		while (BFS(S, T)) {
			fill(pt.begin(), pt.end(), 0); //avoid repeat the loop of previous elements
			while (long long flow = DFS(S, T)) {
				total += flow;
			}
		}
		return total;
	}
};



int main(void){
	int N, E;
	cin >> N >> E;
	Dinic dinic(N);
	for (int i = 0; i < E; i++) {
		int u, v;
		long long cap;
		cin >> u >> v >> cap;
		dinic.addEdge(u - 1, v - 1, cap);
		dinic.addEdge(v - 1, u - 1, cap);
	}
	cout << dinic.maxFlow(0, N - 1);
	return 0;
}
