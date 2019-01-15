#include<bits/stdc++.h>
#define int64 long long 

using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

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
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		if(i&1){
		 	cout << "I hate ";
		}
		else{
		 	cout << "I love ";
		}
		if(i != n){
		 	cout << "that ";
		}
	}
	cout << "it";
	return 0;
}