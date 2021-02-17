//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=989
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 101;
const int INF = 1e9;
int C, S, Q;
bool visited[MAX];
int dist[MAX];
int path[MAX];
vector<pii> graph[MAX];
vector<pii> mxGraph[MAX];

void clear() {
    for (int i = 1; i <= C; i++) {
        graph[i].clear();
        mxGraph[i].clear();
        visited[i] = false;
        path[i] = -1;
        dist[i] = INF;
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
            int c = it.second;
            
            if (visited[v] == true) continue;
            if (dist[v] <= c) continue;

            dist[v] = c;
            path[v] = u;
            pq.push({v, dist[v]});
        }
    }

    for (int u = 1; u <= C; u++) {
        if (path[u] != -1) {
            int v = path[u];
            int c = dist[u];
            mxGraph[v].pb({u, c});
            mxGraph[u].pb({v, c});
        }
    }
}


int dfs(int src, int des, int level) {
    if (src == des) { 
        return level;
    }
    visited[src] = true;
    for (auto &it : mxGraph[src]) {
        int v = it.first;
        int c = it.second;
        if (visited[v] == false) {
            int tmpLevel = dfs(v, des, max(level, c));
            if (tmpLevel != INF) {
                return tmpLevel;
            }
        }
    }
    return INF;
}

void solve() {
    int tc = 1;
    while (1) {
        cin >> C >> S >> Q;
        if (C == 0 && S == 0 && Q == 0) {
            break;
        }

        clear();

        for (int i = 0; i < S; i++) {
            int u, v, c; cin >> u >> v >> c;
            graph[u].pb({v, c});
            graph[v].pb({u, c});
        }

        for (int i = 1; i <= C; i++) {
            if (visited[i] == false) {
                prims(i);
            }
        }

        if (tc != 1) {
            cout << endl;
        }
        cout << "Case #" << tc++ << endl;

        for (int i = 0;  i < Q; i++) {
            int u, v; cin >> u >> v;
            fill(visited, visited + MAX, false);
            int res = dfs(u, v, 0);
            if (res != INF) {
                cout << res;
            } else {
                cout << "no path";
            }
            cout << endl;
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