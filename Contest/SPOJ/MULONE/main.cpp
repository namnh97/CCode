#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

char res[20000000];

void process(){
	int n; cin >> n;
	int memo = 0, p = n + n - 2;
	for(int i = 1; i <= n; i++, --p){
		memo += i;
		res[p] = memo % 10 + 0x30;
		memo /= 10;
	}
	for(int i = n - 1; i > 0; --i, --p){
		memo += i;
		res[p] = memo % 10 + 0x30;
		memo /= 10;
	}
	if(memo) cout << memo << endl;
	res[n + n - 1] = 0;
	cout << res << endl;
}

int main(void){
	int tc; cin >> tc;
	while(tc--){
		process();
	}
	return 0;
}
