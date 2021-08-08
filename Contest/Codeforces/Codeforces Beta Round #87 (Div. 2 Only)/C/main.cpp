#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;
int n;
int res = 0;
int countNode;
vector<int> adj[2002];
int root[2002];

void in() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		if (p == -1)  root[i] = 1;
		else {
			adj[--p].push_back(i);
		}
	}
}

void dfs(int index) {
	countNode++;
	res = max(countNode, res);
	for (int i = 0; i < (int)adj[index].size(); i++) {
		int child = adj[index][i];
		dfs(child);
		countNode--;
	}
}

void process() {
	for (int i = 0; i < n; i++) {
		if (root[i]) {
			countNode = 0;
			dfs(i);
		}
	}
	cout << res;
}

int main(void){
	in();
	process();
	return 0;
}
