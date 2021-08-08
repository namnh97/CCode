#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

struct Item {
    int c;
    int p;
    int t;
    Item(int _c, int _p, int _t) {
        c = _c;
        p = _p;
        t = _t;
    }
};

vector<Item> items;
vector<vector<int>> dp;
void solve() {
    int t; cin >> t;
    while (t--) {
        int n, w; cin >> n >> w;
        items.clear();
        items.pb(Item(0, 0, 0));
        for (int i = 0; i < n; i++) {
            int c, t, p;
            cin >> c >> t >> p;
            items.pb(Item(c, t, p));
        }
        dp.assign(n + 1, vector<int>(w + 1, 0));

        for (int i = 1; i < items.size(); i++) {
            for (int j = 0; j <= w; j++) {
                if (items[i].t > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    int temp1 = items[i].c * items[i].p  + dp[i - 1][j - items[i].t];
                    int temp2 = dp[i - 1][j];
                    dp[i][j] = max(temp1, temp2);
                }
            }
        }
        cout << dp[n][w] << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


