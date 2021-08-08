#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define MAX 100005
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int n, m, k;
struct edge{
	int to, next;
};

edge e[MAX];
vector<int> vec1, vec2;
int head[MAX], deg[MAX], _deg[MAX];
int cnt;

void solve();
void addEdge(int u, int v);
int work();
void init();
int firstBFS();
int secondBFS();

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

void solve() {
	while (1) {
		cin >> n >> m >> k;
		if (!n || !m || !k) break;

		memset(head, -1, sizeof(head));
		memset(_deg, 0, sizeof(_deg));
		cnt = 0;
		for (int i = 0; i < k; i++) {
			int v, u;
			cin >> v >> u;
			addEdge(v, u);
			_deg[v]++;
		}
		cout << work() + 1 << endl;
	}
}

void addEdge(int v, int u) {
	e[cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
	cnt++;
}

int work() {
	int count = 0, res1 = 0, res2 = 0;
	for (int i = 1; i <= n + m; i++) {
		deg[i] = _deg[i];
	}
	init();
	while(1) {
		count += firstBFS();
		res1++;
		if (count == n + m) break;
		count += secondBFS();
		res1++;
		if (count == n + m) break;
	}
	init();
	while(1) {
		count += secondBFS();
		res2++;
		if (count == n + m) break;
		res2++;
		if (count == n + m) break;
	}
	return min(res1, res2);
}

void init() {
	vec1.clear();
	vec2.clear();
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			vec1.push_back(i);
		}
	}
	for (int i = n + 1; i <= n + m; i++) {
		if (deg[i] == 0) {
			vec2.push_back(i);
		}
	}
}

int firstBFS() {
	int num = 0;
	for (int i = 0; i < (int)vec1.size(); i++) {
		num++;
		int v = vec1[i];
		for (int i = head[v]; i != - 1; i = e[i].next) {
			int u = e[i].to;
			if (--deg[u] == 0) {
				if (u <= n) vec1.push_back(u);
				vec2.push_back(u);
			}
		}
	}
	vec1.clear();
	return num;
}

int secondBFS() {
	int num = 0;
	for (int i = 0; i < (int)vec2.size(); i++) {
		num++;
		int v = vec2[i];
		for (int i = head[v]; i != -1; i = e[i].next) {
			int u = e[i].to;
			if (--deg[u] == 0) {
				if (u <= n) vec1.push_back(u);
				vec2.push_back(u);
			}
		}
	}
	vec2.clear();
	return num;
}