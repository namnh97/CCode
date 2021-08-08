//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1549
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
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

struct Union {
    int *parents;
    int *size;

    Union(int N) {
        parents = new int[N];
        size = new int[N];
        for (int i = 0; i < N; i++) {
            parents[i] = i;
            size[i] = 1;
        }
    }

    int find(int u) {
        if (parents[u] != u) {
            parents[u] = find(parents[u]);
        }
        return parents[u];
    }

    void doUnion(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) {
            return;
        }
        if (size[pu] < size[pv]) {
            parents[pu] = pv;
            size[pv] +=  size[pu];
        } else {
            parents[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


void solve() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        Union *uni = new Union(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            uni->doUnion(u, v);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (uni->parents[i] == i) {
                res = max(res, uni->size[i]);
            }
        }
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
