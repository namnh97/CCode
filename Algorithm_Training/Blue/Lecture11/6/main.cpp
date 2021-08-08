//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1744
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int INF = 2049;
const int MAX = 105;
vector<pii> points;
double dist[MAX][MAX];
int n;

double calDistance(const pii &a, const pii &b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void doFloy() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve() {
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        points.clear();

        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = (i == j) ? 0 : INF;
            }
        }

        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            points.pb({x, y});
        }
        

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double dis = calDistance(points[i], points[j]) ;
                if (dis <= 10) {
                    dist[i][j] = dis;
                }
            }
        }

        doFloy();

        double res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dist[i][j]);
            }
        }
        cout << "Case #" << t << ":" << endl;
        if (res != INF) {
            cout << fixed << setprecision(4) << res << endl;
        } else {
            cout << "Send Kurdy" << endl;
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


