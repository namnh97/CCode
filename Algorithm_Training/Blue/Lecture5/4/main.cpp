//https://lightoj.com/problem/guilty-prince
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

const int MAX = 22;
char grids[MAX][MAX];
bool visited[MAX][MAX];
int w, h;
int startx, starty;
int stepx[4] = {-1, 1, 0, 0};
int stepy[4] = {0, 0, - 1, 1};

bool isValid(int row, int col) {
	return row >= 1 && row <= h && col >= 1 && col <= w;
}

void solve() {
	int t; cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		memset(visited, true, sizeof(visited));
		cin >> w >> h;
		fori (i, 1, h) {
			fori (j, 1, w) {
				cin >> grids[i][j];
				if (grids[i][j] == '@') {
					startx = i;
					starty = j;
					visited[i][j] = false;
				}
				if (grids[i][j] == '.') {
					visited[i][j] = false;
				}
			}
		}
		queue<pair<int, int>> q;
		q.push({startx, starty});
		visited[startx][starty] = true;
		int res = 1;
		while (!q.empty()) {
			pair<int, int> u = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nextx = u.first + stepx[i];
				int nexty = u.second + stepy[i];
				if (visited[nextx][nexty] == false && isValid(nextx, nexty)) {
					q.push({nextx, nexty});
					visited[nextx][nexty] = true;
					res++;
				}
			}
		}
		cout << "Case " << cas << ": " << res << endl;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

