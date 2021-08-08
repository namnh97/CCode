//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1541
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX_N = 105;
const int INF = 1e8;

struct Edge {
    int u, v, c;
};

bool mark[MAX_N][MAX_N][MAX_N * 3];
vector<Edge> save, tmp;
vector<pii> graph[MAX_N];
bool visited[MAX_N];
int dist[MAX_N], path[MAX_N];
int cnt[MAX_N];
int n, m;

struct Compare {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};
int prims(int src, vector<Edge> &save) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = false;
        path[i] = -1;
    }

    priority_queue<pii, vector<pii>, Compare> pq;
    dist[src] = 0;
    pq.push({src, 0});
    while (!pq.empty()) {
        int u = pq.top().first; pq.pop();
        visited[u] = true;
        for (auto &it : graph[u]) {
            int v = it.first;
            int c = it.second;
            
            if (visited[v]) continue;
            if (mark[u][v][c]) continue;
            if (dist[v] <= c) continue;
            
            dist[v] = c;
            path[v] = u;
            
            pq.push({v, c});
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) { 
        if (dist[i] == INF) return -1;
    }

    for (int i = 1; i <= n; i++) {
        res += dist[i];
    }
    
    for (int i = 1; i <= n; i++) {
        int u = path[i];
        if (u != -1) {
            save.pb((Edge){u, i, dist[i]});
        }
    }
    return res;
}

void solve() {
    int t; cin >> t;
    while (t--) {
        for (int i = 1; i < MAX_N; i++) {
            for (int j = 1; j < MAX_N; j++) {
                for (int k = 1; k < MAX_N * 3; k++) {
                    mark[i][j][k] = false;
                }
            }
        }
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int u, v, c; cin >> u >> v >> c;
            cnt[u]++;
            cnt[v]++;
            graph[u].pb({v, c});
            graph[v].pb({u, c});
        }

        save.clear();

        int min0 = prims(1, save);

        cout << min0 << " ";

        int min1 = INF;

        for (int i = 0; i < save.size(); i++) {
            int u = save[i].u;
            int v = save[i].v;
            int c = save[i].c;

            mark[u][v][c] = mark[v][u][c] = true;
            cnt[u]--;
            cnt[v]--;

            tmp.clear();

            int x;
            for (int i = 1; i <= n; i++) {
                if (cnt[i]) {
                    x = i;
                    break;
                }
            }

            int K = prims(x, tmp);

            if (K >= 0) {
                min1 = min(min1, K);
            }

            mark[u][v][c] = mark[v][u][c] = false;
            cnt[u]++;
            cnt[v]++;
        }
        if (min1 == INF) {
            min1 = min0;
        }
        cout << min1 << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}