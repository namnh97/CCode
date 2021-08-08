//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3084
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

void solve() {
    while (true) {
        ll n; cin >> n;
        if (n == 0) break;

        ll a = 0, b = 0;
        bool flag = true;
        for (int i = 0; i < 31; i++) {
            if ((n & (1 << i)) > 0) {
                if (flag) {
                    a += (1 << i);
                } else {
                    b += (1 << i);
                }
                flag = !flag;
            }
        }
        cout << a << " " << b << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


