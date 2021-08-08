#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;
const int BASE = 41;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int cnt[2], h[MAX], pw[MAX], len[2], g[2], f[2];

int getHash(int l, int r) {
    return (h[r] - 1LL * h[l - 1] * h[r - l + 1] % MOD + MOD) % MOD;
}

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for (int i = 1; i <= n; i++) {
        cnt[s[i] - '0']++;
    }

    // cal hash
    pw[0] = 1;
    for (int i = 1; i <= m; i++) {
        pw[i] = (1LL * pw[i - 1] * BASE) % MOD;
        h[i] = (1LL * h[i - 1] * BASE + t[i] - 'a' + 1) % MOD;
    }

    int ans = 0;
    int i = 1;
    while (1) {
        f[0] = f[1] = 1;
        if (cnt[0] * i >= m) {
            break;
        }

        if ((m - cnt[0] * i) % cnt[1]) {
            continue;
        }

        len[0] = i;
        len[1] = (m - cnt[0] * i) / cnt[1];

        for (int l = 1, k = 1; k <= n; k++) {
            int cur = s[k] - '0';
            if (f[cur]) {
                g[cur] = getHash(l, l + len[cur] - 1);
                f[cur] = 0;
            } else if (g[cur] != getHash(l, l + len[cur] - 1)) {
                break;
            }

            if (!f[0] && !f[1] && g[0] == g[1]) {
                break;
            }

            if (k == n) {
                ans++;
            }

            l += len[cur];
        }
        i++;
    }
    cout << ans << endl;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}