#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

void solve() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> coins;
        int sum = 0;
        coins.pb(0);
        for (int i = 0; i < n; i++) {
            int coin; cin >> coin;
            sum += coin;
            coins.pb(coin);
        }
        int w = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        for (int i = 1; i < coins.size(); i++) {
            for (int j = 0; j <=  w; j++) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else{
                    int temp1 = coins[i] + dp[i - 1][j - coins[i]];
                    int temp2 = dp[i - 1][j];
                    dp[i][j] = max(temp1, temp2);
                }
            }
        }
        int result = sum - 2 * dp[coins.size() - 1][w];
        cout << result << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


