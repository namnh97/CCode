#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	int n;
	while (cin >> n) {
		for (int step1 = -n; step1 <= n; step1++) {
			int top = n - abs(step1);
			for (int step2 = 0; step2 < abs(step1); step2++) {
				cout << "  ";	
			}
			for (int step2 = 0; step2 < top; step2++) { 
				cout << step2 << " ";	
			}
			for (int step2 = top; step2 > 0; step2--) {
				cout << step2 << " ";	
			}
			cout << 0 << endl;
		}
		cout << endl;
	}
	return 0;
}
