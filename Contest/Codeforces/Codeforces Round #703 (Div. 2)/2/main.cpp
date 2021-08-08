#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;


ll cal(vector<int> x) {
    sort(x.begin(), x.end());
    ll first = x[x.size() / 2];
    ll second = x[(x.size() - 1) / 2];
    return first - second + 1; 
 }

void solve() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        cout << cal(x) * cal(y) << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}