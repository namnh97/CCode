#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 50001;

int parent[MAX];
int ranks[MAX];

void makeSet() {
    for (int i = 1; i <= MAX; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v) { 
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) {
        return;
    }
    if (ranks[pu] > ranks[pv]) {
        parent[pv] = pu;
    } else if (ranks[pu] < ranks[pv]) {
        parent[pu] = parent[pv];
    } else {
        parent[pu] = pv;
        ranks[pv]++;
    }
}

void solve() {
    int n, m;
    int cas = 0;
    while (cin >> n >> m && n != 0 && m != 0) {
        makeSet();
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            unionSet(u, v);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (parent[i] == i) {
                res++;
            }
        }
        cout << "Case " << ++cas << ": ";
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


