#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;



int main(void){
	int n; cin >> n;
	int a[5] = {0};
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		a[x]++;
	}
	int total = a[4] + a[3] + a[2] / 2;
	a[1] -= a[3];
	if (a[2] % 2 == 1){
		total += 1;
		a[1] -= 2;
	}
	if (a[1] >= 0){
		total += (a[1] + 3 ) / 4;
	}
	cout << total << endl;
	return 0;
}
