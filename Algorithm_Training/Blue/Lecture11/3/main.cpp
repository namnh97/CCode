//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=40
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

const int MAX = 31;
using namespace std;
map<string, int> concurrencyMap;
double dist[MAX][MAX];
int n;

void runFloy() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] < dist[i][k] * dist[k][j]) {
                    dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }
    }
}

void solve() {
    int cas = 0;
    while (cin >> n && n != 0) {
        int cnt = 0;
        concurrencyMap.clear();
        for (int i = 0; i < n; i++) {
            string concurrency; cin >> concurrency;
            concurrencyMap[concurrency] = cnt++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = i == j ? 1 : 0;
            }
        }
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            string src, des;
            double rate;
            cin >> src >> rate >> des;
            dist[concurrencyMap[src]][concurrencyMap[des]] = rate;
        }
        runFloy();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (dist[i][i] > 1) {
                flag = true;
                break;
            }
        }
        cout << "Case " << ++cas << ": ";
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
        cin.get();
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}
