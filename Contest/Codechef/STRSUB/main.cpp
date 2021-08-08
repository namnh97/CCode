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

const int MAX = 100005;
int far[MAX];
int n, k, q;
int count0, count1;
string s;

void precompute() {
	count0 = 0;
	count1 = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		int j = i;
		while (j < n && count0 + 1 <= k && count1 + 1 <= k) {
			if (s[j] == '1') {
				count1++;
			}
			if (s[j] == '0') {
				count0++;
			}
			j++;
		}
		far[i] = j - 1;
		if (s[i] == '1') {
			count1--;
		} else {
			count0--;
		}
	}
}

int query(int l, int r) {
	int res = 0;
	for (int i = l - 1; i <= r - 1; i++) {
		int index = min(r - 1, far[i]);
		debug(index);
		res += index - i;
	}
	return res;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> k >> q;
		cin >> s;
		memset(far, 0x3f, sizeof(far));
		precompute();
		for (int i = 0; i < n; i++) debug(far[i]);
		for (int i = 1; i <= q; i++) {
			int l, r; 
			cin >> l >> r;
			cout << query(l, r) << endl;
		}
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


