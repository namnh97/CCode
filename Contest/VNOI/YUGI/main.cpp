#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

const int N = 222;
using namespace std;
int a[N][N];
int n, k;

struct disjoint_set {
	int lab[N];
	disjoint_set() {
		//initialize
		for (int i = 1; i <= n; i++) {
			lab[i] = -1;
		}
	}
	int root(int u) {
	//get root 
		return lab[u] <= 0
				 ? u
				 : lab[u] = root(lab[u]);
	}
	void join(int u, int v) {
		int x = root(u);
		int y = root(v);
		if (x == y) return;
		if (lab[u] > lab[v]) swap(u, v);
		lab[v] = u;
		lab[u]--;
	}
};

int cnt(int lim) {
	disjoint_set dsu;
	int cc = n;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i][j] < lim) {
				int x = dsu.root(i);
				int y = dsu.root(j);
				if (x != y) {
					dsu.join(x, y);
					cc--;
				}
			}
		}
	}
	return cc;
}


int main(void){
	cin >> n >> k; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	int l = 0, r = 1 << 16, m, res = 0;
	while (l <= r) {
		m = (l + r) >> 1;
		if (cnt(m) >= k) {
			res = m;
			l = m + 1;
		} else {
			r = m - 1;
		} 
	}
	cout << res;
	return 0;
}
