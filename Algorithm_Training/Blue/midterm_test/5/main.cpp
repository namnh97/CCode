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

const int MAX = 205;
int V;
int dist[MAX];
vector<string> dict;
vector<int> graph[MAX];

void BFS(int s, int f) {
	fill(dist, dist + V, -1);
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto &v : graph[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
			if (v == f) return;
		}
	}
}

bool isNext(string parent, string child) {
	int cnt = 0;
	for (int i = 0; i < (int)parent.size(); i++) {
		if (parent[i] != child[i]) cnt++;
	}
	return cnt == 1;
}

void solve() {
	int N;
	string line, word, sWord, fWord;
	cin >> N;
	while (N--) {
		while (cin >> word && word != "*") {
			dict.pb(word);
		}
		V = dict.size();
		for (int i = 0; i < V; i++) {
			graph[i].clear();
		}
		for (int u = 0; u < V - 1; u++) {
			for (int v = u + 1; v < V; v++) {
				if (dict[u].size() == dict[v].size() && isNext(dict[u], dict[v])) {
					graph[v].pb(u);
					graph[u].pb(v);
				}
			}
		}
		cin.ignore();
		while (getline(cin, line) && line != "") {
			stringstream ss(line);
			ss >> sWord >> fWord;
			int s = find(dict.begin(), dict.end(), sWord) - dict.begin();
			int f = find(dict.begin(), dict.end(), fWord) - dict.begin();
			BFS(s, f);
			cout << sWord << " " << fWord << " " << dist[f] << endl;
		}
	}
}

int main(void){
	solve();
	return 0;
}
