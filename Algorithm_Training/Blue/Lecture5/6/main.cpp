//https://www.spoj.com/problems/UCV2013H/
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
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

const int MAX = 251;
int n, m, sea[MAX][MAX];
int slicks[MAX * MAX];
int stepx[4] = {-1, 1, 0, 0};
int stepy[4] = {0, 0, - 1, 1};

void bfs(int row, int col) {
	queue<pii> q;
	q.push({row, col});
	int numberOfAdj = 1;
	sea[row][col] = 0;
	while (!q.empty()) {
		pii u = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = u.first + stepx[i];
			int nexty = u.second + stepy[i];
			if (sea[nextx][nexty] == 1 && nextx >= 0 && nextx <= n - 1 && nexty >= 0 && nexty <= m - 1) {
				sea[nextx][nexty] = 0;
				q.push({nextx, nexty});
				numberOfAdj++;
			}
		}
	}
	slicks[numberOfAdj]++;
}

void solve() {
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		memset(sea, 0, sizeof(sea));
		memset(slicks, 0, sizeof(slicks));
		fori (i, 0, n - 1) {
			fori (j, 0, m - 1) {
				cin >> sea[i][j];
				slicks[i * m + j] = 0;
			}
		}

		int cnt = 0;
		fori (i, 0, n - 1) {
			fori (j, 0, m - 1) {
				if (sea[i][j] == 1) {
					cnt++;
					bfs(i, j);
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i <= n * m; i++) {
			if (slicks[i]) {
				cout << i << " " << slicks[i] << endl;
			}
		}
	}	
}




int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

