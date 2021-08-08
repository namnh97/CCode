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
	bool occv = false, occh = false;
	for(auto &x : s){
		if(x == '0'){
			if(occv){
				cout << "3 4\n";
			}
			else{
				cout << "1 4\n";
			}
			occv = !occv;
		}else{
			if(occh){
				cout << "4 3\n";
			}else{
				cout << "4 1\n";
			}
			occh = !occh;
		}
	}
	return 0;
}


