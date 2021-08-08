#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

void solve() {
    int t; cin >> t;
    while (t--) {
        int p, a, b, c;
        cin >> p >> a >> b >> c;
        ll res = min(ceil(p / a) * a, min(ceil(p / b) * b, ceil(p / c) * c)) - p;
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