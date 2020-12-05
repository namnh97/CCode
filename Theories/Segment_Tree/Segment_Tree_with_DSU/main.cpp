#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c)	for(auto &(i) : (c))
#define x     first
#define y     second
#define pb  push_back
#define PB  pop_back()
#define iosfal  ios_base::sync_with_stdio(false)
#define mp(a,b) make_pair(a,b)
#define sqr(a)  ((a)*(a))
#define all(a)  a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl                                                                 
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a) << endl
#define dis(a,b)	(point(a.x - b.x, a.y - b.y))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define mt	make_tuple
#define get(a,b)	get<b>(a)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>	os;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<pii,int> piii;
const int maxn = 210, maxm = 5e4 + 10;
const ll inf = 1LL << 62;
int n,m;
struct node{
	int par[maxn];
	int moal;
	inline void init(){
		moal = 1;
		fill(par,par+maxn,-1);
	}
	node(){moal = ::n;init();}
	inline int root(int &v){
		return par[v] < 0 ? v : (par[v] = root(par[v]));
	}
	inline void merge(int x,int y){
		x = root(x), y = root(y);
		if(x == y)	return ;
		if(par[y] < par[x])
			swap(x,y);
		par[x] += par[y];
		par[y] = x;
		moal ++ ;
	}
	inline node operator * (node n){
		node a = *this;
		For(i,0,::n)
			a.merge(i,n.root(i));
		return a;
	}
	inline bool con(){
		return moal == n;
	}
}seg[maxm * 4], emp;
int s[maxm], g[maxm];
int V[maxm],U[maxm];
int G,S;
node ANS;
int ans;
inline void upd(int p,int i,int id = 1,int l = 0,int r = m){
	seg[id].merge(V[i],U[i]);
	if(r-l < 2)	return ;
	int mid = (l+r)/2;
	if(p < mid)
		upd(p,i,L(id),l,mid);
	else
		upd(p,i,R(id),mid,r);
}
inline void ask(int id = 1,int l = 0,int r = m){
	int mid = (l+r)/2;
	if(ANS.con())	return ;
	if(r-l<2){
		ans = max(ans,r-1);
		ANS = ANS * seg[id];
		return ;
	}
	if(!(ANS * seg[L(id)]).con()){
		ans = max(ans,mid-1);
		ANS = ANS * seg[L(id)];
		ask(R(id),mid,r);
	}
	else
		ask(L(id),l,mid);
}
vector<int> ps,pg;
inline int ms(){
	if(!seg[1].con())	return -1;
	ans = 0;
	ANS = emp;
	ask();
	return s[ps[ans]]; 
}
int sp[maxm];
int main(){
	iosfal;
	cin >> n >> m >> G >> S;
	ll ans = inf;
	For(i,0,m){
		cin >> V[i] >> U[i] >> g[i] >> s[i];
		-- V[i];
		-- U[i];
		ps.pb(i);
		pg.pb(i);
	}
	sort(all(ps), [](const int &i,const int &j){return s[i] < s[j];});
	sort(all(pg), [](const int &i,const int &j){return g[i] < g[j];});
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	For(i,0,ps.size())
		sp[ps[i]] = i;
	rep(i,pg){
		upd(sp[i],i);
		int x = ms();
		if(x + 1)
			ans = min(ans,1LL * G * g[i] + 1LL * x * S);
	}
	if(ans == inf)
		cout << -1 << endl;
	else
		cout << ans << endl;
}
 