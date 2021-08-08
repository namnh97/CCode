//https://www.spoj.com/problems/LASTSHOT/
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
const int MAX = 100005;
int n, m;
vector<int> graph[MAX];
int vis[MAX];

int dfs(int index) {
    memset(vis, 0, sizeof(vis));
    stack<int> s;
    s.push(index);
    vis[index] = 1;

    int cnt = 0;   
    while (!s.empty()) {
        int u = s.top(); s.pop();
        cnt++;
        for (auto &it : graph[u]) {
            if (!vis[it]) {
                vis[it] = 1;
                s.push(it);
            }
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


