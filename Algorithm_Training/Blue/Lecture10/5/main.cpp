//https://open.kattis.com/problems/shortestpath3
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 1001;
const int INF = 1e9;

struct Edge {
    int from;
    int to;
    int weight;
};

vector<Edge> graph;
int m, n, q, s;
int dist[MAX];

void Bellman(int src) {
    fill(dist, dist + MAX, INF);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : graph) {
            int u = edge.from;
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : graph) {
            int u = edge.from;
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = -INF;
            }
        }
    }
}

void solve() {
    while (cin >> n >> m >> q >> s && n >= 0 && m >= 0 && q >= 0 && s >= 0) {
        graph.clear();
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph.pb(Edge{u, v, w});
        }
        Bellman(s);
        for (int i = 0; i < q; i++) {
            int des; cin >> des;
            if (dist[des] == INF) {
                cout << "Impossible" << endl;
            } else if (dist[des] == -INF) {
                cout << "-Infinity" << endl;
            } else {
                cout << dist[des] << endl;
            }
        }
        cout << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}
