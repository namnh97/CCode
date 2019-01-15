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
	int a, b;
	cin >> a >> b;
	int count = 0;
	while(a <= b){
		count++;
		a *= 3;
		b *= 2;
	}	
	cout << count;
	return 0;
}