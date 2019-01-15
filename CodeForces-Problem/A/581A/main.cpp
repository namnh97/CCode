#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;



typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	int a, b;
	cin >> a >> b;
	int res1 = min(a,b);
	int res2 = max(a,b) - res1;
	res2 = res2 / 2;
	
	cout << res1 << " " << res2;
	return 0;
}
