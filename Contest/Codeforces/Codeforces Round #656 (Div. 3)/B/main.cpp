#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;
int t;
int n;

int main(void){
	cin >> t;
	while (t--) {
		cin >> n;
		int x;
		vector<int> permu;
		for (int i = 0; i < 2 * n; i++) {
			cin >> x;
			if (find(permu.begin(), permu.end(), x) == permu.end()) {
				permu.push_back(x);
			}
		}
		for (auto &it : permu) {
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}
