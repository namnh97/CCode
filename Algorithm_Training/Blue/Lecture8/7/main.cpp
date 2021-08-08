//https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/successful-marathon-0691ec04/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 100005;
const int INF = 1e9;

int nCities, nRoads, expiryTime;
int u, v, d, k, src, des;
vector<int> cPlaces;
vector<pii> graph[MAX];

vector<int> dijkstra(int src) {
    vector<int> dist(MAX, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src]  = 0;
    pq.push({src, 0});
    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int u = top.first;
        int w = top.second;
        if (dist[u] != w) continue;
        for (auto &it : graph[u]) {
            int v = it.first;
            int c = it.second;
            if (dist[v] > w + c) {
                dist[v] = w + c;
                pq.push({v, dist[v]});
            }
        }
    }
    return dist;
}

void solve() {
    cin >> nCities >> nRoads >> k >> expiryTime;
    for (int i = 0; i < k; i++) {
        int tmp; cin >> tmp;
        cPlaces.pb(tmp);
    }
    for (int i = 0; i < nRoads; i++) {
        cin >> u >> v >> d;
        graph[u].pb({v, d});
        graph[v].pb({u, d});
    }

    cin >> src >> des;
    vector<int> distS = dijkstra(src);
    vector<int> distT = dijkstra(des);
    int res = INF, time = INF;
    for (int i = 0; i < cPlaces.size(); i++) {
        int index = cPlaces[i];
        if (res > distS[index] + distT[index]) {
            res = distS[index] + distT[index];
            time = distT[index];
        }
    }
    if (time <= expiryTime) {
        cout << res;
    } else {
        cout << -1;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


