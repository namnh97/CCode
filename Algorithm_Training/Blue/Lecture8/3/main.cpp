//https://www.spoj.com/problems/SHPATH/
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

const ll MAX = 10001;
map<string, ll> cities;
ll t, n, p;
vector<pii> edge[MAX];
ll dist[MAX];
string name;

struct Compare {
	bool operator() (const pair<ll, ll> &a, const pair<ll, ll> &b) const {
		return a.second > b.second;
	}
};

ll dijkstra(ll source, ll sink) {
	fori (i, 0, MAX - 1) {
		dist[i] = INT_MAX;
	}
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> pq;
	pq.push({source, 0});
	dist[source] = 0;
	while (!pq.empty()) {
		ll u = pq.top().first;
		ll w = pq.top().second;
		pq.pop();
		if (dist[u] != w) continue;
		for (ll i = 0; i < (ll)edge[u].size(); i++) {
			ll v = edge[u][i].first;
			ll cost = edge[u][i].second;
			if (dist[v] > w + cost) {
				dist[v] = w + cost;
				pq.push({v, dist[v]});
			}
		}
	}
	return dist[sink];
}

void solve() {
	cin >> t;
	while (t--) {
		cin >> n;
		fori (i, 1, n) {
			cin >> name;
			cities[name] = i;
			cin >> p;
			while (p--) {
				ll des, cost; cin >> des >> cost;
				edge[i].pb({des, cost});
			}
		}
		ll r; cin >> r;
		while (r--) {
			string source, sink;
			cin >> source >> sink;
			ll res = dijkstra(cities[source], cities[sink]);
			cout << res << endl;
		}
		cities.clear();
		for (int i = 0; i < MAX; i++) {
			edge[i].clear();
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

