#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

const int MAX = 1e5 + 7;
void solve() {
    int nTest; cin >> nTest;
    for (int test = 1; test <= nTest; test++) {
        cout << "Scenario #" << test << ": ";
        int n, k; cin >> n >> k;
        vector<int> bush(n);
        for (int i = 0; i < n; i++) {
            cin >> bush[i];
        }

        // base state
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = bush[0]; i <= k; i++) {
            dp[1][i] = bush[0];
        }
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (j < bush[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    ll temp1 = dp[i - 2][j - bush[i - 1]] + bush[i - 1];
                    ll temp2 = dp[i - 1][j];
                    dp[i][j] = max(temp1, temp2);
                }
            }
        }
        cout << dp[n][k] << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}

