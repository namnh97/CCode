#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

const int MAX = 101;
const double INF = 10000000;
struct Point {
    double x, y;
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
};
using namespace std;
int n;

vector<pair<int, double>> graph[MAX];
vector<Point> points;
double dist[MAX];
int path[MAX];
bool visited[MAX];

double calDistance(const Point a, const Point b) {
    double fi = a.x - b.x;
    double se = a.y - b.y;
    return sqrt(fi * fi + se * se);
}

struct Compare {
    bool operator() (const pair<int, double> &a, const pair<int, double> &b) {
        return a.second > b.second;
    }
};

void prims(int src) {
    memset(visited, false, sizeof(visited));
    fill(dist, dist + MAX, INF);
    memset(path, -1, sizeof(path));
    priority_queue<pair<int, double>, vector<pair<int, double>>, Compare> pq;
    pq.push({0, 0.0});
    dist[src] = 0.0;
    while (!pq.empty()) {
        int u = pq.top().first; pq.pop();
        visited[u] = true;
        for (auto &it : graph[u]) {
            int v = it.first;
            double w = it.second;
            if (visited[v] == false && dist[v] > w) {
                dist[v] = w;
                path[v] = u;
                pq.push({v, w});
            }
        }       
    }
}

double getMinimumDis() {
    double result = 0;
    for (int i = 0; i < n; i++) {
        if (path[i] == -1) continue;
        result += dist[i];
    }
    return result;
}

void solve() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("\n%d", &n);
        for (int i = 0; i < MAX; i++) {
            graph[i].clear();
            points.clear();
        }
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            points.pb(Point(x * 1.0, y * 1.0));
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                double dis = calDistance(points[i], points[j]);
                graph[i].pb({j, dis});
                graph[j].pb({i, dis});
            }
        }
        prims(0);
        double res = getMinimumDis();
        cout << fixed << setprecision(2) << res << endl << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}