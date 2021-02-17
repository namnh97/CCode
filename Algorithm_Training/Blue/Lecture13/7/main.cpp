//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1167
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
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

void solve() {
	int t;
	scanf("%d\n\n", &t);
	map<string, int> trees;
	char tree[35];
	while (t--) {
		int cnt = 0;
		trees.clear();
		while (cin.getline(tree, sizeof(tree))) {
			if (strlen(tree) == 0) {
				break;
			}
			trees[string(tree)]++;
			cnt++;
		}
		cout << fixed << setprecision(4);
		for (auto &it : trees) {
			cout << it.first << " " << (double)(it.second /(double)cnt * 100.0)  << endl;
		}
		if (!t) cout << endl;
	}
}



int main(int argc, char** argv){
	#ifndef ONLINE_JUDGE
	freopen(argv[1], "r", stdin);
	#endif
	solve();
	return 0;
}



