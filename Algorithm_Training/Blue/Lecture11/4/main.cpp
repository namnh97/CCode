//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=508
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 20;
const int INF = 1e9 + 7;
int dist[MAX + 1][MAX + 1];

void clear() {
    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; j <= MAX; j++) {
            dist[i][j] = INF;
        }
    }
}

string format(int n) {
    if (n >= 10) {
        return to_string(n);
    }
    return " " + to_string(n);
}

void doFloy() {
    for (int k = 1; k <= MAX; k++) {
        for (int i = 1; i <= MAX; i++) {
            for (int j = 1; j <= MAX; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void solve() {
    int tests = 0;
    while (1)  {
        clear();
        for (int src = 1; src < MAX; src++) {
            int n;
            if (!(cin >> n)) return;
            
            for (int i = 0; i < n; i++) {
                int des; cin >> des;
                dist[src][des] = 1;
                dist[des][src] = 1;
            }
        }
        doFloy();
        cout << "Test Set #" << ++tests << endl;
        int q; cin >> q;
        while (q--) {
            int src, des; cin >> src >> des;
            cout << format(src) << " to " << format(des) << ": " << dist[src][des] << endl; 
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