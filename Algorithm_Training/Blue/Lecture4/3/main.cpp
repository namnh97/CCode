//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1876
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
	while (1) {
		int n; cin >> n;
		vector<int> cards;
		if (n == 0) return;
		fori (i, 1, n) {
			cards.pb(i);
		}
		cout << "Discarded cards:";
		while (cards.size() != 1) {
			cout <<  " " << cards.front();
			cards.erase(cards.begin());
			if (cards.size() != 1) {
				cout << ",";
			}
			cards.pb(cards.front());
			cards.erase(cards.begin());
		}
		cout << endl;
		cout << "Remaining card: " << cards[0] << endl;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

