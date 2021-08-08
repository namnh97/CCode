#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
void debugOut() {
    cerr << endl;
}

void solve() {
    ll t; cin >> t;
    while (t--) {
        ll n, m, res = 0; cin >> n >> m;
        if (n < 1) {
            cout << res << endl;
            continue;
        }
        ll a[n];
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        ll right = n - 1, left = 0;
        while (left < right) {
            int curSum = a[left] + a[right];
            if (curSum == m) {
                res++;
                right--;
                left++;
            } else if (curSum > m) {
                right--;
            } else {
                left++;
            }
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


