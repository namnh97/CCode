#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };
#define MOD 100000000

using namespace std;

int n1, n2, k1, k2;
int dp[101][101][11][11];

int solve(int n1, int n2, int l1, int l2) {
	if (dp[n1][n2][l1][l2] != -1) return dp[n1][n2][l1][l2];
	if (n1 + n2 == 0) return 1;
	int optFirst = 0, optSecond = 0;

	if (l1 < k1 && n1 > 0) {
		optFirst = solve(n1 - 1, n2, l1 + 1, 0) % MOD;
	}
	if (l2 < k2 && n2 > 0) {
		optSecond = solve(n1, n2 - 1, 0, l2 + 1) % MOD;
	}
	return dp[n1][n2][l1][l2] = (optFirst + optSecond) % MOD;
}


int main(void){
	while (cin >> n1 >> n2 >> k1 >> k2) {
		memset(dp, -1, sizeof dp);
		cout << solve(n1, n2, 0, 0) << endl;
	}
	return 0;
}
