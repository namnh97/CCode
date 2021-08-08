//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1895
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
	while (1) {
		ll n; cin >> n;
		if (n == 0) break;
		priority_queue<ll, vector<ll>, greater<ll>> q;
		fori (i, 1, n) {
			ll tmp; cin >> tmp;
			q.push(tmp);
		}
		ll cost = 0;
		while (q.size() > 1) {
			ll first = q.top(); q.pop();
			ll second = q.top(); q.pop();
			ll total = first + second;
			cost += total;
			q.push(total);
		}
		cout << cost << endl;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

