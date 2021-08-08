#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

typedef vector< vector<int> > dsk;

int cha[800];

//function to find root
int find(int u){
	if(cha[u] != u) cha[u] = find(cha[u]);
	return cha[u];
}

vector<int> s;
bool visited[800], instack[800];

void dfs(int u, dsk &ke){
	visited[u] = true;
	instack[u] = true;
	s.push_back(u);
	for(int v : ke[u]){
		if(instack[v]){
			v = find(v);
			while(s.back() != v){
				cha[s.back()] = v
				s.pop_back();
			}
		}
	}
	for(int v : ke[u]) if(!visited[v]) dfs(v, ke);
	instack[u] = false;
	if(s.back() == u) s.pop_back();
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	dsk ke(n);
	while(m--){
		int u, v; cin >> u >> v;
		ke[u - 1].push_back(v - 1);
	}
	for(int i = 0; i < n; i++)  cha[i] = i;
	for(int i = 0; i < n; i++){
		if(!visited[i]) dfs(i, ke);
	}

	vector<int> f(n, 0);
	for(int i = 0; i < n; i++) f[i] = (cha[i] == i);
	for(int i = 0; i < n; i++){
		for(int j : ke[i]){
			if(find(i) != find(j)) f[find(j)] = 0;
		}
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		res += f[i];
	}
	cout << res;
	return 0;
}
