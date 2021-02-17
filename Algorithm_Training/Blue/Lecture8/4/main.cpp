//https://www.spoj.com/problems/TRAFFICN/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 10005;
const int INF = 1e9;
vector<pii> graphS[MAX];
vector<pii> graphT[MAX];
int distT[MAX], distS[MAX];
int nVertex, nEdge, src, des, nAdditionalRoad;


void dijkstra(int s, int dist[], vector<pii> (&graph)[MAX]) {
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({s, 0});
    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int u = top.first;
        int w = top.second;
        if (w > dist[u]) {
            continue;
        }
        for (auto &it : graph[u]) {
            int v = it.first;
            int c = it.second;
            if (dist[v] > w + c) {
                dist[v] = w + c;
                pq.push({v, dist[v]});
            }
        }
    }

}

void solve() {
    int nTests; cin >> nTests;
    while (nTests--) {
        int u, v, c;
        for (int i = 0; i < MAX; i++) {
            graphS[i].clear();
            graphT[i].clear();
            distT[i] = INF;
            distS[i] = INF;
        }
        cin >> nEdge >> nVertex >> nAdditionalRoad >> src >> des;
        for (int i = 0; i < nVertex; i++) {
             cin >> u >> v >> c;
            graphS[u].pb({v, c});
            graphT[v].pb({u, c});
        }
        dijkstra(src, distS, graphS);
        dijkstra(des, distT, graphT);
        int res = distS[des];
        for (int i = 0; i < nAdditionalRoad; i++) {
            cin >> u >> v >> c;
            int first = distS[u] + c + distT[v];
            int second = distS[v] + c + distT[u];
            res = min(res, min(first, second));
        }
        if (res == INF) {
            cout << -1 << endl;
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