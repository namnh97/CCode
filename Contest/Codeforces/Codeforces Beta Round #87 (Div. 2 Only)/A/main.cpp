#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int n;


int main(void){
	cin >> n;
	int total = 0;
	int res = 0;
	while (n--) {
		int a, b;
		cin >> a >> b;
		total -= a;
		total += b;
		res = max(res, total);
	}
	cout << res;
	return 0;
}
