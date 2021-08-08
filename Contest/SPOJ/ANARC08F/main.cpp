#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
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

int n, c, r;
int cnt;
int head[10000];
string location;
vector<string> brokenCars;

struct edge {
	int from;
	int to;
	int cost;
};

void solve() {
	while (1) {
		cin >> n >> c >> r;
		if ( !n || !c || !r) break;
		cnt = 0;
		cin >> location;
		fori(i, 1, 2) {
			string car; cin >> car;
			brokenCars.push_back(car);
		}
		fori(i, 1, 5) {
			cin.ignore();
			string a, edge, c;
			scanf("%s %s %s", a, edge, c);
			debug(a, edge, c);
			// string line; getline(cin, line);
			// istringstream ss(line);
			// string word;
			// string first; ss >> first; debug(first);
			// while (ss >> word) {
			// 	debug(word);
			// }
			// debugOut();
		}
	}
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

