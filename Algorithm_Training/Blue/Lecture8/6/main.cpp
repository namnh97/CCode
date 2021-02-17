//https://lightoj.com/problem/commandos
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 101;
const int INF = 1e9;
int nBuildings, nRoads, src, des;
vector<int> graph[MAX];
int distS[MAX], distT[MAX];

vector<int> dijkstra(int src) {
    vector<int> dist(MAX, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({src, 0});
    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int u = top.first;
        int w = top.second;
        if (w != dist[u]) continue;
        for (auto &it : graph[u]) {
            int v = it;
            if (dist[v] > w + 1) {
                dist[v] = w + 1;
                pq.push({v, dist[v]});
            }
        }
    }
    return dist;
}

void solve() {
    int nTests; cin >> nTests;
    for (int cas = 1; cas <= nTests; cas++) {
        cout << "Case " << cas << ": ";
        cin >> nBuildings >> nRoads;
        for (int i = 0; i < MAX; i++) {
            graph[i].clear();
        }
        for (int i = 0; i < nRoads; i++) {
            int u, v; cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        cin >> src >> des;
        vector<int> distS = dijkstra(src);
        vector<int> distT = dijkstra(des);
        int res = 0;
        for (int i = 0; i < nBuildings; i++) {
            res = max(res, distS[i] + distT[i]);
        }
        cout << res << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


