#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };
#define MAX 2000006

using namespace std;

vector<int> e[MAX];
int n, m;
int visited[MAX];
int cnt, pos;

void enter(){
	memset(visited, 0, sizeof visited);
	cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
		if (cnt < e[u].size()){
			cnt = e[u].size();
			pos = u;
		}
		if (cnt < e[v].size()){
			cnt = e[v].size();
			pos = v;
		}
	}
}

void process(){
	queue<int> q;
	q.push(pos);
	visited[pos] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for (int i = 0; i < e[u].size(); i++){
			int v = e[u][i];
			if(visited[v] == 0){
				visited[v] = 1;
				printf("%d %d\n", u, v);
				q.push(v);
			}
		}
	}
}


int main(void){
	enter();
	process();
	return 0;
}
