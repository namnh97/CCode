#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;
int n, m;
char grid[12][12];
int res = 0;

int main(void){
	cin >> n >> m;
	for (int i = 0; i < 12; i++) {
		grid[i][0] = '.';
		grid[0][i] = '.';
		grid[i][11] = '.';
		grid[11][i] = '.';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];
		}
	}

	int res = 0;
	for (int i = 1; i <=n ; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid [i][j] == 'W')
				if (grid[i - 1][j] == 'P' || grid[i + 1][j] == 'P' || grid[i][j + 1] == 'P' || grid[i][j - 1] == 'P') {
					res++;
				}
		}
	}
	cout << res;
	return 0;
}
