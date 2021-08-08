#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define MAX 10001
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
int n;
int graph[MAX][MAX];
int r[MAX], c[MAX];
int sum;

void solve() {
	int cases = 0;
	while (1) {
		cin >> n;
		cases++;
		sum = 0;
		memset(graph, 0, sizeof(graph));
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		if (!n) break;
		fori(i, 1, n) {
			fori(j, 1, n) {
				cin >> graph[i][j];
				sum += graph[i][j];
			}
		}
		fori(i, 1, n) {
			fori(j, 1, n) {
				r[i] += graph[i][j];
				c[i] += graph[j][i];
			}
		}
		int dif = 0;
		fori(i, 1, n) {
			if (r[i] > c[i]) {
				dif += r[i] - c[i];
			}
		}
		cout << cases << ". " << sum << " " << dif << endl;
	}
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

