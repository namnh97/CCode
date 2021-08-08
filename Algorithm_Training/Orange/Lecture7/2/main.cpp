#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

void solve() {
    ll n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        n = abs(n);
        int cnt = 0;
        ll res = -1;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                res = i;
                while (n % i == 0) {
                    n = n / i;
                }
            }
        }
        if (cnt > 0 && n > 1) {
            cout << n << endl;
        } else if (cnt == 1) {
            cout << -1 << endl;
        } else {
            cout << res << endl;
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


