//https://www.hackerrank.com/challenges/bfsshortreach/problem
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
const int MAX = 1001;
int n, m, s;
vector<int> edges[MAX];
bool visited[MAX];
int path[MAX];

int calculatePath(int index) {
	if (path[index] == -1) {
		return -1;
	}

	int total = 0;
	while (path[index] != -1) {
		total += 6;
		index = path[index];
	}
	return total;
}

void solve() {
	int q; cin >> q;
	while (q--) {
		memset(visited, false, sizeof(visited));
		memset(path, -1, sizeof(path));
		fori (i, 1, 1000) {
			edges[i].clear();
		}

		cin >> n >> m;
		queue<int> q;
		fori (i, 1, m) {
			int from, to;
			cin >> from >> to;
			edges[from].pb(to);
			edges[to].pb(from);
		}

		cin >> s;
		q.push(s);
		visited[s] = true;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < (int)edges[u].size(); i++) {
				int v = edges[u][i];
				if (!visited[v]) {
					path[v] = u;
					visited[v] = true;
					q.push(v);
				}
			}
		}
		int res[n + 1];
		fori (i, 1, n) {
			if (i != s) {
				cout << calculatePath(i) << " ";
			}
		}
		cout << endl;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

