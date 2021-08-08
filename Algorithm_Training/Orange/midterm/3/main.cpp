#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX = 1e5 + 5;
vector<int> graph[MAX];
int n, x, y, q;
int arrivalTime[MAX], endTime[MAX];
int step;

void dfs(int vertex) {
    step++;
    arrivalTime[vertex] = step;
    for (auto &it : graph[vertex]) {
        if (arrivalTime[it] == 0) {
            dfs(it);
        }
    }
    step++;
    endTime[vertex] = step;
}

void solve() {
    step = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    cin >> q;
    while (q--) {
        int a; cin >> a >> x >> y;
        if (a == 1) swap(x, y);
        if (arrivalTime[x] <= arrivalTime[y] && endTime[x] >= endTime[y]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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


