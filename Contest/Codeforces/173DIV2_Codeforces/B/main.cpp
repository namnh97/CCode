#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	int n; cin >> n;
	int sum = 0;
	while (n--) {	
		int a, g;
		cin >> a >> g;
		if (sum + a <= 500) {
			sum += a;
			cout << "A";
		} else {
			sum -= g;
			cout << "G";
		}
	}
	cout << endl;
	return 0;
}
