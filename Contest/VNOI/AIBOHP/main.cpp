#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int LCS(string s, string t) {
	int n = s.size();
	int dp[n + 1][n + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (s[i - 1] == t[i - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][n];
}

int main(void){
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		string t(s);
		reverse(s.begin(), s.end());
		int number = LCS(s, t);
		DEBUG(number);
	}
	return 0;
}
