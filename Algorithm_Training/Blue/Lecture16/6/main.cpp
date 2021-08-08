//https://codeforces.com/problemset/problem/104/C
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 105;
int parent[MAX];

int findRoot(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void doUnion(int u, int v) {
    int pu = findRoot(u);
    int pv = findRoot(v);
    parent[pu] = pv;
}

void solve() {
    int n, m; cin >> n >> m;
    if (m != n) {
        cout << "NO";
        return;
    }   
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        doUnion(u, v);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            res++;
        }
    }
    if (res > 1) {
        cout << "NO";
    } else {
        cout << "FHTAGN!";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}