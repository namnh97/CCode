//https://codeforces.com/problemset/problem/295/B
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;
const int MAX = 501;
int dist[MAX][MAX];
int removedV[MAX];
ll res[MAX];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> removedV[i];
    }

    for (int index = n - 1; index >= 0; index--) {
        int k = removedV[index];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n;j ++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }

        for (int i = index; i < n; i++) {
            int u = removedV[i];
            for (int j = index; j < n; j++) {
                int v = removedV[j];
                res[index] += dist[u][v];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}