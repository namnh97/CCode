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
	int n, k; cin >> n >> k;
	int countLess = 0, countEqual = 0;
	string tries[n];
	string password;
	fori (i, 0, n - 1) {
		cin >> tries[i];
	}
	cin >> password;
	fori (i, 0, n - 1) {
		if (tries[i].size() < password.size()) {
			countLess++;
		}
		if (tries[i].size() == password.size()) {
			countEqual++;
		}
	}
	int best = countLess + (5 * (countLess / k)) + 1;
	int worst = countLess + countEqual +(((countLess + countEqual - 1) / k) * 5);
	debug(countLess, countEqual);
	cout << best << " " << worst;
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


