//https://codeforces.com/problemset/problem/224/B
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
	vector<int> a(n + 1);
	fori (i, 1, n) {
		cin >> a[i];
	}
	map<int, int> marked;
	int cnt = 0;
	int left = 0, right = 0;
	bool flag = false;
	fori (i, 1, n) {
		if (marked[a[i]]) {
			continue;
		}
		marked[a[i]] = 1;
		cnt++;
		if (cnt == k) {
			right = i;
			flag = true;
			break;
		}
	}
	marked.clear();
	cnt = 0;
	for (int i = right; i >= 1; i--) {
		if (marked[a[i]]) {
			continue;
		}
		marked[a[i]] = 1;
		cnt++;
		if (cnt == k) {
			left = i;
			break;
		}
	}
	if (flag) {
		cout << left << " " << right;
	} else {
		cout << "-1 -1";
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


