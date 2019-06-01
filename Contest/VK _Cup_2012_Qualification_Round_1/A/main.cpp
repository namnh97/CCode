#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	int n, k; cin >> n >> k;
	int a[n + 1];
	int res = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		if (a[i] <= 0) continue;
		if (a[i] >= a[k])  res++;
		
	}
	cout << res << endl;

	return 0;
}
