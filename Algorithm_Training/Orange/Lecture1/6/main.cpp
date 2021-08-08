//https://www.spoj.com/problems/RPLA/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 1001;
vector<int> graph[MAX], inDeg;
vector<bool> visited;
int n, r; 

struct Item {
    int index;
    int rank;
    Item(int _index, int _rank) {
        index = _index;
        rank = _rank;
    }
    bool operator < (const Item &a) const { 
        if (rank == a.rank) {
            return index < a.index;
        }
        return rank < a.rank;
    }
};

void init() {
    for (int i = 0; i < MAX; i++) {
        graph[i].clear();
    }
    visited = vector<bool>(n, false);
    inDeg = vector<int>(n, 0);
}

void findTopo(int index, vector<int> &result, vector<bool> &visited) {
    visited[index] = true;
    for (auto &it : graph[index]) {
        if (visited[it] == false) {
            findTopo(it, result, visited);
        }
    }
    result.pb(index);
}

void solve() {
    int t; cin >> t;
    for (int testcase = 1; testcase <= t; testcase++) {
        cin >> n >> r;
        init();

        for (int i = 0; i < r; i++) {
            int r1, r2;
            cin >> r1 >> r2;
            graph[r2].pb(r1);
            inDeg[r1]++;
        }

        //find topo
        vector<int> topo;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                findTopo(i, topo, visited);
            }
        }
        reverse(topo.begin(), topo.end());

        vector<int> rank(n, 0);

        for (auto &it : topo) {
            if (inDeg[it] == 0) {
                rank[it] = 1;
            }
            for (auto &adj : graph[it]) {
                rank[adj] = max(rank[adj], rank[it] + 1);
            }
        }

        vector<Item> result;
        for (int i = 0; i < n; i++) {
            result.pb(Item(i, rank[i]));
        }

        sort(result.begin(), result.end());
        cout << "Scenario #" << testcase << ":" << endl;
        for (auto &it : result) {
            cout << it.rank << " " << it.index << endl;
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


