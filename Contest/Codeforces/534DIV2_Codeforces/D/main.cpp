#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

const int maxn = 1e5 + 10;

int main(void){
	char ch[10], op[5];
	while(cin >> ch){
		if(ch[0] != 's') break;
		ll x = 1, y = 2;
		while(true){
			cout << "? " << x << " "  << y << endl;
			cin >> op;
			if(op[0] == 'x') break;
			x = y, y = y * 2;
		}
		ll l = x, r = y, mid;
		while(l < r - 1){
			mid = (l + r) >> 1;
			cout << "? " << mid << " " << l << endl;
			cin >> op;

			if(op[0] == 'x') l = mid;
			else r = mid;
		}
		cout << "? " << r << " " << l << endl;
		cin >> op;
		if(op[0] == 'x') cout << "! " << l << endl;
		else cout << "! " << r << endl;
	}
	return 0;
}


