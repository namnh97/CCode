#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

void solve() {
    int t; cin >> t;
    while (t--) {
        int nfriends, nboxes;
        cin >> nfriends >> nboxes;
        int res = 0;
        for (int i = 0; i < nboxes; i++) {
            int countOneBox = 1;
            int k; cin >> k;
            for (int i = 0; i < k; i++) {
                int tmp; cin >> tmp;
                countOneBox = (countOneBox * tmp) % nfriends;
            }
            res = (res + countOneBox) % nfriends;
        }
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


