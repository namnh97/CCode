#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

char numToChar(int a ){
	return a - 1 + 'a';
}

int main(void){
	int s, k, t;
	cin >> t;
	while(t--){
		cin >> s >> k;
		for(int i = 0; i < s; i++){
			cout << char('a' + i % k);
		}
		cout << endl;
	}
	return 0;
}
