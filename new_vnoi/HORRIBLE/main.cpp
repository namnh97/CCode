#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

const int MAX = 100005;
long long int lazy[4 * MAX];
long long int seg[4 * MAX];
//build segment tree
void build(int low, int high, int node) {
	if (low > high) return;
	if (low == high) {
		seg[node] = 0;
		return;
	}
	int mid = (low + high) >> 1;
	build(low, mid, 2 * node + 1);
	build(mid + 1, high, 2 * node + 2);
	seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}

void update(int low, int high, int lq, int hq, int node, long long int val) {
	//down id
	if (lazy[node]) {
		seg[node] += (high - low + 1) * lazy[node];
		if (high != low) {
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (low > hq || high < lq) return;
	if (lq <= low && high <= hq) {
		seg[node] += (high - low + 1) * val;
		if (high != low) {
			lazy[2 * node + 1] += val;
			lazy[2 * node + 2] += val;
		}
		return;
	}

	int mid = (low + high) >> 1;
	update(low, mid, lq, hq, 2 * node + 1, val);
	update(mid + 1, high, lq, hq, 2 * node + 2, val);
	seg[node] = seg[2 * node + 1] +  seg[2 * node + 2];
}

long long int query(int low, int high, int lq, int hq, int node) {
	//down id
	if (lazy[node]) {
		seg[node] += (high - low + 1) * lazy[node];
		if (high != low) {
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (low > hq || high < lq) return 0;
	if (lq <= low && high <= hq) {
		return seg[node];
	}
	int mid = (low + high) >> 1;
	return query(low, mid, lq, hq, 2 * node + 1) + query(mid + 1, high, lq, hq, 2 * node + 2);
}
int main(void){
	int t, n, c;
	cin >> t;
	while (t--) {
		cin >> n >> c;
		memset(lazy, 0, sizeof(lazy));
		memset(seg, 0, sizeof(seg));
		build(0, n - 1, 0);
		while (c--) {
			int type, p, q;
			long long int val;
			cin >> type;
			if (type == 0) {
				cin >> p >> q >> val;
				update(0, n - 1, p - 1, q - 1, 0, val);
			} else {
				cin >> p >> q;
				cout << query(0, n - 1, p - 1, q - 1, 0) << endl;
			}
		}

	}
	return 0;
}
