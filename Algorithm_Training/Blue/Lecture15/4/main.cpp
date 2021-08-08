//https://lightoj.com/problem/road-construction
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 105;
const int INF = 1e7;
int cnt, n;
vector<pii> graph[MAX];
map<string, int> id;
int dist[MAX];
bool visited[MAX];

void clear() {
    fill(dist, dist + MAX, INF);
    fill(visited, visited + MAX, false);
    for (int i = 0; i < MAX; i++) {
        graph[i].clear();
    }
    id.clear();
    cnt = 0;
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
    for (int cas = 1; cas <= t; cas++) {
        clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            string u, v;
            int c;
            cin >> u >> v >> c;
            if (id.find(u) == id.end()) id[u] = cnt++;
            if (id.find(v) == id.end()) id[v] = cnt++;
            int src = id[u], des = id[v];
            graph[id[u]].pb({id[v], c});
            graph[id[v]].pb({id[u], c});
        }
        prims(0);
        int res = 0;
        for (int i = 0; i < cnt; i++) {
            res += dist[i];
        }
        cout << "Case " << cas << ": ";
        if (res >= INF) {
            cout << "Impossible" << endl;
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