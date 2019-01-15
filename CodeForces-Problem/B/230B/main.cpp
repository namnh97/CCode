#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;
#define MAX 10000000



typedef vector<int> vi;
typedef vector< pair<int, int> > pii;


ll primes[MAX];
void primeProcess(){
	memset(primes, 0, sizeof primes);
	primes[1] = 1;
	for(ll i = 2; i < sqrt(MAX); i++){
		if(primes[i] == 0){
			for(ll j = i * i; j < MAX; j += i){
				primes[j] = 1;
			}
		}
	}
}


void process(ll value){
	ll base = sqrt(value);
	if((base * base == value) && primes[base] == 0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

int main(void){
	ll n, value;
	cin >> n;
	primeProcess();
	while(n--){
		cin >> value;
		process(value);
	}
	return 0;
}
