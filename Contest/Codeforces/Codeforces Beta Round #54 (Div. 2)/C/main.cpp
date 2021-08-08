#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

const int MAX =  100001;

int a[MAX], d[MAX];
int n;

int main(void){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int k = n / 2 + n % 2;
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= k; i++) { // 0 - 1 -2 -3
		if (a[i] - i + 1 > 0) d[a[i] - i + 1]++;
	}
	for (int i = n; i > k; i--) { // -2 -1 0
		if (a[i] + i - n > 0) d[a[i] + i - n]++;
	}
	int m = -1; //
	for (int i = 1; i <= 100000; i++) {
		m = max(m, d[i]);
	}
	cout << n - m << endl;
	return 0;
}
