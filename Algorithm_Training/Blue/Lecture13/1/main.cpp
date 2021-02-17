//https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/distinct-count/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
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
		int n, m;
		set<int> s;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp;
			s.insert(tmp);
		}
		if ((int)s.size() == m) {
			cout << "Good" << endl;
		} else if ((int)s.size() < m) { 
			cout << "Bad" << endl;
		} else {
			cout << "Average" << endl;
		}
	}
}



int main(int argc, char** argv){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}



