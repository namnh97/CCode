#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 1e6;
const int INF = 1e9;
int n, m;
vector<pii> graph[MAX];
int dist[MAX];
bool visited[MAX];

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
            pq.push({v, dist[v]});
        }
    }
}
void solve() {
    cin >> n >> m;

    for (int i = 0; i < MAX; i++) {
        graph[i].clear();
        visited[i] = false;
        dist[i] = INF;
    }

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].pb({v, c});
        graph[v].pb({u, c});
    }

    prims(1);

    priority_queue<int> mxQueue;
    for (int i = 2; i <= n; i++) {
        mxQueue.push(dist[i]);
    }
    int q; cin >> q;

    priority_queue<int, vector<int>, greater<int>> cables;
    for (int i = 1; i <= q; i++) {
        int newcable;
        cin >> newcable;
        cables.push(newcable);
    }

    ll res = 0;
    while (!mxQueue.empty()) {
        int cable = mxQueue.top();
        mxQueue.pop();

        while (!cables.empty() && cables.top() < cable) {
            cable = cables.top();
            cables.pop();
        }
        res += cable;
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