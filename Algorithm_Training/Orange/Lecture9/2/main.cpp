#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const ll MOD = 1000000007;
const int BASE = 26;
ll *mul, *f, n;

void getHash(string s) {
    ll hashValue = 0;
    for (int i = 0; i < s.length(); i++) {
        hashValue = ((s[i] - 'a') + (BASE * hashValue) % MOD) % MOD;
        f[i + 1] = hashValue;
    }
}

void solve() {
    int nTests; cin >> nTests;
    for (int t = 1; t <= nTests; t++) {
        string s; cin >> s;
        n = s.length();
        mul = new ll[n + 1];
        f = new ll[n + 1];
        mul[0] = 1;

        for (int i = 1; i <= n; i++) {
            mul[i] = (mul[i - 1] * BASE) % MOD;
        } 

        f[0] = 0;

        getHash(s);
        int res = 0, len = 1;
        while (len < n) {
            if (f[len] == ((f[n] - (f[n - len] * mul[len]) % MOD) + MOD) % MOD) {
                res++;
            }
            len++;
        }
        cout << "Case " << t << ": " << res << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


