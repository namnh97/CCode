//https://codeforces.com/problemset/problem/424/B
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

map<double, int> m;
const int INF = 1e6;

double calculateDistance(int x, int y) {
    return sqrt(x * x + y * y);
}

void solve() {
    int n, s; cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int x, y, k; cin >> x >> y >> k;
        m[calculateDistance(x, y)] += k;
    }
    double res;
    for (auto &it : m) {
        if (s >= INF) {
            break;
        }
        s += it.second;
        res = it.first;
    }
    cout << fixed << setprecision(7);
    if (s < INF) {
        cout << "-1" << endl;
    } else {
        cout << res << endl;
    }
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

