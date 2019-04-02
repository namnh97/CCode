#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;
struct edge{
	int v, l, c;
	edge(int _v, int _l, int _c){
		v = _v;
		l = _l;
		c = _c;
	}
	bool operator < (const edge &a) const{
		return l > a.l;
	}
};


const int N = 111, K = 11111, INF = 1e9;
int d[N][K], n, k, m;

vector<vector<edge>> g;

void enter(){
	cin >> k >> n >> m;
	g.assign(n, vector<edge>());
	for(int i = 0; i < m; i++){
		int u, v, l, c;
		cin >> u >> v >> l >> c;
		--u, --v;
		g[u].push_back(edge(v, l, c));
	}
}

void solve(){
	memset(d, 0x3f, sizeof d);
	d[0][k] = 0;
	priority_queue<edge> q;
	q.push(edge(0, 0, k));
	while(!q.empty()){
		int u = q.top().v;
		int dumo = q.top().l;
		int mo = q.top().c;
		q.pop();
		if(dumo > d[u][mo]) continue;
		if(u == n-1){
			cout << dumo << endl;
			return;
		}
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i].v;
			int w = g[u][i].l;
			int c = g[u][i].c;
			if(mo >= c && d[v][mo - c] > dumo + w){
				q.push(edge(v, d[v][mo - c] = dumo + w, mo - c));
			}
		}
	}
	cout << -1 << endl;
}

int main(void){
	int tc; cin >> tc;
	while(tc--){
		enter();
		solve();
	}
	return 0;
}
