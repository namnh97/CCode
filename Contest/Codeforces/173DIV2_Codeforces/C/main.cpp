#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	string des, src; cin >> des >> src;
	if (des == src) cout << "YES";
	else {
		if ((int)des.size() != (int)src.size()) { 
			cout << "NO";
		} else {
			int flag = 0;
			for (int i = 0; i < (int)src.size(); i++) {
				if (src[i] == '1') flag = 1;
			}
			if (flag == 0) {
				cout << "NO";
			} else {
				flag = 0;
				for (int i = 0; i < (int)des.size(); i++) {
					if (des[i] == '1') flag = 1;
				}
				if (flag == 0) cout << "NO";
				else cout << "YES";
			}
		}
	}
	return 0;
}
