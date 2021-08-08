#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	int q; cin >> q;
	int res = 0;
	while (q--) { 
		string in; cin >> in;
		if (in[0] != 'X') { 
			if (in[0] == '-') {
				--res;
			} else {
				++res;
			}
		}  else { 
			if (in[1] == '-') {
				res--;
			} else {
				res++;
			}
		}
	}
	cout << res;
	return 0;
}
