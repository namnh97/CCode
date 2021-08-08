#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

void solve() {
    int nTest; cin >> nTest;
    for (int test = 1; test <= nTest; test++) {
        string s1, s2; cin >> s1 >> s2;
        int n = s1.size();
        int m = s2.size();

        int scs[n + 1][m + 1];
        long scsNum[n + 1][m + 1];
        memset(scs, 0, sizeof(scs));
        memset(scsNum, 0, sizeof(scsNum));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    scs[i][j] = i + j;
                    scsNum[i][j] = 1;
                } else if (s1[i - 1] == s2[j - 1]) {
                    scs[i][j] = scs[i - 1][j - 1] + 1;
                    scsNum[i][j] = scsNum[i - 1][j - 1];
                } else {
                    scs[i][j] = min(scs[i][j - 1], scs[i - 1][j]) + 1;
                    if (scs[i][j] == scs[i][j - 1] + 1) {
                        scsNum[i][j] += scsNum[i][j - 1];
                    }

                    if (scs[i][j] == scs[i - 1][j] + 1) {
                        scsNum[i][j] += scsNum[i - 1][j];
                    }
                }
            }
        }
        cout << "Case " << test << ": " << scs[n][m] << " " << scsNum[n][m] << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


