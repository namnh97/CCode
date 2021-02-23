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

string getAnswer(string number) {
	int digit = number[number.size() - 1] - '0' + 1;
	int carry = 0;
	carry = digit / 10;
	digit = digit  % 10;
	number[number.size() - 1] = digit + '0';
	int i = number.size() - 2;
	for (; i >= 0; i--) {
		if (carry == 0) break;
		digit = number[i] - '0' + digit + carry;
		debug(digit);
		carry = digit / 10;
		digit = digit % 10;
		number[i] = digit + '0';
	}
	string result;
	if (carry) {
		char charCarry = carry + '0';
		result.push_back(charCarry);
	}
	result += number;
	return result;
}
void solve() {
	int t; cin >> t;
	string s;
	while (t--) {
		cin >> s;
		cout << getAnswer(s) << endl;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


