#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

void add(int p, int k, int id = 1, int l = 0, int r = n){
	s[id].insert(k);
	if(r - l < 2) return;
	int mid = (l + r) / 2;
	if(p < mid)
		add(p, k, 2 * id, l, mid);
	else
		add(p, k, 2 * id + 1, mid, r);
}

int ask(int x, int y, int k, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y){
		return s[id].count(k);
	}
	int mid = (l + r) / 2;
	return ask(x, y, k, 2 * id, l, mid) + ask(x, y, k, 2 * id + 1, mid, r);
}

int main(void){
	return 0;
}