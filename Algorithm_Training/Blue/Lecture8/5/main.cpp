//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1927
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
using namespace std;

const ll INF = LONG_MAX;
const int MAX = 20001;

vector<pii> graph[MAX];
ll dist[MAX];
int nVertexes, nEdges, src, des;

ll dijkstra(int src, int des) {
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({src, 0});
    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int u = top.first;
        int w = top.second;
        if (w != dist[u]) continue;
        for (auto &it : graph[u]) {
            int v = it.first;
            int c = it.second;
            if (dist[v] > w + c) {
                dist[v] = w + c;
                pq.push({v, dist[v]});
            }
        }
    }
    return dist[des];
}
void solve() {
    int nTests; cin >> nTests;
    for (int cas = 1; cas <= nTests; cas++) {
        cout << "Case #" << cas << ": ";
        for (int i = 0; i < MAX; i++) {
            graph[i].clear();
            dist[i] = INF;
        }

        cin >> nVertexes >> nEdges >> src >> des;
        for (int i = 0; i < nEdges; i++) {
            int u, v, c; cin >> u >> v >> c;
            graph[u].pb({v, c});
            graph[v].pb({u, c});
        }
        ll res = dijkstra(src, des);
        if (res == LONG_MAX) {
            cout << "unreachable" << endl;
        } else {
            cout << res << endl;
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


