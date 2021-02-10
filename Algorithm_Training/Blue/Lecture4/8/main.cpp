//https://www.codechef.com/problems/COMPILER
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
	int n; cin >> n;
	string s;
	stack<int> xml;
	while (n--) {
		cin >> s;
		int res = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == '<') {
				xml.push(1);
			} else if (xml.empty()) {
				break;
			} else {
				xml.pop();
				if (xml.empty()) {
					res = i + 1;
				}	
			}
		}
		cout << res << endl;
		while (!xml.empty()) xml.pop();
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

