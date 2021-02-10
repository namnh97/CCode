//https://www.spoj.com/problems/CAM5/
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

const int MAX = 100001;
vector<int> edges[MAX];
bool visited[MAX];

void dfs(int index) {
	stack<int> s;
	s.push(index);
	visited[index] = true;
	while (!s.empty()) {
		int u = s.top();
		s.pop();
		for (int i = 0; i < (int)edges[u].size(); i++) {
			int v = edges[u][i];
			if (visited[v] == false) {
				visited[v] = true;
				s.push(v);
			}
		}
	}
}

void solve() {
	int t; cin >> t;
	while (t--) {
		memset(visited, false, sizeof(visited));
		for (auto &it : edges) {
			it.clear();
		}
		int res = 0;
		int n, e; cin >> n >> e;
		for (int i = 0; i < e; i++) {
			int from, to;
			cin >> from >> to;
			edges[from].pb(to);
			edges[to].pb(from);
		}
		for (int i = 0; i < n; i++) { 
			if (visited[i] == false) {
				dfs(i);
				res++;
			}
		}
		cout << res << endl;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

