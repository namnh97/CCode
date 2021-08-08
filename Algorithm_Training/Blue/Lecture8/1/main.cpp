//https://www.spoj.com/problems/TRVCOST/
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
const int MAX = 505;
vector<pair<int, int>> graph[MAX];
int dist[MAX];
int n, a, b, w, q;

struct Compare {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		return a.second > b.second;
	}
};

int dijkstra(int start, int finish) {
	fori (i, 0, MAX) dist[i] = MAX;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
	q.push({start, 0});
	dist[start] = 0;
	while (!q.empty()) {
		pair<int, int> u = q.top(); q.pop();
		if (dist[u.first] != u.second) {
			continue;
		}
		for (int i = 0;  i < (int)graph[u.first].size(); i++) {
			pair<int, int> v = graph[u.first][i];
			if (dist[v.first] > u.second + v.second) {
				dist[v.first] = u.second + v.second;
				q.push({v.first, dist[v.first]});
			}
		}
	}
	return dist[finish];
}	

void solve() {
	cin >> n;
	fori (i, 1, n) {
		cin >> a >> b >> w;
		graph[a].pb({b, w});
		graph[b].pb({a, w});
	}
	int u; cin >> u;
	cin >> q;
	while (q--) {
		int v; cin >> v;
		int res = dijkstra(u, v);
		if (res == MAX) {
			cout << "NO PATH" << endl;
		} else {
			cout << res << endl;
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

