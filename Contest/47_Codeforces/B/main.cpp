#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	int cnt[200];
	char in[100000];
	double ans;
	cout << fixed << setprecision(0);
	while (cin >> in) {
		ans = 0;
		int n = strlen(in);
		memset(cnt, 0, sizeof (cnt));
		for (int i = 0; i < n; i++) {
			cnt[(int)in[i]]++;
		}
		for (int i = '0'; i <= 'z'; i++) {
			ans += (double)cnt[i] * cnt[i];
		}
		cout << ans << endl;
	}
    return 0;
}
