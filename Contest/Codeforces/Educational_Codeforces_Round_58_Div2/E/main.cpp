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
	int maxa = 0;
	int maxb = 0;
	char c; int x, y;
	cin >> n;
	while(n--){
		cin >> c >> x >> y;
		if(x < y){
			swap(x, y);
		}
		if(c == '+'){
			maxa = max(maxa, x);
			maxb = max(maxb, y);
		}else{
			if(maxa <= x && maxb <= y){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}


