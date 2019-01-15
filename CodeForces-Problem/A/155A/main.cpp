#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;



typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int n; cin >> n;
	int x; cin >> x; n--;
	int max = x, min = x;
	int count = 0;
	while(n--){
		cin >> x;
		if(max < x) {
			max = x;
			count++;
		}
		if(min > x){
			min = x;
			count++;
		}
	}	
	cout << count;
	return 0;
}