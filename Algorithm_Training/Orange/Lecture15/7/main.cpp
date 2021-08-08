#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;
int n, m;

bool topologicalSort(vector<vector<int>> &graph) {
    vector<int> inDegree(graph.size(), 0);
    queue<int> zeroIndegree;

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            inDegree[graph[i][j]]++;
        }
    }

    for (int i = 0; i < graph.size(); i++) {
        if (inDegree[i] == 0) {
            zeroIndegree.push(i);
        }
    }

    while (!zeroIndegree.empty()) {
        int u = zeroIndegree.front();
        zeroIndegree.pop();
        for (auto &it : graph[u]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                zeroIndegree.push(it);
            }
        }
    }

    for (int i = 0; i < graph.size(); i++) {
        if (!inDegree[i] == 0) {
            return false;
        }
    }

    return true;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[v].pb(u);
    }

    bool result = topologicalSort(graph);
    if (result) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


