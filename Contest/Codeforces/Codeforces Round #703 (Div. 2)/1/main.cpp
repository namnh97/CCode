#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

void solve() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll lower = 0;
        ll sum = 0;
        bool res = true;
        for (int i = 0; i < n; i++) {
            lower += i;
            sum += a[i];
            if (sum < lower) {
                res = false;
            }
        }
        if (res) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}