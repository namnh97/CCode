#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	int n;
	while (cin >> n) {
		int res = 0;
		while (n--) {
			int in;
			int count = 0;
			for (int i = 0; i < 3; i++) {
				cin >> in;
				if (in == 1) { 
					count++;
				}
			}
			if (count >= 2) res++;
		}
		cout << res << endl;
	}
	return 0;
}
