#include<bits/stdc++.h>
#define ll long long 
#define x first 
#define y second
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
#define fore(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = int(1e9);
const int N = 411;
int n, m;
int a[N];
vector< pair<pii, pii> > qs; //to save trucks

inline bool read(){
	if(!(cin >> n >> m)) return false;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	qs.resize(m);
	for(int i = 0; i < m; i++){
		cin >> qs[i].x.x >> qs[i].x.y >> qs[i].y.x >> qs[i].y.y;
		qs[i].x.x--, qs[i].x.y--;
	}
	return true;
}

vi ids[N];
int d[N][N];

inline void solve() {
	fore(i, 0, m)
		ids[qs[i].x.x].push_back(i);
	ll ans = -1;
	
	fore(l, 0, n) {
		fore(r, l, n)
			d[0][r] = a[r] - a[l];
		
		fore(k, 1, n + 1) {
			int opt = l;
			fore(r, l, n) {
				while(opt < r && max(d[k - 1][opt], a[r] - a[opt]) >= max(d[k - 1][opt + 1], a[r] - a[opt + 1]))
					opt++;
				
				d[k][r] = max(d[k - 1][opt], a[r] - a[opt]);
			}
		}
		
		for(int id : ids[l])
			ans = max(ans, d[qs[id].y.y][qs[id].x.y] * 1ll * qs[id].y.x);
	}
	
	cout << ans << endl;
}

int main(void){
	if(read()){
		solve();
	}
	return 0;
}


