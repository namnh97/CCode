#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	int q; cin >> q;
	while(q--){
		int l, r, d;
		cin >> l >> r >> d;
        if(d < l || d > r){
            cout << d << endl;
        }
        else{
            cout << (r /d) *d + d;
        }
	}
	return 0;
}
