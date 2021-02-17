//https://www.spoj.com/problems/LOSTNSURVIVED/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 100005;
int N, Q;
int parent[MAX], sz[MAX];
int maxi = 0;
priority_queue<pii,vector<pii>, greater<pii>> mnPQ;

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
    sz[pu] += sz[pv];
    parent[pv] = pu;
    mnPQ.push({sz[pu], pu});
    maxi = max(maxi, sz[pu]);
}

void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        sz[i] = 1;
        parent[i] = i;
        mnPQ.push({sz[i], i});
    }
    maxi = 1;
    for (int i = 1; i <= Q; i++) {
        int u, v; cin >> u >> v;
        doUnion(u, v);
        while (1) {
            pii tmp = mnPQ.top();
            int root = findRoot(tmp.second);
            if (root != tmp.second) {
                mnPQ.pop();
                continue;
            }
            if (sz[root] != tmp.first) {
                mnPQ.pop();
                continue;
            }
            break;
        }
        cout << maxi - mnPQ.top().first << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}