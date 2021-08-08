#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

	
int N, C;
int a[111][111];
long long d[111];
 
void process() {
	memset( d, 0x3f, sizeof(d));
	d[N] = 0;
	queue<int> q;
	q.push(N);
	while(!q.empty()) {
		int u = q.front(), v;
		long long L, tmp, k, xx;
		q.pop();
		for(v=1;v<=N;++v) if((L=a[u][v])>0 && a[u][v]<=C){
			// 1 lan
			if(C-L>=d[u]) {
				tmp = d[u] + L;
				if(d[v]>tmp) {
					d[v] = tmp;
					q.push(v);
				}
			}
			// nhieu lan
			else if(C>2*L) {
				xx = (d[u]+L-C) / (C-2*L) - 1;
				xx = max(xx, (ll)1);
				for(k=xx;k<=xx+10;++k) {
					tmp = d[u] + L - k * (C - 2*L);
					if(tmp>=L && tmp<=C) {
						tmp = tmp + k * C;
						if(d[v]>tmp) {
							d[v] = tmp;
							q.push(v);
						}
					}
				}
			}
		}
	}
	printf("%lld\n",d[1]);
}
 
int main() {
	int st, M, u, v, l;
	scanf("%d",&st);
	while(st--) {
		scanf("%d%d%d",&N,&M,&C);
		memset( a, 0, sizeof(a));
		for(int i=0;i<M;++i) {
			scanf("%d%d%d",&u,&v,&l);
			a[u][v] = a[v][u] = l;
		}
		process();
	}
	return 0;
}