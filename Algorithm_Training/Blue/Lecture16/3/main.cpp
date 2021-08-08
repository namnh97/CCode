//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1168
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 105;
int parent[MAX], ranks[MAX];
set<int> trees[MAX];

int findRoot(int u) {
    if (u != parent[u]) {
        parent[u] = findRoot(parent[u]);
    }
    return parent[u];
}


void doUnion(int u, int v) {
    int pu = findRoot(u);
    int pv = findRoot(v);
    if (pu == pv) return;
    if (ranks[pu] > ranks[pv]) {
        parent[pv] = pu;
    } else if (ranks[pu] < ranks[pv]) {
        parent[pu] = pv;
    } else {
        parent[pu] = pv;
        ranks[pv]++;
    }
}

void solve() {
    int t; cin >> t;
    while (t--) {
        string in;
        int P, T; cin >> P >> T;
        cin.ignore();
        while (getline(cin, in) && !in.empty()) {
            stringstream ss(in);
            int person, tree;
            ss >> person >> tree;
            trees[person].insert(tree);
        }
        for (int i = 1; i <= P; i++) {
            parent[i] = i;
            ranks[i] = 0;
        }
        for (int i = 1; i <= P; i++) {
            for (int j = i + 1; j <= P; j++) {
                if (trees[i] == trees[j]) {
                    doUnion(i, j);
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= P; i++) {
            if (i == parent[i]) {
                res++;
            }
            trees[i].clear();
        }
        cout << res << endl;
        if (t > 0) {
            cout << endl;
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