//https://codeforces.com/problemset/problem/468/B
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define pii pair<int, int>
using namespace std;

const int MAX = 1e5 + 5;
int parent[MAX], fa[MAX], p[MAX];
int n, a, b;
map<int, int> mp;

int findRoot(int u) {
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = findRoot(parent[u]);
}

void doUnion(int u, int v) {
    int pu = findRoot(u);
    int pv = findRoot(v);
    if (pu == pv) return;
    parent[pu] = pv;
}

void solve() {
    while(scanf("%d%d%d", &n, &a, &b) == 3) {
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            int tmp; cin >> tmp;
            p[i] = tmp;
            mp[p[i]] = i;
            mx = max(mx, tmp);
        }

        if (mx >= max(a, b)) {
            cout << "NO" << endl;
            return;
        }

        for (int i = 0; i <= n + 1; i++) {
            parent[i] = i;
        }

        for (int i = 1; i <= n; i++) {
            if (mp[a - p[i]]) {
                doUnion(i, mp[a - p[i]]);
            } else {
                doUnion(i, n + 1);
            }

            if (mp[b - p[i]]) {
                doUnion(i, mp[b - p[i]]);
            } else {
                doUnion(i, 0);
            }
        }
        
        int A = findRoot(0);
        int B = findRoot(n + 1);

        if (A == B) {
            cout << "NO" << endl;
            return;
        }

        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            if (i != 1) cout << " ";
            if (findRoot(i) == A) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
        cout << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}