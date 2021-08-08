#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

void solve() {
    int k;
    while (cin >> k) {
        if (k == 0) return;
        string w1, w2; cin >> w1 >> w2;
        int n = w1.size();
        int m = w2.size();

        int dp[n + 1][m + 1];
        int c[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (w1[i - 1] == w2[j - 1]) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                } else {
                    c[i][j] = 0;
                }

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                for (int e = k; e <= c[i][j]; e++) {
                    dp[i][j] = max(dp[i][j], dp[i - e][j - e] + e);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


