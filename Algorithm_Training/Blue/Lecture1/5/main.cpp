// https://codeforces.com/problemset/problem/572/A
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
	int na, nb, k, m;
	vector<int> a, b;
	cin >> na >> nb;
	cin >> k >> m;
	for (int i = 0; i < na; i++) {
		int tmp; cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < nb; i++) {
		int tmp; cin >> tmp;
		b.push_back(tmp);
	}
	if (a[k - 1] < b[nb - m]) cout << "YES";
	else cout << "NO";
}



int main(void){
	// #ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
	// #endif
	solve();
	return 0;
}


