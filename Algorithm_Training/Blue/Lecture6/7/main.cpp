//https://www.spoj.com/problems/ABCPATH/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
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

const int MAX = 51;
int n, m;
char matrix[MAX][MAX];
int visited[MAX][MAX];
int stepr[] = {0, 0, 1, 1, 1, -1, -1, -1};
int stepc[] = {1, -1, 0, 1, -1, 0, 1, -1};

bool isValid(int row, int col) {
	return row >= 0 && row < n && col >= 0 && col < m;
}

int DFS(int row, int col) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int nextr = row + stepr[i];
		int nextc = col + stepc[i];
		if (isValid(nextr, nextc) && (matrix[nextr][nextc] - matrix[row][col] == 1) && visited[nextr][nextc] == 0) {
			DFS(nextr, nextc);
			cnt = max(cnt, visited[nextr][nextc]);
		}
	}
	visited[row][col] = cnt + 1;
	return visited[row][col];
}

void solve() {
	int cas = 0;
	while (cin >> n >> m && n != 0 && m != 0) {
		cout << "Case " << ++cas << ": ";
		for (int i = 0; i < n; i++ ) {
			for (int j = 0; j < m; j++) {
				cin >> matrix[i][j];
				visited[i][j] = 0;;
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++ ) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == 'A') {
					res = max(res, DFS(i, j));
				}
			}
		}
		cout << res << endl;
	}
}



int main(int argc, char** argv){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}



