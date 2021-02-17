//https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/monks-business-day/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 101;
const int INF = 1e9;

struct Edge {
    int u, v, w;
};
int n, m;
vector<Edge> graph;
int dist[MAX];

bool Bellman(int src) {
    fill(dist, dist + MAX, -INF);
    dist[src] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (auto &edge : graph) {
            if (dist[edge.u] != -INF && dist[edge.v] < dist[edge.u] + edge.w) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }
    for (auto &edge : graph) {
        if (dist[edge.u] != -INF && dist[edge.v] < dist[edge.u] + edge.w) {
            return true;
        }
    }
    return false;
}
void solve() {
    int t; cin >> t;
    while (t--) {
        graph.clear();
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph.pb((Edge){u, v, w});
        }
        if (Bellman(1)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
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