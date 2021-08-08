//https://acm.timus.ru/problem.aspx?space=1&num=1837
#include<bits/stdc++.h>
#define ll long long 
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

const int MAX = 305;
map<string, int> id;
vector<int> graph[MAX];
int dist[MAX];
int n;
string a, b, c;

void BFS(string s) {
	memset(dist, -1, sizeof(dist));
	if (id.find(s) != id.end()) {
		queue<int> q;
		dist[id[s]] = 0;
		q.push(id[s]);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto &it : graph[u]) {
				int v = it;
				if (dist[v] == -1) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
	}

}

void solve() {
	cin >> n;
	int cnt = 0;
	while (n--) {
		cin >> a >> b >> c;
		if (id.find(a) == id.end()) id[a] = cnt++;
		if (id.find(b) == id.end()) id[b] = cnt++;
		if (id.find(c) == id.end()) id[c] = cnt++;

		int x = id[a], y = id[b], z = id[c];
		graph[x].pb(y);
		graph[x].pb(z);

		graph[y].pb(x);
		graph[y].pb(z);

		graph[z].pb(x);
		graph[z].pb(y);
		
	}
	BFS("Isenbaev");
	
	for (auto &it : id) {
		cout << it.first << " ";
		if (dist[it.second] == -1) {
			cout << "undefined" << endl;
		} else {
			cout << dist[it.second] << endl;
		}
	}
}



int main(int argc, char** argv){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}



