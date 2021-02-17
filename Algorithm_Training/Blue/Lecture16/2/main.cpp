//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400
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

int parent[26];
void init() {
    for (int i = 0; i < 26; i++) {
        parent[i] = i;
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void doUnion(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    parent[pu] = pv;
}

void solve() {
    int t;
    string in;
    scanf("%d\n\n", &t);
    for (int cas = 1; cas <= t; cas++) {
        init();
        getline(cin, in);
        int nNodes = in[0] - 'A' + 1;
        while (getline(cin, in) && !in.empty()) {
            int u = in[0] - 'A';
            int v = in[1] - 'A';
            int pu = find(u);
            int pv = find(v);
            if (pu != pv) {
                nNodes--;
                doUnion(u, v);
            }
        }
        if (cas != 1) cout << endl;
        cout << nNodes << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}