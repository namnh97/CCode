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
        if (n % 2 == 1) {
            for (int i = 1; i <= n - 1; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (j - i <= n / 2) {
                        cout << 1 << " ";
                    } else {
                        cout << -1 << " ";
                    }
                }
            }
        } else {
            for (int i = 1; i <= n - 1; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n / 2) {
                        cout << 1 << " ";
                    } else if (j - i == n / 2) {
                        cout << 0 << " ";
                    } else {
                        cout << -1 << " ";
                    }
                }
            }
        }
        cout << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}