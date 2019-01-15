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
	int n;
	cin >> n;                                                            	
	double sumPercent = 0;
	for(int i = 0; i < n; i++){
	 	double x; cin >> x;
	 	sumPercent += (double)(x/100);
	}
	cout << fixed << setprecision(12);
	cout << ((double)(sumPercent/n)*100);
	return 0;
}