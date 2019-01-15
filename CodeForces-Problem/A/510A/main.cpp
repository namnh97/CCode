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
	int n, m;
	cin >> n >> m;
	int count = 0;
	for(int i=1; i<=n; i++){
		if(!(i&1)) count++;
		for(int j=1; j<=m ;j++){
			if(i&1){
				cout << "#";
			}
			else{
				if((j == 1) && !(count & 1)){
					cout << "#";
				}
				else if((j == m) && (count & 1)){
					cout << "#";
				}
				else
					cout << ".";
			}
		}
		cout << endl;
	}
 	return 0;
}