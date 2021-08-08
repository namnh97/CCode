#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;


const int nmax = 30009;
const int qmax 	= 200009;

struct Ques{
	int l, r, k, p;
};

int n, q;
Ques qu[qmax];
ii a[nmax];
int IT[nmax * 8];
int Lazy[nmax * 8];
int res[qmax];

bool comp(Ques x, Ques y){
	return x.k < y.k; 
}

void Update(int id, int l, int r, int u, int v, int k){
	IT[id] += Lazy[id] * (r - l + 1); //lazy multiply with range r - l
	Lazy[id * 2] += Lazy[id];
	Lazy[id * 2 + 1] += Lazy[id];
	Lazy[id] = 0;
	if(l > v || r < u) //out of range
		return;
	if(l >= u && r <= v){
		// in range of segment tree
		IT[id] += k * (r - l + 1);
		Lazy[id * 2] += k;
		Lazy[id * 2 + 1] += k;
		return;
	} 
	int mid = (l + r) / 2;
	Update(id * 2, l, mid, u, v, k);
	Update(id * 2 + 1, mid + 1, r, u, v, k);
	IT[id] = IT[id * 2] + IT[id * 2 + 1];
}

int Query(int id, int l, int r, int u, int v){
	IT[id] += Lazy[id] * (r - l + 1);
	Lazy[id * 2] += Lazy[id];
	Lazy[id * 2 +1 ] += Lazy[id];
	Lazy[id] = 0;
	if(l > v || r < u){
		//out of range
		return 0;
	}

	if(l >= u && r <= v){
		//in rage
		return IT[id];
	}
	int mid = (l + r) / 2;
	return Query(id * 2, l, mid, u, v) + Query(id * 2 + 1, mid + 1, r, u , v);

}

int Find(int l, int r, int k){
	while(l <= r){
		int mid = (l + r) / 2;
		if(a[mid].first >= k){
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return l;

}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	

	int n; cin >> n; //enter n 
	FOR(i, 1, n){
		cin >> a[i].first; //save value
		a[i].second = i; //save index
	}

	sort(a + 1, a + n + 1); //sort value array

	Update(1, 1, n, 1, n, 1); //update with id = 1 , 1, n, 1 , n with k = 1

	cin >> q;
	FOR(i, 1, q){
		cin >> qu[i].l >> qu[i].r >> qu[i].k; //save value
		qu[i].p = i; //save index
	}

	sort(qu + 1, qu + q + 1, comp); //Sorting depends on k
	int prev = 1;

	FOR(i, 1, q){
		int l = qu[i].l;
		int r = qu[i].r;
		int k = qu[i].k;
		int p = qu[i].p;
		int now = Find(prev, n, k + 1); //find (prev, n) with k value
		for(int i = prev; i < now; i++){
			Update(1, 1, n, a[i].second, a[i].second, -1);
		}
		prev = now;
		res[p] = Query(1, 1, n, l, r);
	}
	FOR(i, 1, q){
		cout << res[i] << endl;
	}
	return 0;
}