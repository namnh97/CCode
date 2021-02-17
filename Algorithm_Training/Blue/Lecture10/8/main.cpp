//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=364
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 105;
const int INF = INT_MAX;
struct Edge {
    int u, v, w;
};
vector<Edge> graph;
int dist[MAX];
int n;

void Bellman(int s) {
    fill(dist, dist + MAX, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : graph) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            string tmp; cin >> tmp;
            if (tmp != "x") {
                int w = atoi(tmp.c_str());
                graph.pb({i, j, w});
                graph.pb({j, i, w});
            }
        }
    }
    Bellman(1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dist[i]);
    }
    cout << res << endl;
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}