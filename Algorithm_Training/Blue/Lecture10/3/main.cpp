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

const int MAX = 101;
const int INF = -1e9;
struct Edge {
    int src;
    int des;
    int weight;
    Edge(int src = 0, int des = 0, int weight = 0) {
        this->src = src;
        this->des = des;
        this->weight = weight;
    }
};

vector<Edge> graph;
vector<int> dist(MAX, INF);
int n;

bool Bellman(int s) {
    dist[s] = 100;
    int u, v, w;
    for (int i = 1; i <= n - 1; i++) {
        for (auto &Edge : graph) {
            u = Edge.src;
            v = Edge.des;
            w = Edge.weight;
            if (dist[u] != -INF && (dist[u] + w > dist[v]) && dist[u] >= 0) {
                dist[v] = dist[u] + w;
            }
        }
    } 
    for (auto &Edge : graph) {
        u = Edge.src;
        v = Edge.des;
        w = Edge.weight;
        if (dist[u] != INF && dist[u] + w < dist[v]) return false;
    }
    return true;
}


void clear() {
    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
    }
    graph.clear();
}
void solve() {
    while (cin >> n && n != -1) {
        clear();
        for (int i = 1; i <= n; i++) {
            int cost; cin >> cost;
            int numberOfAdj; cin >> numberOfAdj;
            for (int j = 0; j < numberOfAdj; j++) {
                int adj; cin >> adj;
                graph.push_back(Edge(i, adj, cost));
            }
        }
        bool canGo = Bellman(1,);
    }
}



int main(void){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    solve();
    return 0;
}
