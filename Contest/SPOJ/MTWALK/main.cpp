#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };
#define MAX 111
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int maxh, minh;
int h[MAX][MAX];
int c[MAX][MAX];
int n;

void init(){
	cin >> n;
	maxh = 0;
	minh = 1e5;
	FOR(i, 1, n){
		FOR(j, 1, n){
			cin >> h[i][j];
			maxh = max(maxh, h[i][j]);
			minh = min(minh, h[i][j]);
		}
	}
	for(int i = 0; i < n + 1; i++){
		c[0][i] = 2;
		c[i][0] = 2;
		c[n + 1][i] = 2;
		c[i][n + 1] = 2;
	}
}

void dfs(int x, int y){
	c[x][y] = 1;
	for(int i = 0; i < 4; i++){
		if(c[x + dx[i]][y + dy[i]] == 0){
			c[x + dx[i]][y + dy[i]] = 1;
			dfs(x + dx[i], y + dy[i]);
		}
	}
}
bool moveable(int min, int max){
	FOR(i, 1, n){
		FOR(j, 1, n){
			if(h[i][j] < min || h[i][j] > max){
				c[i][j] = 2;
			}else{
				c[i][j] = 0;
			}
		}
	}
	if(c[1][1] > 0) return false;
	if(c[n][n] > 0) return false;
	c[1][1] = 1;
	dfs(1, 1);
	if(c[n][n] == 0) return false;
	return true;
}
bool move(int d){
	for(int i = minh; i + d <= maxh; i++){
		if(moveable(i, i + d)) return true;
	}
	return false;
}

void process(void){
	int l = 0;
	int r = maxh - minh;
	int m;
	while(l <= r){
		if(l == r){
			cout << r;
			return;
		}
		if(r - l == 1){
			if(move(l)){
				cout << l;
				return;
			}
			cout << r;
			return;
		}
		m = (l + r) / 2;
		if(move(m)) r = m;
		else l = m + 1;
	}
}

int main(void){
	init();
	process();
	return 0;
}
