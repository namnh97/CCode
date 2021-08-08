#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 100;
vector<int> graph[MAX];
int result[MAX];
bool colors[MAX];
int V, E;

void printColoring() {
    for (int i = 0; i < V; i++) {
        cout << "Vertex" << i << " --> Color " << result[i] << endl;
    }
}

void greedyColoring() {
    for (int u = 0; u < V; u++) {
        for (int neightbor : graph[u]) {
            if (result[neightbor] != -1) {
                colors[result[neightbor]] = true;
            }
        }

        for (int cr = 0; cr < V; cr++) {
            if (colors[cr] = false) {
                result[u] = cr;
                break;
            }
        }
        
        for (int neightbor : graph[u]) {
            if (result[neightbor] != -1) {
                colors[result[neightbor]] = false;
            }
        }
    }
}

void solve() {
    int u, v;
    cin >> V >> E;
    memset(result, -1, sizeof(result));
    memset(colors, false, sizeof(colors));

    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    greedyColoring();
    printColoring();
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}