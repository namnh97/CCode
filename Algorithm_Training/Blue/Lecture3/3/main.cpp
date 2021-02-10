//https://codeforces.com/problemset/problem/451/B
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
	vector<int> a(n), b(n);
	fori (i, 0, n - 1) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	int left = 0, right = 0;
	fori (i, 0, n - 1) {
		if (a[i] != b[i]) {
			left = i;
			break;
		}
	}
	ford (i, n - 1, 0) {
		if (a[i] != b[i]) {
			right = i;
			break;
		}
	}
	for (int i = left, j = right; i < j; i++, j--) {
		swap(a[i], a[j]);
	}
	if (a != b) {
		cout << "NO";
	} else {
		cout << "YES" << endl;
		cout << left + 1 << " " << right + 1;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

