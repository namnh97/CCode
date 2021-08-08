//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=48
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

struct Graph {
    vector<vector<int>> adj;
    Graph(int n) {
        adj = vector<vector<int>> (n + 1, vector<int>());
    }

    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

int result;
int n, k;

vector<int> dfs(Graph &graph, int u, int parent) {
    vector<int> countU(k + 1);
    countU[0] = 1;
    for (auto &v : graph.adj[u]) {
        if (v != parent) {
            vector<int> countV = dfs(graph, v, u);

            for (int i = 0; i < k; i++) {
                result += countU[i] * countV[k - i - 1];
            } 


            for (int i = 1; i <= k; i++) {
                countU[i] += countV[i - 1];
            }
        }
    }
    return countU;
}

void solve() {
    cin >> n >> k;
    Graph graph(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph.add(a, b);
    }
    result = 0;
    dfs(graph, 1, -1);
    cout << result << endl;
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


