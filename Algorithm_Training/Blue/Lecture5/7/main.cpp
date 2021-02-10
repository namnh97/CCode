//https://codeforces.com/problemset/problem/540/C
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
void debugOut() {
	cerr << endl;
}

int stepX[4] = {-1, 1, 0, 0};
int stepY[4] = {0, 0, -1, 1};
const int MAX = 501;
char grid[MAX][MAX];
int n, m;


bool BFS(pii src, pii des) {
	queue<pii> q;
	q.push(src);
	grid[src.first][src.second] = 'X';
	while (!q.empty()) {
		pii u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = u.first + stepX[i];
			int nextY = u.second + stepY[i];
			if (nextX == des.first && nextY == des.second && grid[nextX][nextY] == 'X') return true;
			if (nextX <= n && nextX >= 1 && nextY <= m  && nextY >= 1 && grid[nextX][nextY] == '.') {
				grid[nextX][nextY] = 'X';
				q.push({nextX, nextY});
			}
		}
	}
	return false;

}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];
		}
	}
	pii src, des;
	cin >> src.first >> src.second;
	cin >> des.first >> des.second;
	bool canGo = BFS(src, des);
	if (canGo) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

