//https://codeforces.com/problemset/problem/337/D
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
using namespace std;

const int INF = 1e9;

void dfs(vector<vector<int>> &graph, vector<bool> affectedPlaces, vector<int> &dist, int u, int d) {
    dist[u] = -INF;
    if (affectedPlaces[u]) {
        dist[u] = d;
    }
    
    for(auto it : graph[u]) {
        if (dist[it] == -1) {
            dfs(graph, affectedPlaces, dist, it, d + 1);
        }
    }
}

void solve() {
    int n, m, d; cin >> n >> m >> d;
    vector<bool> affectedPlaces(n);

    for (int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        affectedPlaces[tmp - 1] = true;   
    }

    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    vector<int> distV(n, -1), distU(n, -1);
    dfs(graph, affectedPlaces, distU, 0, 0);
    int u = std::max_element(distU.begin(), distU.end()) - distU.begin();
    dfs(graph, affectedPlaces, distV, u, 0);
    int v = std::max_element(distV.begin(), distV.end()) - distV.begin();

    vector<int> dist1(n, -1);
    vector<int> dist2(n, -1);
    dfs(graph, vector<bool>(n, true), dist1, u, 0);
    dfs(graph, vector<bool>(n, true), dist2, v, 0);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (max(dist1[i], dist2[i]) <= d) {
            res++;
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


