#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

void solve() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int ans;
        if (n % 2 == 0) {
            ans = k % n;
        } else {
            ans = ((k + (k - 1) / (n / 2)) % n);
        }
        if (ans == 0) {
            cout << n << endl;
        } else {
            cout << ans << endl;
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