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

const int MAX = 251;
int n, m;
char matrix[MAX][MAX];
int stepX[4] = {-1, 1, 0, 0};
int stepY[4] = {0, 0, -1, 1};

bool isValid(int row, int col) {
	return row >= 1 && row <= n && col >= 1 && col <= m && (matrix[row][col] != '#');
}

bool isOut(int row, int col) {
	return (row == 1 || row == n) && (col == 1 || col == m) && (matrix[row][col] != '#');
}

pii BFS(int row, int col) {
	queue<pii> q;
	matrix[row][col] = '#';
	q.push({row, col});
	int sheeps = 0, wolves = 0;
	bool out = false;
	while (!q.empty()) {
		pii u = q.front(); q.pop();
		fori (i, 0, 3) {
			int nextX = u.first + stepX[i];
			int nextY = u.second + stepY[i];
			if (isValid(nextX, nextY)) {
				if (isOut(nextX, nextY)) {
					out = true;
				}
				if (matrix[nextX][nextY] == 'k') {
					sheeps++;
				} else if (matrix[nextX][nextY] == 'v') {
					wolves++;
				}
				q.push({nextX, nextY});
				matrix[nextX][nextY] = '#';
			}
		}
	}
	if (out) {
		return {sheeps, wolves};
	} else {
		return (sheeps > wolves) ? make_pair(sheeps, 0) : make_pair(0, wolves);
	}
}

void solve() {
	cin >> n >> m;
	fori (i, 1, n) {
		fori (j, 1, m){ 
			cin >> matrix[i][j];
		}
	}
	vector<pii>  res;
	fori (i, 1, n) {
		fori (j, 1, m) {
			if (matrix[i][j] == '.') {
				pii tmp = BFS(i, j);
				res.pb(tmp);
			}
		}
	}
	int sheeps = 0, wolves = 0;
	for (auto &it : res) {
		sheeps += it.first;
		wolves += it.second;
	}
	cout << sheeps << " " << wolves;
}

int main(int argc, char** argv){
	#ifndef ONLINE_JUDGE
	freopen(argv[1], "r", stdin);
	#endif
	solve();
	return 0;
}

