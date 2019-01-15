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

int64 n, m;

int main(void){
	cin >> n >> m;
	int64 location = 1;
	int64 res = 0;
	while(m--){
	 	int64 x; cin >> x;
		if(x >= location){
		 	res += x - location;
	 	}
	 	else{
	 	 	res += n-(location - x);
	 	}
	 	location = x;
	}
	cout << res;
 	return 0;
}