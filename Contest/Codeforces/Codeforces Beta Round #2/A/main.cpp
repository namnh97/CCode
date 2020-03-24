#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;


int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif	

	int n; cin >> n;
	map<string, long int> mp;
	string s[10001];
	int a[10001];

	for (int i = 0; i < n; i++) {
		cin >> s[i] >> a[i];
		mp[s[i]] += a[i];
	}
	long int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mp[s[i]], mx);
	}
	string ans;
	map<string, long int> mp2;
	for (int i = 0; i < n; i++) {
		mp2[s[i]] += a[i];
		if (mp2[s[i]] >= mx && mp[s[i]] == mx) {
			ans = s[i];
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
