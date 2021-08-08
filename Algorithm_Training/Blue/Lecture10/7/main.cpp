//https://www.spoj.com/problems/UCV2013B/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

struct Edge {
    int u, v;
    ll weight;
};
const ll INF = (1LL<<30)*100;
const int MAX = 105;
ll dist[MAX][MAX];
string monuments[MAX];
vector<Edge> graph;
int n;

void Bellman(int src) {
    dist[src][src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : graph) {
            if (dist[src][edge.u] != INF && dist[src][edge.v] > dist[src][edge.u] + edge.weight) {
                dist[src][edge.v] = dist[src][edge.u] + edge.weight;
            }           
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : graph) {
            if (dist[src][edge.u] != INF && dist[src][edge.v] > dist[src][edge.u] + edge.weight) {
                dist[src][edge.v] = -INF;
            }           
        }
    }
}
void solve() {
    int tc = 0;
    while (cin >> n && n != 0 ) {
        graph.clear();
        for (int i = 0; i < n; i++) {
            cin >> monuments[i];
            for (int j = 0; j < n; j++) {
                ll w; cin >> w;
                dist[i][j] = INF;
                if (i != j && w == 0) {
                    continue;
                }
                if (i == j && w >= 0) {
                    w = 0;
                }
                graph.pb((Edge){i, j, w});
            }
        }
        for (int i = 0; i < n; i++) {
            Bellman(i);
        }
        int q; cin >> q;
        cout << "Case #" << ++tc << ":" << endl;
        while (q--) {
            int u, v; cin >> u >> v;
            if (dist[u][v] <= -INF) {
                cout << "NEGATIVE CYCLE" << endl;
            } else {
                cout << monuments[u] << "-" << monuments[v] << " ";
                if (dist[u][v] != INF) {
                    cout << dist[u][v] << endl;
                } else {
                    cout << "NOT REACHABLE" << endl;
                }
            }
        }   
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}
