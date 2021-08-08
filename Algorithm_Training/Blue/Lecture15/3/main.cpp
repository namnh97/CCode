//https://www.spoj.com/problems/CSTREET/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 1001;
const int INF = 1e9;
int cost, n, m;
vector<pair<int, int>> graph[MAX];
int visited[MAX];
int dist[MAX];

void init() {
    fill(visited, visited + MAX, false);
    fill(dist, dist + MAX, INF);
    for (int i = 0; i < MAX; i++) {
        graph[i].clear();
    }
}

struct Compare {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};


void prims(int src) {
    priority_queue<pii, vector<pii>, Compare> pq;
    dist[src] = 0;
    pq.push({src, 0});
    while (!pq.empty()) {
        int u = pq.top().first; pq.pop();
        visited[u] = true;
        for (auto &it : graph[u]) {
            int v = it.first;
            int w = it.second;
            if (visited[v] == false && dist[v] > w) {
                dist[v] = w;
                pq.push({v, dist[v]});
            }
        }
    }
}

void solve() {
    int t; cin >> t;
    while (t--) {
        cin >> cost >> n >> m;
        init();
        for (int i = 0; i < m; i++) {
            int u, v, l;
            cin >> u >> v >> l;
            graph[u].pb({v, l});
            graph[v].pb({u, l});
        }
        prims(1);
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) continue;
            res += dist[i] * cost;
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