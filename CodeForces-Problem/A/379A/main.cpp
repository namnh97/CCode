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
	int a, b;
	cin >> a >> b;
	int res = a;
	while(a >= b){
		int div = a / b;
//		error(div);
		res += div;
		int mod = (a % b);
//		error(mod);
		a = (div + mod);
	}
	cout << res;
 	return 0;
}