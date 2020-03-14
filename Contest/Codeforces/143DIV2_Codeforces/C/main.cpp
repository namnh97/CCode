#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };
#define MAX 100005
using namespace std;

ll a[100005], sum[100005];
ll n, k, m, cnt, val;

int check(int tmp) {
	for (int i = tmp; i <= n; i++) {
		if (sum[i] - sum[i - tmp] + k >= tmp * a[i]) {
			cnt = tmp;
			val = a[i];
			return 1;
		}
	}
	return 0;
}

int main(void){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int h = 1, t = n, mid;
	while (h <= t) {
		mid = (h + t) / 2;
		if (check(mid)) {
			h = mid + 1;
		} else {
			t = mid - 1;
		}
	}
	cout << cnt << " " << val << endl;
	return 0;
}

