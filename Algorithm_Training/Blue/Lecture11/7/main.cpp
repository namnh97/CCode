//https://www.codechef.com/problems/MAXCOMP
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 49;
const int INF = 1e9;
int dist[MAX][MAX];
int n;

void doFloy() {
    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (i <= k && k <= j) { //to avoid overlap;
                    dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void solve() {
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                dist[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            dist[u][v] = max(dist[u][v], c);
        }
        doFloy();
        cout << dist[0][MAX - 1] << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


