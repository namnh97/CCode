#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

const int N = 205;
const int oo = 1e5;
int n, m, d, c, v, u;
bool link[N][N];
int a[N][N], deg[N], Q[N * N], F[N * N], res[N * N];

void init() {
	cin >> n >> m;
	FOR (i, 1, m) {
		cin >> u >> v >> c;
		link[u][v] = true, link[v][u] = true;
		a[u][v] = c, a[v][u] = c;
		deg[u]++, deg[v]++;
	}
}

bool ok(int pos) {
	if (d != m + 1) return false;
	FOR (i, 1, n) {
		if (deg[i] & 1) return false; //check point just have once edge.
	}
	int sum = 0;
	FOR (i, pos, d - 1) {
		sum += a[res[i]][res[i + 1]];
		if (sum < 0) return false;
	}
	FOR (i, 1, pos - 1) {
		sum += a[res[i]][res[i + 1]];
		if (sum < 0) return false;
	}
	return true;
}

void process() {
	int top = 1; Q[1] = 1;
	while (top) {
		u = Q[top];
		FOR (i, 1, n) {
			if (link[u][i]) {
				link[u][i] = false, link[i][u] = false;
				top++, Q[top] = i; break;
			}
		}
		if (u == Q[top]) {
			d++; res[d] = u;
			top--;
		}
	}
	int low = oo, start; F[1] = 0;
	FOR (i, 2, d) {
		F[i] = F[i - 1] + a[res[i]][res[i - 1]];
		if (F[i] < low) {
			low = F[i], start = i;
		}
	}
	if (!ok(start)) cout << "-1";
	else {
		FOR (i, start, d) {
			cout << res[i] << " ";
		}
		FOR (i, 2, start) {
			cout << res[i] << " ";
		}
	}
}

int main(void){
	init();
	process();
	return 0;
}
