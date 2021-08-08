//https://codeforces.com/problemset/problem/723/D
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
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


struct Lake {
	int i, j, cnt;
};

const int MAX = 51;
char matrix[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> waterCells;
vector<Lake> lakes;
int n, m, k;
int stepx[4] = {-1, 1, 0, 0};
int stepy[4] = {0, 0, - 1, 1};

template<typename T, std::size_t N, std::size_t M>
int dfs(int x, int y, T (&a)[N][M]) {
	int cnt = 1;
	stack<pair<int, int>> s;
	s.push({x, y});
	a[x][y] = true;
	while (!s.empty()) {
		pair<int, int> u = s.top();
		s.pop();
		fori (i, 0, 3) {
			int nextx = u.first + stepx[i];
			int nexty = u.second + stepy[i];
			if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && a[nextx][nexty] == false) {
				s.push({nextx, nexty});
				a[nextx][nexty] = true;
				cnt++;
			}
		}
	}
	return cnt;
}
bool cmp(const Lake &a, const Lake &b) {
	return a.cnt < b.cnt;
}

void solve() {
	cin >> n >> m >> k;
	memset(visited, false, sizeof(visited));
	fori (i, 0, n - 1) {
		fori (j, 0, m - 1) {
			cin >> matrix[i][j];
			if (matrix[i][j] == '.') {
				waterCells.push_back({i, j});
			} else {
				visited[i][j] = true;
			}
		}
	}

	fori (i, 0, n - 1) {
		fori (j, 0, m - 1) {
			if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && visited[i][j] == false) {
				dfs(i, j, visited);
			}
		}
	}
	
	bool finalMatrix[MAX][MAX], minimumMatrix[MAX][MAX];

	fori (i, 0, n - 1){
		fori (j, 0, m - 1) {
			finalMatrix[i][j] = visited[i][j];
			minimumMatrix[i][j] = visited[i][j];
		}
	}

	for (auto &it : waterCells) {
		if (visited[it.first][it.second] == false) {
			int cnt = dfs(it.first, it.second, visited);
			Lake a;
			a.i = it.first; a.j = it.second; a.cnt = cnt;
			lakes.push_back(a);
		};
	}

	sort(lakes.begin(), lakes.end(), cmp);
	int res = 0;
	for (int i = 0; i + k < (int)lakes.size(); i++) {
		 res += dfs(lakes[i].i, lakes[i].j,  minimumMatrix);
	}
	
	cout << res << endl;
	fori (i, 0, n - 1) {
		fori (j, 0, m - 1) {
			if (minimumMatrix[i][j] != finalMatrix[i][j]) {
				cout << "*";
			} else {
				cout << matrix[i][j];
			}
		}
		cout << endl;
	}

};

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

