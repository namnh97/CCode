#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	int n, d, l, ans[100];
	while (cin >> n >> d >> l) {
		int b = n / 2;
		int a = n - b;
		if (!(a - b * l <= d && d <= a * l - b)) {
			cout << -1  << endl;
			continue;
		}
		for (int i = 0; i < n; i++) {
			ans[i] = 1;
			d += i % 2 ? 1 : -1;
		}
		if (d > 0) {
			for (int i = 0; i < n; i += 2) {
				int p = min(d, l - ans[i]);
				ans[i] += p;
				d -= p;
				if (d <= 0) break;
			}
		} else if (d < 0) {
			for (int i = 1; i < n; i += 2) {
				int p = min(-d, l - ans[i]);
				ans[i] += p;
				d += p;
				if (d >= 0) break;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
