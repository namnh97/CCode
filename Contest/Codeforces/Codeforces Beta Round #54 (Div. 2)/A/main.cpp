#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	string s; cin >> s;
	string hello = "hello";
	int index = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == hello[index]) {
			index++;
		}
	}
	if (index == 5) cout << "YES";
	else cout << "NO";
	return 0;
}
