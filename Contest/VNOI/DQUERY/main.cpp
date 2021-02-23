#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;
#define MAX 100000

int n, q;
int a[MAX];
set<int> IT[MAX];
set<int>::iterator it;

void build(int id, int l, int r) {
	if (r - l < 2) {
		IT[id].insert(a[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	for (it = IT[2 * id].begin(); it != IT[2 * id].end(); it++) {
		IT[id].insert(*it);
	}
	for (it = IT[2 * id + 1].begin(); it != IT[2 * id + 1].end(); it++) {
		IT[id].insert(*it); 
	}
}

void outSet(set<int> in) {
	for (it = in.begin(); it != in.end(); it++) {
		cout << *it << endl;
	}
}

set<int> query(int id, int x, int y, int l, int r) {
	if (l >= y || x >= r) return set<int>();
	if (x <= l && r <= y) { 
		 return IT[id];
	}
	int mid = (l + r) / 2;
	set<int> left = query(2 * id, x, y, l, mid);
	set<int> right = query(2 * id + 1, x, y, mid, r);
	set<int> res;
	for (it = left.begin(); it != left.end(); it++) {
		res.insert(*it);
	}
	for (it = right.begin(); it != right.end(); it++) {
		res.insert(*it);
	}
	return res;
}

void in() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> q;
	build(1, 0, n);
	while (q--) {
		int x, y;
		cin >> x >> y;
		set<int> res = query(1, x, y, 0, n);
		cout << res.size() << endl;
	}
}
int main(void){
	in();
	return 0;
}
