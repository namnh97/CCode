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
#define sqr(a)  ((1LL * (a) * (a)))
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
//typedef pair<int,int>pii;
typedef long long ll;
const int maxn = 1e5 + 100;
typedef pair<ll,ll> pll;
vector<pll> v;
int xo[maxn];
vector<int> adj[maxn  * 4], adl[maxn * 4];
map<pll,int> mp;
int N;
inline int nott(int v){
	return (v < N ? N + v : v - N);
}
inline void add_edge(int v,int u){
	adj[v].pb(u);
	adl[u].pb(v);
}
inline void add_or(int v,int u){
	add_edge(nott(v),u);
	add_edge(nott(u),v);
}
inline void xor1(int v,int u){
	add_or(v, u);
	add_or(nott(v), nott(u));
}
inline void xor0(int v,int u){
	add_or(nott(v), u);
	add_or(nott(u), v);
}
stack<int> st;
bool mark[4 * maxn];
int com[4 * maxn];
inline void dfs(int v){
	mark[v] = 1;
	For(i,0,adj[v].size()){
		int u = adj[v][i];
		if(!mark[u])
			dfs(u);
	}
	st.push(v);
}
inline void dfs(int v,int c){
	com[v] = c;
	mark[v] = 1;
	For(i,0,adl[v].size()){
		int u = adl[v][i];
		if(!mark[u])
			dfs(u, c);
	}
}
inline bool check(int x){
	mp.clear();
	fill(adj,adj + 4 * maxn,vector<int>());
	fill(adl,adl + 4 * maxn,vector<int>());
	N = 0;
	For(i,0,x + 1){
		if(mp.find(pll(v[i].x, 0)) == mp.end())
			mp[pll(v[i].x,0)] = N ++ ;
		if(mp.find(pll(v[i].y, 1)) == mp.end())
			mp[pll(v[i].y,1)] = N ++; 
	}
	For(i,0,x + 1){
		if(!xo[i])
			xor0(mp[pll(v[i].x, 0)], mp[pll(v[i].y, 1)]);
		else
			xor1(mp[pll(v[i].x, 0)], mp[pll(v[i].y, 1)]);
	}
	memset(mark,0,sizeof mark);
	For(i,0,N * 2)
		if(!mark[i])
			dfs(i);
	memset(mark,0,sizeof mark);
	int v, co = 0;
	while(!st.empty()){
		v = st.top();
		st.pop();
		if(!mark[v])
			dfs(v, co ++);
	}
	For(i,0,N * 2)
		if(com[i] == com[nott(i)])
			return false;
	return true;
}
int main(){
	iosfal;
	int n;
	cin >> n;
	ll x,y;
	int a,b;
	For(i,0,n){
		cin >> x >> y >> a >> b;
		if(a == b)
			xo[i] = 0;
		else
			xo[i] = 1;
		v.pb(pll(x,y));
	}
	int l = 0, r = n-1, mid;
	while(l < r){
		mid = (l+r)/2;
		if(check(mid))
			l = mid;
		else
			r = mid - 1;
		if(l == r - 1){
			if(check(r))
				l = r;
			else
				r = l;
		}
	}
	For(i,0,n)
		cout << (i <= l ? "Yes" : "No") << endl;
}