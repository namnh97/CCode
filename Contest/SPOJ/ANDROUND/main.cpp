#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
const double EPS=1e-9;
const int MAX = 1 << 15;
int IT[MAX << 1], a[MAX];
int t, n, _k, k;
int res;

void build(int node, int left, int right) {
	if (left == right) {
		IT[node] = a[left];
		cerr << left << ": " << a[left] << endl;
		return;
	}
	int mid = (left + right) / 2;
	build(2 * node, left, mid);
	build(2 * node + 1, mid + 1, right);
	IT[node] = IT[2 * node] & IT[2 * node + 1];
}

int query(int node, int left, int right, int start, int end) {
	if (left >= end || right <= start) return -1;
	if (start <= left && right <= end) return IT[node];
	int mid = (left + right) >> 1;
	int leftValue = query(2 * node, left, mid, start, end);
	int rightValue = query(2 * node + 1, mid + 1, right, start, end);
	return leftValue & rightValue;
}


void solve() {
	cin >> t;
	for(int cs = 0; cs < t; cs++) {
		cin >> n >> _k;
		k = min(_k, n - 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		build(1, 0, n - 1);
		for (int i = 0; i < n; i++) {
			int s = (i - k + n) % n;
			int e = (i + k) % n;
			int res = -1;
			if (s < i) res &= query(1, 0, n - 1, s, i);
			else {
				res &= query(1, 0, n - 1, 0, i) & query(1, 0, n - 1, s, n - 1);
			}
			if (e > i) {
				res &= query(1, 0, n - 1, i, e);
			} else {
				res &= query(1, 0, n - 1, i, n - 1) & query(1, 0, n - 1, 0, e);
			}
			cout << res << " ";
		}
		cout << endl;

	}
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

