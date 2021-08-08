#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result = result / i * (i - 1);
        }
    }
    if (n > 1) {
        result = result / n * (n - 1);
    }
    return result;
}
void solve() {
    ll n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        int res = phi(n);
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


