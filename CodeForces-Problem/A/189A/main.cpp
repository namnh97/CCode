#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;



typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int n, a[3];
	int f[6000];
	cin >> n >> a[0] >> a[1] >> a[2];
	memset(f, -1, sizeof f);
	f[0] = 0;
	for(int i = 0; i < 3; i++){
		int m = n - a[i];
		for(int j = 0; j <= m; j++){
			DEBUG(~f[j]);
			if(~f[j]){
				f[j + a[i]] = max(f[j + a[i]], f[j] + 1);
			}
		}
	}
	cout << f[n];
	return 0;
}