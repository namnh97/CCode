#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	string s; cin >> s;
	stack<char> stackChar;
	stackChar.push(s[0]);
	int count = 1;
	for(int i = 1; i < s.length(); i++){
		if(!stackChar.empty()){
			if(s[i] == stackChar.top()){
				count++;
				stackChar.pop();
				continue;
			}
		}
		stackChar.push(s[i]);
	}
	if(count % 2 == 0){
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}


