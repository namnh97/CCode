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
	stack<int> stackBracket;
	int res = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '['){
			stackBracket.push(1);
		}
		else if(s[i] == ']' && stackBracket.top() == 1){
			stackBracket.pop();
		}
		else if(stackBracket.top() == 1){
			if(s[i] == ':'){
				if(stackBracket.top() == 2){
					stackBracket.pop();
					res += 2;
				}else{
					stackBracket.push(2);
					res += 2;
				}
			}
			if(stackBracket.top() == 2){
				if(s[i] == '|') res += 1;
			}
		}
	}
	if(!stackBracket.empty()) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}