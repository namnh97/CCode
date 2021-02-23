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


bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
	if (a.second == b.second) {
		return a.first.compare(b.first) < 0;
	}
	return a.second > b.second;
}

void solve() {
	int n, m;
	cin >> n >> m;
	string chef, country;
	map<string, string> relations;
	map<string, int> chefs;
	map<string, int> countries;
	fori(i, 0, n - 1) {
		cin >> chef >> country;
		relations.insert(mp(chef, country));
	}
	fori(i, 0, m - 1) {
		cin >> chef;
		chefs[chef]++;
		countries[relations[chef]]++;
	}
	vector<pair<string, int>> vchefs;
	vector<pair<string, int>> vcountries;
	for (auto &it : chefs) {
		vchefs.pb(mp(it.first, it.second));
		debug(it.first, it.second);
	}
	for (auto &it :countries) {
		vcountries.pb(mp(it.first, it.second));
		debug(it.first, it.second);
	}
	sort(vchefs.begin(), vchefs.end(), cmp);
	sort(vcountries.begin(), vcountries.end(), cmp);
	cout << vcountries.begin()->first << endl;
	cout << vchefs.begin()->first;
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


