#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;
#define MAX 100000
int a[MAX];

int main(void){
	int n, m, k;
	map<int, int> mp;
	set<int> s;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		mp[a[i]]++;
		if (mp[a[i]] == 1) {
			s.insert(a[i]);
		} else {
			s.erase(a[i]);
		}
	}
	set<int>::reverse_iterator itr = s.rbegin();

	if (s.empty()) cout << "Nothing" << endl;
	else cout << *itr << endl;

	int j = 0;
	for (int i = k; i < n; i++) {
		mp[a[j]]--;
		if (mp[a[j]] == 1) {
			s.insert(a[j]);
		} else {
			s.erase(a[j]);
		}
		mp[a[i]]++;
		if (mp[a[i]] == 1) {
			s.insert(a[i]);
		} else {
			s.erase(a[i]);
		}
		itr = s.rbegin();

		if (s.empty()) cout << "Nothing" << endl;
		else cout << *itr << endl;

		j++;
	}
	return 0;
}
