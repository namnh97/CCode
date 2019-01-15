#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;



typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int n, m, a, b;
int main(void){
	cin >> n >> m >> a >> b;
	if(a * m <= b){
		cout << a * n;
	}
	else{
		int timesMoney = (n / m) * b;
		int remaining = n % m;
		if((remaining * a) > b){
			cout << timesMoney + b;
		}
		else  cout << timesMoney + (remaining * a); 
	}
	return 0;
}