#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
void debugOut() {
	cerr << endl;
}
const int MAX = 100001;
vector<int> nodes[MAX];
int cnt;

int dfs(int index) {
	if (nodes[index].empty()) {
		return 1;
	}
	int nodeNumber = 0;
	for (int i = 0; i < (int)nodes[index].size(); i++) {
		int child = nodes[index][i];
		nodeNumber += dfs(child);
	}

	if (nodeNumber % 3 == 0 && (int)nodes[index].size() == nodeNumber) {
		cnt += nodeNumber;
		return 1;
	} else if (nodeNumber > 2) {
		int tmp = nodeNumber / 3;
		cnt += (tmp * 3);
		return 0;
	} else {
		return 0;
	}
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cnt = 0;
		for (int i = 0; i < MAX; i++) {
			nodes[i].clear();
		}
		for (int i = 2; i <= n; i++) {
			int a; cin >> a;
			nodes[a].push_back(i);
		}
		if (dfs(1)) cout << "1" << endl;
		else cout << n - cnt << endl;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


