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
const int MAX = 2005;
int ranked[MAX];

void solve() {
	int n; cin >> n;
	int a[n + 1], sorted_a[n + 1];
	int rating;
	for (int i = 0; i < n; i++) {
		cin >> rating;
		a[i] = sorted_a[i] = rating;
	}
	sort(sorted_a, sorted_a + n, [&](const int &left, const int &right) {
		return left > right;
	});
	for (int i = 0; i < n; i++) {
		rating = sorted_a[i];
		if (!ranked[rating]) {
			ranked[rating] = i + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ranked[a[i]] << " ";
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

