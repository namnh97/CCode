//https://www.spoj.com/problems/BENEFACT/
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

const int MAX = 50000 + 5;
int t, leaf;
int E, V;
vector<pii> graph[MAX];
ll  dist[MAX];
ll maxDist;

void DFS(int index) {
    memset(dist, -1, sizeof(dist));
    stack<int> s;
    s.push(index);
    dist[index] = 0;
    while(!s.empty()) {
        int u = s.top(); s.pop();
        for (auto &it : graph[u]) {
            int v = it.first;
            int du = it.second;
            if (dist[v] == -1) {
                dist[v] = dist[u] + du;
                s.push(v);
                if (dist[v] > maxDist) {
                    maxDist = dist[v];
                    leaf = v;
                }
            }
        }
    }

}

void clear() {
    maxDist = 0;
    for (int i = 0; i <= V; i++) {
        graph[i].clear();
    }
}

void solve() {
    cin >> t;
    while (t--) {
        cin >> V;
        E = V - 1;
        clear();
        for (int i = 0; i < E; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            graph[u].pb({v, c});
            graph[v].pb({u, c});
        }

        DFS(1);
        DFS(leaf);

        cout << maxDist << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


