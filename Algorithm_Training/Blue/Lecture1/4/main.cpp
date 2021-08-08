// https://codeforces.com/problemset/problem/518/A

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
	string s, t; cin >> s >> t;
	int i = (int)s.size() - 1;
	for (; i >= 0; i--) {
		if (s[i] == 'z') {
			s[i] = 'a';
		} else {
			s[i]++;
			break;
		}
	}
	for (i = (int)s.size() - 1; i >= 0; i--) {
		if (s[i] < t[i]) {
			cout << s;
			return;
		}
	}
	cout << "No such string";
}



int main(void){
	// #ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
	// #endif
	solve();
	return 0;
}


