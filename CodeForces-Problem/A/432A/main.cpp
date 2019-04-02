#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	int n, k; cin >> n >> k;
	int team = 0;
	int member = 0;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(5 - x >= k){
			member++;
		}
		if(member == 3){
			team++;
			member = 0;
		}
	}
	cout << team;
	return 0;
}
