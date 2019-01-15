#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;
int b, n, m;

int main(void){
	cin >> b >> n >> m;
	int *keyboards = new int[n];
	int *drives = new int[m];
	for(int i = 0; i < n; i++){
		cin >> keyboards[i];
	}
	for(int i = 0; i < m; i++){
		cin >> drives[i];
	}
	int res = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(keyboards[i] + drives[j] <= b){
				res = max(res, keyboards[i] + drives[j]);
			}
		}
	}
	cout << res;
	return 0;
}