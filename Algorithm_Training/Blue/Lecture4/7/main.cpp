//https://codeforces.com/problemset/problem/644/B
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
	ll n, b; 
	ll t, d, finish = 0;
	queue<ll> q; //contains the finish time of every process
	
	cin >> n >> b;
	while (n--) {
		cin >> t >> d;
		while (!q.empty() && q.front() <= t) {
			q.pop();
		}
		if (q.size() <= b) {
			finish = max(finish, t) + d;
			cout << finish << " ";
			q.push(finish);
		} else {
			cout << "-1" << " ";
		}
	}
	while (!q.empty()) {
		q.pop();
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

