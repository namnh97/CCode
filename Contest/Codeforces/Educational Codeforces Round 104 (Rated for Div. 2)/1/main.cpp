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
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            a.pb(tmp);
        }
        int mini = *min_element(a.begin(), a.end());
        int ans = n - count(a.begin(), a.end(), mini);
        cout << ans << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}