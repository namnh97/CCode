//https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/
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
    int t; cin >> t;
    set<ll> s;
    while (t--) {
        int n, m;
        cin >> n >> m;
        s.clear();
        for (int i = 0; i < n; i++) {
            ll tmp; cin >> tmp;
            s.insert(tmp);
        }
        for (int i = 0; i < m; i++) {
            ll tmp; cin >> tmp;
            if (s.find(tmp) != s.end()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            s.insert(tmp);
        }
    }
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}
