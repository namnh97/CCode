#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;



typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	int n, k;
	cin >> n >> k;
	int theRemaining = 240 - k;
	int i = 1;
	while(i <= n){
		theRemaining -= i * 5;
		if(theRemaining < 0) break;
		i++;
	}
	cout <<  --i;
	return 0;
}
