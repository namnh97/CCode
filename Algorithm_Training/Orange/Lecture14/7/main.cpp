#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;
const int INF = 1e9;

void solve() {
    int nTest; cin >> nTest;
    while (nTest--) {
        cin.get();
        int n, s; cin >> n >> s;
        vector<int> conventionalValues(n), infoTechnologicalValues(n);
        for (int i = 0; i < n; i++) {
            cin >> conventionalValues[i] >> infoTechnologicalValues[i];
        }

        int dp[s + 1][s + 1];
        dp[0][0] = 0;
        for (int i = 0; i <= s; i++) {
            for (int j = 0; j <= s; j++) {
                if (i == 0  && j == 0) continue;
                dp[i][j] = INF;
                for (int k = 0; k < n; k++) {
                    if (i >= conventionalValues[k] && j >= infoTechnologicalValues[k]) {
                        dp[i][j] = min(dp[i][j], dp[i - conventionalValues[k]][j - infoTechnologicalValues[k]] + 1);
                    }
                }
            }
        }

        int result = INF;
        for (int i = 0; i <= s; i++) {
            int temp = sqrt(s*s - i*i);
            if (temp * temp == s * s - i * i) {
                result = min(result, dp[i][temp]);
            }
        }

        if (result == INF) {
            cout << "not possible" << endl;
        } else {
            cout << result << endl;
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


