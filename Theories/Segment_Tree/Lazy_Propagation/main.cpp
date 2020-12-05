#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

//problem poster in SPOJ
//shift function 
void shift(int id){
	if(lazy[id]){
		lazy[2 * id] = lazy[2 * id + 1] = lazy[id];
	}
	lazy[id] = 0;
}

//update node
void upd(int x, int y, int color, int id = 0, int l = 0, int r = n){
	if(x >= r || l >= y)  return;
	if(x <= l && r <= y){
		lazy[id] = color;
		return;
	}
	int mid = (l + r) / 2;
	shift(id);
	upd(x, y, color, 2 * id, l, mid);
	upd(x, y, color, 2 * id + 1, mid, r);}
//function query

set<int> se;
void cnt(int id = 1, int l = 0, int r = n){
	if(lazy[id]){
		se.insert(lazy[id]);
		return;
	}
	if(r - l < 2)  return;
	int mid = (l + r) / 2;
	cnt(2 * id, l, mid);
	cnt(2 * id + 1, mid, r);
}
int main(void){

	return 0;
}