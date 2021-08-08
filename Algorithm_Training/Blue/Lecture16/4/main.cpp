//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1099
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 10000;
int parent[MAX * 2];

int findRoot(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return parent[u];
}

void doUnion(int u, int v) {
    int pu = findRoot(u);
    int pv = findRoot(v);
    parent[pu] = pv;
}

void solve() {
    int t; cin >> t;
    for (int i = 0; i < MAX * 2; i++) {
        parent[i] = i;
    }
    while (true) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0 && x == 0 && y == 0) {
            break;
        }
        if (c == 1) {
            if (findRoot(x) == findRoot(y + MAX)) {
                cout << -1 << endl;
                continue;
            }
            doUnion(x, y);
            doUnion(x + MAX, y + MAX);
        } else if (c == 2) {
            if (findRoot(x) == findRoot(y)) {
                cout << -1 << endl;
                continue;
            }
            doUnion(x, y + MAX);
            doUnion(x + MAX, y);
        } else if (c == 3) {
            if (findRoot(x) == findRoot(y)) {
                cout << 1 << endl;
                continue;
            }
            cout << 0 << endl;
        } else {
            if (findRoot(x) == findRoot(y + MAX)) {
                cout << 1 << endl;
                continue;
            }
            cout << 0 << endl;
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