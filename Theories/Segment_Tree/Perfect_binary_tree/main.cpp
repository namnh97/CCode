#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

const int N = 1e5; //limit for array size
int n;
int t[2 * N];

//function to build segmentree
void build(){
	for(int i = n - 1; i > 0; i--){
		t[i] = t[i << 1] + t[i << 1 | 1]; //is the same with t[2 * i] + t[2 * i  + 1];
	}
}

//function to update value of tree node
void modify(int p, int value){
	for(t[p += n] = value; p > 1; p >>= 1){
		t[p >> 1] = t[p] + t[p ^ 1];
	}
}

int query(int l, int r){
	int res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1){
		if(l & 1) res += t[l++];
		if(r & 1) res += t[--r];
	}
	return res;
}
int main(void){
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%d", t + n + i);
	}
	build();
	modify(0, 1);
	cout << query(3, 11);
	return 0;
}