//https://vjudge.net/problem/UVA-12207
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
using namespace std;

void solve() {
	int cas = 1;
	queue<int> que;
	int n, p, x, number;
	char com;
	while (1) {
		cin >> n >> p;
		if (n == 0 && p == 0) break;
		for (int i = 1; i <= min(n, p); i++) {
			que.push(i);
		}
        cout << "Case " << cas++ << ":" << endl;
		for (int k = 0; k < p; k++) {
			cin >> com;

			if (com == 'N') {
				x = que.front();
				cout << x << endl;
				que.pop();
				que.push(x);
			} else {
				cin >> number;
				int siz = que.size();
				que.push(number);
				for (int j = 0; j < siz; j++) {
					x = que.front();
					que.pop();
					if (number != x) {
						que.push(x);
					}
				}
			}
		}
		while (!que.empty()) {
			que.pop();
		}
	}}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

