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

const int MAX = 1000;
int primes[MAX];
int semiPrime[MAX];
int marked[MAX] = {0};

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

void solve() {
	for (int i = 2; i <= MAX; i++) {
		for (int j = i + 1; j * i < MAX; j++) {
			if (isPrime(i) && isPrime(j)) {
				semiPrime[i * j] = 1;
			}
		}
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		bool ok = false;
		for (int i = 2; i < n; i++) {
			if (semiPrime[i] && semiPrime[n - i]) {
				ok = true;
				break;
			}
		}
		if (ok) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
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


