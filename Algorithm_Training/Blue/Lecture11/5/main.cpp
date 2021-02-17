//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1187
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 85;
const int INF = 1e9;
int C, R, Q;
int dist[MAX][MAX];
int maxCost[MAX][MAX];
int cityCost[MAX];

void doFloy() {
    for (int time = 1; time <= 2; time++)
    for (int k = 1; k <= C; k++) {
        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= C; j++) {
                int maxFeast = max(maxCost[i][k], maxCost[k][j]);
                if (dist[i][j] + maxCost[i][j] > dist[i][k] + dist[k][j] + maxFeast) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    maxCost[i][j] = maxFeast;
                }
            }
        }
    }
}

void solve() {
    int tc = 0;
    while (cin >> C >> R >> Q && C != 0 && R != 0 && Q != 0) {
        for (int i = 1; i <= C; i++) {
            cin >> cityCost[i];
        }

        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= C; j++) {
                dist[i][j] = INF;
                maxCost[i][j] = max(cityCost[i], cityCost[j]);
            }
        }
        for (int i = 1; i <= R; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            dist[u][v] = dist[v][u] = c;
        }

        doFloy();

        if (tc > 0) cout << endl;
        cout << "Case #" << ++tc << endl;
        for (int i = 1; i <= Q; i++) {
            int src, des; cin >> src >> des;
            if (dist[src][des] == INF) {
                cout << "-1" << endl;
            } else {
                cout << dist[src][des] + maxCost[src][des] << endl;
            }
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


