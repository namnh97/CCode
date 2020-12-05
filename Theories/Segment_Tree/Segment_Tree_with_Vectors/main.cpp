#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

//problem KQUERYO in spoj
typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

void build(int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		v[id].push_back(a[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	merge(v[2 * id].begin(), v[2 * id].end(), v[2 * id + 1].begin(), v[2 * id + 1].end(), back_inserter(v[id]));
	//Need to read more about back_inserterer
}
//function for solving queries

int cnt(int x, int y, int k, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= n){
		return v[id].size();
	}
	int mid = (l + r) / 2;
	return cnt(x, y, k, 2 * id, l, mid) + cnt(x, y, k, 2 * id + 1, mid, r);
}

int main(void){
	return 0;
}