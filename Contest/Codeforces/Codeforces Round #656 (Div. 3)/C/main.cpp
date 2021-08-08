#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define debug(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;
int t, n, x, res;
int main(void){
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int pos = n - 1;
		debug(pos);
		while (pos > 0 && a[pos - 1] >= a[pos]) pos--;
		while (pos > 0 && a[pos - 1] <= a[pos]) pos--;
		cout << pos << endl;
	}
	return 0;
} 
