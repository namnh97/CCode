#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };
#define MAX 10000
using namespace std;

int n, k;
int a[MAX];

bool isSum(int a[], int n, int k) {
	if (k == 0) return true;
	if (n < 0 && k != 0) return false;
	bool check = isSum(a, n - 1, k) || isSum(a, n - 1, k - a[n]);
	return check;
}

int main(void){
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (isSum(a, n - 1, k))
		cout << "YES";
	else 
		cout << "NO";
	return 0;
}
