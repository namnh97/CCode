//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1112
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
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
const int MAX = 28;
const int INF = 1e9;
int distY[MAX][MAX], distM[MAX][MAX];
int n, cost;
char age, dir, src, des;
vector<pii> res;

void doFloy(int dist[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
void solve() {
    while (cin >> n && n != 0) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                distY[i][j] = i == j ? 0 : INF;
                distM[i][j] = i == j ? 0 : INF;
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> age >> dir >> src >> des >> cost;
            int u = src - 'A';
            int v = des - 'A';
            if (age == 'Y') {
                distY[u][v] = min(distY[u][v], cost);
                if (dir == 'B') {
                    distY[v][u] = min(distY[v][u], cost);
                }
            } else {
                distM[u][v] = min(distM[u][v], cost);
                if (dir == 'B') {
                    distM[v][u] = min(distM[v][u], cost);
                }
            }
        }
        doFloy(distY);
        doFloy(distM);
        cin >> src >> des;
        int s = src - 'A';
        int f = des - 'A';
        res.clear();

        int minDist = INF;
        for (int i = 0; i < MAX; i++) {
            int firstDist = distY[s][i];
            int secondDist = distM[f][i];
            if (firstDist != INF && secondDist != INF && firstDist + secondDist <= minDist) {
                res.pb({firstDist + secondDist, i});
                minDist = firstDist + secondDist;
            }
        }
        if (res.empty()) {
            cout << "You will never meet." << endl;
        } else {
            sort(res.begin(), res.end(), [&](const pii &a, const pii &b) {
                return a.first < b.first || (a.first == b.first && a.second < b.second);
            });
            cout << minDist;
            for (auto &it : res) {
                if (it.first == minDist) {
                    cout << " " << (char)(it.second + 'A');
                }
            }
            cout << endl;
        }
    }
}



int main(void){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    solve();
    return 0;
}
