#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2000005;

ll fact[MAX];

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
}

ll modularExponentiation(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return res;
}

ll modInverse(ll b, ll m) {
    ll res = modularExponentiation(b, m - 2, m);
    if (res * b % m == 1)
        return res;
    return -1;
}

ll calC(int n, int k) {
    ll no = fact[n + k - 1];
    ll de = (fact[n] * fact[k - 1]) % MOD;
    return (no * modInverse(de, MOD)) %  MOD;
}

void solve() {
    int t; cin >> t;
    init();
    for (int i = 1; i <= t; i++) {
        int n, k; cin >> n >> k;
        cout << "Case " << i << ": " << calC(n , k) << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


