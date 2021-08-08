#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;



typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int inArray[30005];
vi v[1000005];
int n, q;

void build(int id, int l, int r){
	if(l == r){
		v[id].push_back(inArray[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	merge(v[2 * id].begin(), v[2 * id].end(), v[2 * id + 1].begin(), v[2 * id + 1].end(), back_inserter(v[id]));
}

int query(int x, int y, int k, int id, int l, int r){
	if(x > r || y < l){
		return 0;
	}
	if(x <= l  && r <= y){
		return v[id].size() - (upper_bound(v[id].begin(), v[id].end(), k) - v[id].begin());
	}
	int mid  = (l + r) / 2;
	return query(x, y, k, 2 * id, l, mid) + query(x, y, k, 2 * id + 1, mid + 1, r);
}

int main(void){
	cin >> n;
	FOR(i, 0, n - 1) cin >> inArray[i];
	cin >> q;
	build(1, 0, n - 1);
	int ans = 0;
	while(q--){	
		int a, b, c;
		cin >> a >> b >> c;
		int i = ans ^ a;
		int j = ans ^ b;
		int k = ans ^ c;
		ans = query(i - 1, j - 1, k, 1, 0, n - 1);
		cout << ans << endl;

	}
	return 0;
}
