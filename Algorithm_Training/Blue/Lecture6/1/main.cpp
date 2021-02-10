//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
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
vector<int> edges[MAX];
bool visited[MAX];
int path[MAX];
int n, q;

int calculateDistance(int index) {
	int distance = 0;
	while (path[index] != 0) {
		index = path[index];
		distance++;
	}
	return distance;
}

void solve() {
	memset(visited, false, sizeof(visited));
	memset(path, 0, sizeof(path));
	cin >> n;
	fori (i, 2, n) {
		int from, to;
		cin >> from >> to;
		edges[from].pb(to);
		edges[to].pb(from);
	}

	stack<int> s;
	s.push(1);
	visited[1] = true;
	while (!s.empty()) {
		int u = s.top();
		s.pop();
		for (auto &it : edges[u]) {
			int v = it;
			if (visited[v] != true) {
				s.push(v);
				visited[v] = true;
				path[v] = u;
			}
		}
	}
	int q; cin >> q;
	int minDis = MAX;
	int res = -1;
	while (q--) {
		int id; cin >> id;
		int distance = calculateDistance(id);
		if (minDis > distance) {
			minDis = distance;
			res = id;
		} else if (minDis == distance && res > id) {
			res = id;
		}
	}
	cout << res << endl;
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

