#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	int n;
	cin >> n;

	int *a = new int[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);
	int res = 0;
	for(int i = 0; i < n; i+= 2){
		res += abs(a[i] - a[i ^ 1]);
	}
	cout << res;
	return 0;
}