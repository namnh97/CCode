#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

struct Treasure {
    int t;
    int d;
    int id;

    Treasure(int t, int d, int id) {
        this->t = t;
        this->d = d;
        this->id = id;
    }
    
    bool operator < (const Treasure other) const {
        return this->t < other.t;
    }
};

vector<Treasure> treasures;
int t, w;
int n;

void solve() {
    bool end = false;

    while(cin >> t >> w) {
        cin >> n;
        treasures.clear();
        for (int i = 0; i < n; i++) {
            int ti, di; cin >> ti >> di;
            treasures.pb(Treasure(ti, di, i));
        }

        vector<Treasure> original = treasures;
        int dp[n + 1][t + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= t; j++) {
                int time = treasures[i - 1].t * w * 3;
                if (time > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    int temp1 = dp[i - 1][j];
                    int temp2 = dp[i - 1][j - time] + treasures[i - 1].d;
                    dp[i][j] = max(temp1, temp2);
                }
            }
        }

        if (end) {
            cout << endl;
        }
        end = true;

        cout << dp[n][t] << endl;

        vector<int> ids;       
        for (int i = treasures.size(); i >= 1; i--) {
            if (dp[i][t] == dp[i - 1][t]) {
                // don't take this treasure;
                continue;
            }

            ids.pb(treasures[i - 1].id);
            t -= treasures[i - 1].t * w * 3;
        }

        cout << ids.size() << endl;
        sort(ids.begin(), ids.end());
        for (auto &it : ids) {
            cout << original[it].t << " " << original[it].d << endl;
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


