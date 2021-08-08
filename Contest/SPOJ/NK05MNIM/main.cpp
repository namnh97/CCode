#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	int t; cin >> t;
	while(t--){
		int res = 0, mx = 0, n; cin >> n;
		while(n--){
			int x; cin >> x;
			res ^= x;
			mx = max(mx, x);
		}
		if((mx <= 1) != (res == 0)){
			cout << -1 << endl;
		}
		else{
			cout << 1 << endl;
		}
	}
}
