#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

vector<int> agnas;
vector<int> viRes;
const int MAX = 1005;
int L[MAX][MAX];

int lcs(const vector<int> viFirst, const vector<int> viSecond, int m, int n) {
    memset(L, -1, MAX * MAX);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (viFirst[i - 1] == viSecond[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    return L[m][n];
}

void solve() {
    int d; cin >> d;
    int card;
    while (d--) {
        agnas.clear();
        viRes.clear();

        cin >> card; if (card == 0) return;
        agnas.pb(card);

        while (1) {
            cin >> card;
            if (card == 0) {
                break;
            }
            agnas.pb(card);
        }

        while (1) {
            vector<int> tom;
            cin >> card;
            if (card == 0) {
                break;
            }
            tom.pb(card);

            while(1) {
                cin >> card;
                if (card == 0) {
                    break;
                }
                tom.pb(card);
            }
            int resOfOneLine = lcs(agnas, tom, agnas.size(), tom.size());
            viRes.pb(resOfOneLine);
        }
        int res = 0;
        for (auto &it : viRes) {
            res = max(it, res);
        }
        cout << res << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


