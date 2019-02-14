#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;
const int N = 200 * 1000 + 13;
const int LOGN = 30;

int n;
int a[N], pr[N];
int base[LOGN];

void try_gauss(int v){
	for(int i = LOGN - 1; i >= 0; --i){
		if(base[i] != -1 && (v & (1 << i))){
			v ^= base[i];
		}
	}
	if(v == 0) return;
	for(int i = LOGN - 1; i >= 0; i--){
		if(v & (1 << i)){
			base[i] = v;
			return;
		}
	}
}
int main(void){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(base, -1, sizeof(base));
	for(int i = 0; i < n; i++){
		pr[i + 1] = pr[i] ^ a[i];
		try_gauss(pr[i + 1]);
	}
	if(pr[n] == 0){
		cout << -1 << endl; return 0;
	}
	int siz = 0;
	for(int i = 0; i < LOGN; i++){
		siz += (base[i] != -1);
	}
	cout << siz << endl;
	return 0;
}


