//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1338
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

const int MAX = 751;
const double INF = 1e9;
const int EPS = 1e-9;

vector<pii> buildings;
vector<pair<int, double>> graph[MAX];
double dist[MAX];
bool visited[MAX];

double calDistance(pii a, pii b) {
    int first = a.first - b.first;
    int second = a.second - b.second;
    return sqrt(first * first + second * second);
}

bool doubleCmp(const double a, const double b) {
    return ((a - b) > EPS);
}

struct Compare {
    bool operator() (const pair<int, double> &a, const pair<int, double> &b) {
        return doubleCmp(a.second, b.second);
    }
};

void prims(int src) {
    priority_queue<pair<int, double>, vector<pair<int, double>>, Compare> pq;
    pq.push({src, 0});
    dist[src] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().first; pq.pop();
        visited[u] = true;
        for (auto &it : graph[u]) {
            int v = it.first;
            double w = it.second;
            if (!visited[v] && doubleCmp(dist[v], w)) {
                dist[v] = w;
                pq.push({v, w});
            }
        }
    }
}

void init() {
    fill(visited, visited + MAX, false);
    fill(dist, dist + MAX, INF);
    buildings.clear();
    for (int i = 0; i < MAX; i++) {
        graph[i].clear();
    }
}

void solve() {
    int N;
    while (cin >> N && N != 0) {
        init();
        for (int i = 0; i < N; i++) {
            int x, y; cin >> x >> y;
            buildings.pb({x, y});
        }

        vector<vector<bool>> edges(MAX, vector<bool>(MAX, false));
        int M; cin >> M;
        for (int i = 0; i < M; i++) {
            int u, v; cin >> u >> v;
            edges[u - 1][v - 1] = true;
            edges[v - 1][u - 1] = true;
        }

        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                if (edges[i][j] == false) {
                    double k = calDistance(buildings[i], buildings[j]);
                    graph[i].pb({j, k});
                    graph[j].pb({i, k});
                } else {
                    graph[i].pb({j, 0});
                    graph[j].pb({i, 0});
                }
            }
        }
        prims(0);
        double res = 0.0;
        for (int i = 0; i < N; i++) {
            if (dist[i] == INF) {
                continue;
            }
            res += dist[i];
        }
        cout << fixed << setprecision(2) << res << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


