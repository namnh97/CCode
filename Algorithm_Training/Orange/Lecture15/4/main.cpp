#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> segValues(1 << (n + 1));
    for (int i = 1 << n; i < (1 << (n + 1)); i++) {
        cin >> segValues[i];
        for (int p = i / 2, t = 1; p > 0; p /= 2, t ^= 1) {
            if (t == 1) {
                segValues[p] = segValues[p << 1] | segValues[p << 1 | 1];
            } else {
                segValues[p] = segValues[p << 1] ^ segValues[p << 1 | 1];
            }
        }
    }

    while (m--) {
        int p, b;
        cin >> p >> b;
        // determine pos;
        p = (p + (1 << n) - 1);
        segValues[p] = b;
        p /= 2;
        for (int t = 1; p > 0; p /=2, t ^= 1) {
            if (t == 1) {
                segValues[p] = segValues[p << 1] | segValues[p << 1 | 1];
            } else {
                segValues[p] = segValues[p << 1] ^ segValues[p << 1 | 1];
            }
        }
        cout << segValues[1] << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


