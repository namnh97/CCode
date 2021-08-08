//https://codeforces.com/problemset/problem/448/B
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

bool isArray(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return  s == t;
}

bool isAutomaton(string s, string t) {
	int index = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == t[index]) {
			index++;
		}
	}
	return index == (int)t.size();
}

bool isBoth(string s, string t) {
	for (auto it : t) {
		int index = s.find(it);
		if (index == -1) return false;
		s[index]='0';
	}
	return true;
}

void solve() {
	string s, t;
	cin >> s >> t;
	if (isArray(s, t)) cout << "array";
	else if (isAutomaton(s, t)) cout << "automaton";
	else if (isBoth(s, t)) cout << "both";
	else cout << "need tree";
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


