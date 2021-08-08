#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

//insert function
void insert(int p, int k, int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		v[id].push_back(k);
		return;
	}
	int mid = (l + r) / 2;
	if(p < mid){
		insert(p, k, 2 * id, l, mid);
	}
	else{
		insert(p, k, 2 * id + 1, mid, r);
	}
}

//sort function(after reading all queries);
void SORT(int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		return;
	}
	int mid = (l + r) / 2;
	SORT(2 * id, l, mid);
	SORT(2 * id + 1, mid,  r):
	merge(v[2 * id].begin(), v[2 * id].end(), v[2 * id + 1].begin(), v[2 * id + 1].end(), back_inserter(v[id]));
	v[id].resize(unique(v[id].begin(), v[id].end()) - v[id].begin());
	fen[id] = vector<int> (v[id].size() + 1, 0);
}

void upd(int p, int k, int id = 1, int l = 0, int r = n){
	int a = lower_bound(v[id].begin(), v[id].end(), k) - v[id].begin();
	for(int i = a + 1; i < fen[id].size(); i += i & -i){
		fen[id][i]++;
	}
	if(r - l < 2) return;
	int mid = (l + r) / 2;
	if(p < mid){
		upd(p, k, 2 * id, l, mid);
	}
	else{
		upd(p, k, 2 * id + 1, mid, r);
	}
}

int ask(int x, int y, int k, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y){
		int a = lower_bound(v[id].begin(), v[id].end(), k) - v[id].begin();
		int ans = 0;
		for(int i = a + 1; i > 0; i -= & -i){
			ans += fen[id][i];
		}
		return ans;
	}
	int mid = (l + r) / 2;
	return ask(x, y, k, 2 * id, l, mid) + ask(x, y, k, 2 * id + 1, mid, r);
}

int main(void){
	return 0;
}