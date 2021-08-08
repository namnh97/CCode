#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	int test;
	cin >> test;
	int num1 = 0, num2 = 0, num3 = 0;
	while (test--) {
		int a, b, c;
		cin >> a >> b >> c;
		num1 += a;
		num2 += b;
		num3 += c;
	}
	if (num1 == 0 && num2 == 0 && num3 == 0) cout << "YES";
	else cout << "NO";
	return 0;
}
