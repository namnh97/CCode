#include<bits/stdc++.h>

#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;



typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	int n; cin >> n;
	if(n < 0){
		int a = n / 10;
		int b = n / 100 * 10 + n % 10;
		cout << max(a,b) << endl;
	}else{
		cout << n << endl;
	}
	FOR(i, 0, 5){
		cout << i << endl;
	}
	return 0;
}
