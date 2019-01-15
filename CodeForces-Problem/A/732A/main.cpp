#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;



typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	int k, r;
	cin >> k >> r;
	int count = 1;
	while(true){
		int temp = k * count;
		if(temp % 10 == r  || temp % 10 == 0){
			break;
		}
		count++;
	}
	cout << count;
	return 0;
}