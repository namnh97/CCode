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
int n, m;
vector<int> a;
void solve() {
    int cas = 0;
    while (cin >> n >> m && n != 0 && m != 0) {
        cout << "CASE# " << ++cas << ":" << endl;;
        a.clear();
        fori (i, 1, n) {
            int tmp; cin >> tmp;
            a.pb(tmp);
        }
        sort(a.begin(), a.end());
        fori (i, 1, m) {
            int q; cin >> q;
            vector<int>::iterator loc = lower_bound(a.begin(), a.end(), q);
            int index = loc - a.begin();
            if (a[index] == q) {
                cout << q << " found at " << index + 1 << endl;
            } else {
                cout << q << " not found" << endl;
            }
        }
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


