#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;
int k, m, n, q;
string bas[51];
map<string, map<string, int>> comp;
map<string, int> fri[101];
string ari[101];
string com[51];

int judge (int i, map<string, int> temp) {
	int sign = 1;
	for (int p = 0; p < n; p++) {
		if (fri[i][bas[p]] < temp[bas[p]]) sign = 0;
	}
	return sign;
}

int iscom(string te) {
	for (int i = 0; i < m; i++) {
		if (te == com[i]) return 1;
	}
	return 0;
}
int main(void){
	cin >> k >> n >> m >> q;
	int u = 0;
	for (int i = 0; i < n; i++) {
		cin >> bas[i];
		ari[i] = bas[i];
		u++;
	}
	sort(bas, bas + n);
	for (int i = 0; i < m; i++) {
		string ct;
		cin >> ct;
		int l = ct.length();
		//save composite artifacts
		ct[l - 1] = ' ';
		com[i] = ct;
		ari[u++] = ct;

		string bt;
		cin >> bt;
		int nt;
		cin >> nt;
		comp[ct][bt] = nt;
		// in component of artifact
		while (getchar() == ',') {
			cin >> bt;
			cin >> nt;
			comp[ct][bt] = nt;
		}
	}
	//sort compositie as well as basic artifacts
	sort(ari, ari + u);
	//sort component
	sort(com, com + m);

	for (int d = 0; d < q; d++) {
		int num;
		string temp;
		cin >> num >> temp;
		fri[num][temp]++; // friend with number of artifacts
		for (int j = 0; j < m; j++) {
			map<string, int> temp = comp[com[j]];
			while (judge(num, temp)) {
				int sign = 1;
				for (int p = 0; p < n; p++) {
					if (fri[num][bas[p]] < temp[bas[p]]) {
						sign = 0;
					}
				}
				if (sign == 1) {
					for (int p = 0; p < n; p++) {
						if (fri[num][bas[p]] >= temp[bas[p]]) {
							fri[num][bas[p]] -= temp[bas[p]];
						}
					}
					fri[num][com[j]]++;
				}
			}
		}
	}
	
	for (int i = 1; i <= k; i++) {
		queue<string> strque;
		queue<int> que;
		for (int j = 0; j < m + n; j++) {
			if (fri[i][ari[j]] != 0) {
				strque.push(ari[j]);
				que.push(fri[i][ari[j]]);
			}
		}
		cout << que.size() << endl;
		while (que.size()) {
			if (iscom(strque.front())) {
				cout << strque.front() << que.front() << endl;
			} else cout << strque.front() << ' ' << que.front() << endl;
			strque.pop();
			que.pop();
		}
	}
	return 0;
}