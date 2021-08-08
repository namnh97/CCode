//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1498
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 101;
const int INF = 1e9;
int dist[MAX], cost[MAX];
bool visited[MAX];
vector<pii> graph;
int n;

bool hasPath(int s, int f) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (pii &edge : graph) {
            if (edge.first == u) { //u -> edge.second;
                int v = edge.second;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    if (v == f) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool bellMan(int s, int f) {
    memset(dist, -INF, sizeof(dist));
    dist[s] = 100;
    for (int i = 1; i <= n - 1; i++) {
        for (pii &edge : graph) {
            int u = edge.first;
            int v = edge.second;
            if (dist[u] > 0) {
                dist[v] = max(dist[v], dist[u] + cost[v]);
            }
        }
    }
    for (pii & edge : graph) {
        int u = edge.first;
        int v = edge.second;
        if (dist[u] > 0 &&  dist[u] + cost[v] > dist[v] && hasPath(u, f)) {
            return true;
        }
    }
    return dist[f] > 0;
}


void solve() {
    while (cin >> n && n != -1) {
        graph.clear();
        for (int i = 1; i <= n; i++) {
            cin >> cost[i];
            int numberOfAdj; cin >> numberOfAdj;
            for (int j = 0; j < numberOfAdj; j++) {
                int adj; cin >> adj;
                graph.push_back({i, adj});
            }
        }
        if (bellMan(1, n)) {
            cout << "winnable" << endl;
        } else {
            cout << "hopeless" << endl;
        }
    }
}



int main(int arc, char **argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}
