//https://www.urionlinejudge.com.br/judge/en/problems/view/1655
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
using namespace std;

struct Edge {
    int from;
    int to;
    double weight;
};

const int MAX = 105;
vector<Edge> graph;
double dist[MAX];
int n, m;

void Bellman(int s) {
    fill(dist, dist + MAX, -1.0);
    dist[s] = 1.0;
    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : graph) {
            int u = edge.from;
            int v = edge.to;
            double c = edge.weight;
            dist[u] = max(dist[u], dist[v] * c);
        }
    }
}

void solve() {
    while (cin >> n && n != 0) {
        cin >> m;
        graph.clear();
        for (int i = 0; i < m; i++) {
            int u, v, p; cin >> u >> v >> p;
            graph.pb((Edge){u, v, p / 100.0});
        }
        Bellman(1);
        cout << fixed << setprecision(6) << dist[n] * 100.0 << " percent" << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


