// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/dhoom-4/
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
ll n, key, des;
ll otherKeys[MAX];
ll dist[MAX];
bool visited[MAX];

ll bfs() {
	memset(dist, -1, sizeof(dist));
	queue<ll> q;
	q.push(key);
	dist[key] = 0;
	while (!q.empty()) {
		ll u = q.front();
		q.pop();
		fori (i, 0, n - 1) {
			ll v = (u * otherKeys[i]) % 100000;
			if (dist[v] == - 1) {
				dist[v] = dist[u] + 1;
				if (v == des) {
					return dist[v];
				}
				q.push(v);
			}
		}
	}
	return -1;
}
void solve() {
	cin >> key >> des;
	cin >> n;
	fori (i, 0, n - 1) {
		cin >> otherKeys[i];
	}
	int res = bfs();
	cout << res << endl;
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

