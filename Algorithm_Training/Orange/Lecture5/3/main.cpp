#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

void solve() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        ll sum = 0, nWorkers = 0;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            nWorkers += abs(sum);
            sum += tmp;
        }
        cout << nWorkers << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


