//https://codeforces.com/problemset/problem/551/A
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

struct student {
	int val, index;
};

void solve() {
	int n; cin >> n;
	student a[n + 1];
	fori (i, 1, n) {
		cin >> a[i].val;
		a[i].index = i;
	}
	sort(a + 1, a + n + 1, [&] (const student &left, const student &right) {
		return left.val > right.val;
	});
	int b[n + 1] = {0};
	int rank = 1;
	b[a[1].index] = rank;
	for (int i = 2; i <= n; i++) {
		if (a[i].val == a[i - 1].val) {
			b[a[i].index] = rank;
		} else {
			rank = i;
			b[a[i].index] = rank;
		}
	}
	fori (i, 1, n) {
		cout << b[i] << " ";
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

