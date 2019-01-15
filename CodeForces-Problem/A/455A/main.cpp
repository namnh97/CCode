#include<bits/stdc++.h>
#define lli long long int
#define MAX 100006
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>


void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}


lli ans[MAX];
lli a[MAX];
int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int n; cin >> n;
	memset(a, 0, sizeof a);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		a[x]++;
	}
	ans[0] = 0;
	ans[1] = a[1];
	for(int i = 2; i < MAX; i++){
		ans[i] = max(ans[i-1], ans[i-2] + i * a[i]);
	}
	cout << ans[MAX - 1];

	return 0;
}