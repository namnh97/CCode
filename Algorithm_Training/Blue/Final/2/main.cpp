#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

int grid[5][5] = {
    {1, 4, 5, 16, 17},
    {2, 3, 6, 15, 18},
    {9, 8, 7, 14, 19},
    {25, 24, 23, 22, 21}
};
pii res[5 * 5 + 1];

void dfs(int rol, int col) {

}

void inialize() {
    dfs(0, 0);
}

void solve() {
    int t; cin >> t;
    initialize();
    while(t--) {
        int q; cin >> q;

    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}
