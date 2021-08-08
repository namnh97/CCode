#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

int cal(vector<int> a, int k) {
    int dp[a.size()][k + 1][2];
    int n = a.size();

    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= k; j++) {
            for (int s = 0; s <= 1; s++) {
                dp[i][j][s] = INT_MIN;
            }
        }
    }

    dp[0][0][0] = 0;
    dp[0][0][1] = -a[0];
    
    int result = 0;
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= k; j++) {
            for (int status = 0; status <= 1; status++) {
                // status 1: is to buy
                // status 0: is to sell
                if (dp[i][j][status] == INT_MIN) {
                    continue;
                }

                if (i == n - 1) {
                    // at the final day.
                    if (status == 0) {
                        result = max(result, dp[i][j][status]);
                    }
                    continue;
                }

                dp[i + 1][j][status] = max(dp[i + 1][j][status], dp[i][j][status]);

                if (j < k) {
                    if (status == 0) {
                        dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][0] - a[i + 1]);
                    }

                    if (status ==  1) {
                        dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][1] + a[i + 1]);
                    }
                }
            }
        }
    }

    return result;
}

void solve() {
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, k; cin >> k >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int result = cal(a, k);
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


