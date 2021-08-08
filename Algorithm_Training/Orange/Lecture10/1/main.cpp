#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;
const int MAX = 1e6 + 1;
ll dp[MAX];

void init() {
    for (int i = 0; i < MAX; i++) {
        dp[i] = -1;
    }
}

ll exchange(ll n) {
    if (n < MAX && dp[n] != -1) {
        return dp[n];
    }
    if (n < 3) {
        return n;
    }
    ll result = max(exchange(n / 2) + exchange(n / 3) + exchange(n / 4), n);
    if (n < MAX) {
        dp[n] = result;
    }
    return result;
}

void solve() {
    ll n;
    while (cin >> n) {
        init();
        ll res = exchange(n);
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


