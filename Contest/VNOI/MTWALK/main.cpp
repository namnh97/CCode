#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };
#define MAX 105

int h[MAX][MAX];
int c[MAX][MAX];
int n;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int maxh, minh;

using namespace std;


void init() {
	cin >> n;
	minh = 1e5;
	maxh = 0;
	//read  matrix
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> h[i][j];
			if (maxh < h[i][j]) maxh = h[i][j];
			if (minh > h[i][j]) minh = h[i][j];
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		c[i][0] = 2;
		c[0][i] = 2;
		c[n + 1][i] = 2;
		c[i][n + 1] = 2;
	}
}

void dfs(int x, int y) {
	c[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		if (c[x + dx[i]][y + dy[i]] == 0) {
			c[x + dx[i]][y + dy[i]] = 1;
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

bool moveable(int min, int max) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (h[i][j] <  min || h[i][j] > max) {
				c[i][j] = 2;
			} else {
				c[i][j] = 0;
			}
		}
	}
	if (c[1][1] > 0) return false;
	if (c[n][n] > 0) return false;
	c[1][1] = 1;
	dfs(1, 1);
	if (c[n][n] == 0) return false;
	return true;
}

bool move(int d) {
	for (int i = minh; i + d <= maxh; i++) {
		if (moveable(i, i + d)) return true;
	}
	return false;
}

//use binary search
void process() {
	int left = 0;
	int right = maxh - minh;
	int m;
	while (left <= right) {
		if (left == right) {
			cout << right;
			return;
		}
		if (right - left == 1) {
			if (move(left)) {
				cout << left;
				return;
			}
			cout << right;
			return;
		}
		m = (left + right) / 2;
		if (move(m)) right = m;
		else left = m + 1;
	}
}

int main(void) {
	init();
	process();
	return 0;
}
