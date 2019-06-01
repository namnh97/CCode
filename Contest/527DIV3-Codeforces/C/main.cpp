#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int n;
vector<string> v;
string res;

bool check(const string &pref, const string &suf){
	string s = pref + suf.substr(n - 2);
	multiset<string> vv, sPref,sSuf;
	for(int i = 0; i < n - 1; i++){
		sPref.insert(s.substr(0, n - i - 1));
		vv.insert(s.substr(0, n - i - 1));
		sSuf.insert(s.substr(i + 1));
		vv.insert(s.substr(i + 1));
	}
	if(vv == multiset<string>(v.begin(), v.end())){
		for(int i = 0; i < 2 * n - 2; i++){
			if(sPref.count(v[i])){
				res += 'P';
				sPref.erase(sPref.find(v[i]));
			}
			else if(sSuf.count(v[i])){
				res +=  'S';
				sSuf.erase(sSuf.find(v[i]));
			}
			else{
				assert(false);
			}
		}
		return true;
	}
	return false;
}
int main(void){
	cin >> n ;
	v = vector<string>(2 * n - 2);
	vector<string> big;
	for(int i = 0; i < 2 * n - 2; i++){
		cin >> v[i];
		if((int)v[i].size() == n - 1){
			big.push_back(v[i]);
		}
	}
	if(check(big[0], big[1])){
		cout << res << endl;
	}
	else{
		check(big[1], big[0]);
		cout << res << endl;
	}
	return 0;
}