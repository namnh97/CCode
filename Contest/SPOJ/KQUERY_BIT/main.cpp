#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

	
const int N = 30000+7, Q = 200000+7;
struct Query {
	int u, v, k, id;
	bool operator < (const Query &q) const {
		return k < q.k;
	}
};
 
int ans[Q], n, q, bit[N];
pair<int, int> a[N];
Query query[Q];
 
void enter() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i) {
		Query &q = query[i];
		scanf("%d%d%d", &q.u, &q.v, &q.k);
		q.id = i;
	}
}
 
void increase(int v) {
	for(; v <= n; v += v & -v) {
		++bit[v];
		DEBUG(v);
		DEBUG(bit[v]);
	}
}
 
int sum(int v) {
	int res = 0;
	for(; v != 0; v -= v & -v) res += bit[v];
	return res;
}
 
void solve() {
	sort(query+1, query+q+1);
	FOR(i, 1, q){
		DEBUG(query[i].k);
	}
	sort(a+1, a+n+1); int pos = n;
	FOR(i, 1, q){
		DEBUG(a[i].first);
	}
	for(int i = q; i >= 1; --i) {
		Query &q = query[i];
		while(a[pos].first > q.k)
			increase(a[pos--].second);
		ans[q.id] = sum(q.v) - sum(q.u - 1);
	}
}
 
void print() {
	for(int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
}
 
int main() {
	enter();
	solve();
	print();
	return 0;
}
