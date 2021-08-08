#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;


int main(void){
	int n; cin >> n;
	while (n != 1) {
		cout << n << " ";
		for (int i = 2; i <= n; i++) {
			if (n % i == 0) {
				n /= i;
				break;
			}
		}
	}
	cout << n;
	return 0;
}
