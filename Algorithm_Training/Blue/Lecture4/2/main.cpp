//https://www.spoj.com/problems/STPAR/
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

void solve() {
	int n;
	while(1) {
		stack<int> sideStreet;
		cin >> n;
		if (n == 0) {
			return;
		}
		int a[n];
		fori (i, 0, n - 1) {
			cin >> a[i];
		}
		int street = 1;
		bool ok = true;
		fori (i, 0, n - 1) {
			// if struck is in sidestreet
			while(!sideStreet.empty() &&  sideStreet.top() == street) {
				street++;
				sideStreet.pop();
			}
			// if struck is in order
			if (a[i] == street) {
				street++;
			} else {
				// if struck in order is larger than struck in side street
				if (!sideStreet.empty() && a[i] > sideStreet.top()) {
					ok = false;
					break;
				} else { // otherwise
					sideStreet.push(a[i]);
				}
			}
		}
		if (ok) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
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

