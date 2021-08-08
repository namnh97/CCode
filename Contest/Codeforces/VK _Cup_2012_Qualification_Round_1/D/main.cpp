#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	int n; cin >> n;
	int t[20000], sum = 0, partsum[200000];
	for (int i = 0; i < n; i++){
		cin >> t[i];
		sum += t[i];	
	}
	int max = sum;
	for (int move1 = 2; move1 <= n / 3; move1++){
		if (n % move1 == 0){
		 	memset(partsum, 0, sizeof partsum);
		 	int k = 0;
		 	for (int move2 = 0; move2 < (int) n / move1; move2++){
		 		for (int move3 = 0; move3 < move1; move3++){
		 			partsum[move3] += t[k++];
		 		}
		 	}
		 	for (int tmpMove = 0; tmpMove < move1; tmpMove++){
		 		if (partsum[tmpMove] > max){
		 		 	max = partsum[tmpMove];      	
		 		}
		 	}
		}
	}
	cout << max << endl;
	return 0;
}
