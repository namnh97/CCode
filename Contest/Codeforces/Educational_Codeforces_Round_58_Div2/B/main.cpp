#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

void rem(string &s, const string &c){
    auto pos = s.find(c); //function to find substring
    if(pos == string::npos){
        cout << -1 << endl;
        exit(0);
    }
    s.erase(0, pos + 1); //remove from 0 to pos + 1
}

int main(void){
    string s; 
    cin >> s;
	rem(s, "[");
	rem(s, ":");
	reverse(s.begin(), s.end());
	cout << endl;
	rem(s, "]");
	rem(s, ":");

	cout << count(s.begin(), s.end(), '|') + 4 << endl;
    return 0;
}
