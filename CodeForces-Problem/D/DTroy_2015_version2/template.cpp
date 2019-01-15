#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 40004;

vector<int> comp[N+1];
map<ll, int> coords;
int par[N+1], i, n;
vector<ll> xs;
ll x[N], y[N];
bool need[N];

inline int nt(int k){ return N-k; }

void out(){
 	while(i++ < n)
 		cout << "No\n";
 	exit(0);
}

void merge(int u, int v){
 	u = par[v];
 	v = par[u];
 	if( u == v) return;
 	if(comp[u].size() > comp[v].size()){
 	 	swap(u,v);
 	}
 	vector<int> &l = comp[v], &r = comp[u];
 	for(int chi : r){
 	 	if(par[nt(chi)] == v) out();
 	 	l.push_back(chi);
 	 	par[chi] = v;
 	}

}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
	    int a, b;
	    cin >> x[i] >> y[i] >> a >> b;
	    xs.push_back(x[i]);
	    xs.push_back(-y[i]);
	    need[i] = (a != b);
	}	
	sort(xs.begin(), xs.end());
	xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
	for(int i=0; i < xs.size(); i++){
	 	coords[xs[i]] = i;
	}	
	for(int i=0; i<= N; i++){
	 	comp[i].push_back(i);
	 	par[i] = i;
	}
	for(int i=0; i<n; i++){
	 	x[i] = coords[x[i]];
	 	y[i] = coords[-y[i]];
	 	if(need[i]){
	 	 	merge(x[i], nt(y[i]));
	 	 	merge(nt(x[i]), y[i]);
	 	}
	 	else{
	 	 	merge(x[i], y[i]);
	 	 	merge(nt(x[i]), nt(y[i]));
	 	}
	 	cout << "YES\n";
	}
 	return 0;
}