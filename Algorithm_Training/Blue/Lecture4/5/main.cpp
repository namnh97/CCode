//https://www.spoj.com/problems/MMASS/
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

int convert(char c) {
	switch(c) {
		case 'C': return 12;
		case 'O': return 16;
		default: return 1;
	} 
}

void solve() {
	string s; cin >> s;
	stack<int> atoms;
	for (auto &it : s) {
		if (isalpha(it)) {
			atoms.push(convert(it));
		}
		else if (isdigit(it)) {
			int digit = atoms.top();
			atoms.pop();
			digit = digit * (it - '0');
			atoms.push(digit);
		}
		else if (it == '(') {
			atoms.push(-1);
		}
		else if (it == ')') {
			int total = 0;
			while (atoms.top() != -1) {
				total += atoms.top();
				atoms.pop();
			}	
			atoms.pop();
			atoms.push(total);
		}
	}
	int res = 0;
	while (!atoms.empty()) {
		res += atoms.top();
		atoms.pop();
	}
	cout << res;
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

