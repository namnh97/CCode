//https://www.hackerrank.com/challenges/primsmstsub/problem
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 3005;
const int INF = 1e9;
vector<pii> graph[MAX];
int dist[MAX];
bool visited[MAX];
int m, n;

struct Compare {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

void prims(int src ) {
    priority_queue<pii, vector<pii>, Compare> pq;
    dist[src] = 0;
    pq.push({src, 0});
    while (!pq.empty()) {
        int u = pq.top().first; pq.pop();
        visited[u] = true;
        for (auto &it : graph[u]) {
            int v = it.first;
            int c = it.second;
            if (visited[v] == true) continue;
            if (dist[v] <= c) continue;
            dist[v] = c;
            pq.push({v, dist[v]});
        }
    }
}

void solve() {
    cin >> n >> m;
    fill(dist, dist + MAX, INF);
    fill(visited, visited + MAX, false);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        // bool add = true;
        // pii t = make_pair(v, w);
        // for (int j = 0; j < graph[u].size(); ++j) {
        //     if (graph[u][j] == t) {
        //         if (w < graph[u][j].second) {
        //             graph[u][j].second = w;
        //             t = make_pair(u, w);
        //             int k;
        //             for (k = 0; k < graph[v].size() && graph[v][k] != t; ++k);
        //             graph[v][k].second = w;
        //         }
        //         add = false;
        //         break;
        //     }
        // }
        // if (add) {
            graph[u].push_back({v, w});
            graph[v].push_back(make_pair(u, w));
        // }
    }
    int s; cin >> s;
    prims(s);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] != INF) {
            res += dist[i];
        }
    }
    cout << res;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}