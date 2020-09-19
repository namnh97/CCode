#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int dp[5005];
	while (1) {
		memset(dp, 0, sizeof(dp));
		string in; cin >> in;
		if (in == "0") {
			break;
		}
		else {
			dp[0] = 1;
			for (int i = 1; i < (int)in.size(); i++) {
				int sum = (in[i - 1] - '0') * 10;
				int k = in[i] - '0';
				sum += k;
				if (k > 0) { 
					dp[i] += dp[i - 1];
				}
				if (sum > 9 && sum <= 26) {
					dp[i] += dp[i - 2 < 0 ? 0 : i - 2];
				}
			}
			cout << dp[(int)in.size() - 1] << endl;
		}
	}
	return 0;
}
