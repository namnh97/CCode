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
	string a[6] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
	int n; cin >> n;
	int r = 1;
	while(r * 5 < n){
		n -= r * 5;
		r <<= 1;
	}
	int index = (n - 1) / r;
	cout << a[index];
	return 0;
}