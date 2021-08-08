#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int gcd = __gcd(n, m);
    
    vector<int> h(gcd);
    int nn;
    cin >> nn;
    for (int i = 0; i < nn; i++) {
        int tmp; cin >> tmp;
        h[tmp % gcd] = 1;
    }

    int nm;
    cin >> nm;
    for (int i = 0; i < nm; i++) {
        int tmp; cin >> tmp;
        h[tmp % gcd] = 1;
    }
    
    int res = true;
    for (int i = 0; i < gcd; i++) {
        if (h[i] == 0) {
            res = false;
            break;
        }
    }
    if (res) cout << "YES";
    else cout << "NO";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


