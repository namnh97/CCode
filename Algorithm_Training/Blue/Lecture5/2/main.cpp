//https://www.spoj.com/problems/MAKEMAZE/
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

const int MAX = 21;
int n, m;
vector<pii> points;
int stepx[4] = {-1, 1, 0, 0};
int stepy[4] = {0, 0, 1, -1};
char maze[MAX][MAX];
int visited[MAX][MAX];
queue<pii> q;

void solve() {
	int t; cin >> t;
	while (t--) {
		memset(visited, 0, sizeof(visited));
		points.clear();
		cin >> m >> n;
		fori (i, 1, m) {
			fori (j, 1, n) {
				cin >> maze[i][j];
				if ((i == 1 || i == m || j == 1 || j == n) && maze[i][j] == '.') {
					points.pb({i, j});
				}
			}
		}
		if (n == 1 && m == 1) {
			cout << "invalid" << endl;
			continue;
		}
		if (points.size() == 2) {
			q.push(points[0]);
			while (!q.empty()) {
				pii u = q.front();
				q.pop();
				fori (i, 0, 3) {
					int nextx = u.first + stepx[i];
					int nexty = u.second + stepy[i];
					if (nextx <= m && nexty <= n && nextx >= 1 && nexty >= 1 && visited[nextx][nexty] != 1 && maze[nextx][nexty] == '.') {
						visited[nextx][nexty] = 1;
						q.push({nextx, nexty});
					} 
				}
			}
			if (visited[points[1].first][points[1].second] == 1) {
				cout << "valid" << endl;
			} else {
				cout << "invalid" << endl;
			}
		} else {
			cout << "invalid" << endl;
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

