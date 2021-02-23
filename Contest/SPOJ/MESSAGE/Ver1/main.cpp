#include<bits/stdc++.h>
#define MAX 801

using namespace std;

vector<int> e[MAX];
int n, m, comp, counter;
int low[MAX], num[MAX], d[MAX];
stack<int> s;
bool fr[MAX];

void enter(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		e[u].push_back(v);
	}
}

void visit(int u){
	counter++;
	low[u] = counter;
	num[u] = counter;
	s.push(u);
	for(int i = 0; i < e[u].size(); i++){
		int v = e[u][i];
		if(d[v] != 0) continue;
		if(num[v] == 0){
			visit(v);
			low[u] = min(low[u], low[v]);
		}else{
			low[u] = min(low[u], num[v]);
		}
	}
	int v;
	if(low[u] == num[u]){
		comp++;
		do{
			v = s.top(); s.pop();
			d[v] = comp;
		}while(u != v);
		fr[comp] = true;
	}
}
void tarjan(){
	for(int i = 1; i <= n; i++){
		num[i] = 0;
	}
	counter = 0;
	comp = 0;
	for(int i = 1; i <= n; i++){
		if(num[i] == 0) visit(i);
	}
}

void process(){
	for(int u = 1; u <= n; u++){
		for(int i = 0; i < e[u].size(); i++){
			int v = e[u][i];
			if(d[u] != d[v]){
				fr[d[v]] = false;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= comp; i++){
		if(fr[i]) ans++;
	}
	cout << ans;
}
int main(void){
	enter();
	tarjan();
	process();
	return 0;
}