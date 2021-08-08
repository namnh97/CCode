#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;



int main(void){
	int n; cin >> n;
	while(n--){
		string s; cin >> s;
		if(s.size() < 11){
			cout << s << endl;
		} else {
			cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
		}
	}
	return 0;
}
