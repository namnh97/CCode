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
int n;
vector<int> a;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a.pb(tmp);
    }
    int q; cin >> q;
    while (q--) {
        int tmp; cin >> tmp;
        vector<int>::iterator low, up;
        low = lower_bound(a.begin(), a.end(), tmp);
        up  = upper_bound(a.begin(), a.end(), tmp);
        if(low-a.begin() == 0)
            cout << "X ";
        else
            cout << *--low << " ";
        if(up-a.begin() == n)
            cout << "X" << endl;
        else
            cout << *up << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


