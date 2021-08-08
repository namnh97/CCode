#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;



int main(void){
	int n, k, t;
	cin >> n >> k >> t;
	int total = n * k;
	int process = total * t / 100;
	int maxSat = process / k;
	int remaining = process % k;
	for(int i = 1; i <= maxSat; i++){
		cout << k << " ";
		if(i == n) return 0;
	}
	cout << remaining << " ";
	for(int i = maxSat + 2; i <= n; i++){
		cout << 0 << " ";
	}
	return 0;
}
