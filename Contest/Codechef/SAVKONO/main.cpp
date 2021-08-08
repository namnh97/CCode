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
	while (t--) {
		int n, k; cin >> n >> k;
		priority_queue<int> que;
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp;
			que.push(tmp);
		}
		int res = 0;
		while (que.top() != 0 && k >= 0){ 
			res++;
			int tmp = que.top();
			que.pop();
			k -= tmp;
			que.push(tmp/ 2);
		}
		if (k >= 0) cout << "Evacuate" << endl;
		else cout << res << endl;
	}
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


