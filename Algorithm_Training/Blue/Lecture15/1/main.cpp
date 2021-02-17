//https://www.spoj.com/problems/MST/
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
void debugOut() {
    cerr << endl;
}

const int MAX = 10005;
const int INF = 1e9;

struct Compare {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};
vector<int> dijkstra(int src, vector<pii> (&graph)[MAX]) {
    priority_queue<pii, vector<pii>, Compare> pq;
    pq.push({src, 0});
    vector<int> dist(MAX, INF);
    vector<bool> visited(MAX, false);
    dist[src] = 0;
    
    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int u = top.first;
        visited[u] = true;

        for (auto &it : graph[u]) {
            int v = it.first;
            int w = it.second;
            if (visited[v] == false && dist[v] > w) {
                dist[v] = w;
                pq.push({v, w});
            }
        }
    }
    return dist;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pii> graph[MAX];
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        graph[u].pb({v, c});
        graph[v].pb({u, c});
    }
    vector<int> dist = dijkstra(1, graph);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) continue;
        res +=  dist[i];
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
