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
        int nStick, conLen;
        ll res = -1;
        cin >> nStick >> conLen;
        conLen = conLen * 2;
        vector<pii> sticks(nStick + 1);
        for (int i = 1; i <= nStick; i++) {
            pii temp;
            cin >> sticks[i].first >> sticks[i].second;
            res = max(res, 1LL * sticks[i].second);
        }

        ll f[nStick + 1][conLen + 1][3];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= nStick; i++) {
            for (int j = 1; j <= conLen; j++) {
                for (int c = 0; c <= 2; c++) {
                    f[i][j][c] = f[i - 1][j][c];
                    if (j >= sticks[i].first * 2) {
                        f[i][j][c] = max(f[i][j][c], f[i - 1][j - 2 * sticks[i].first][c] + 1LL * sticks[i].second);
                    }

                    if (j >= sticks[i].first && c > 0) {
                        f[i][j][c] = max(f[i][j][c], f[i - 1][j - sticks[i].first][c - 1] + 1LL * sticks[i].second);
                    }
                }
            }
        }

        for (int c = 0; c <= 2; c++) {
            res = max(res, f[nStick][conLen][c]);
        }
        cout << "Case #" << test << ": " << res << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}
