#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;
char vowels[12] = {'A', 'O', 'Y', 'E', 'U', 'I', 'a', 'o', 'y', 'e', 'u', 'i'};

int main(void){
	string in;
	while (cin >> in) {
		vector<char> res;
	 	for (int i = 0; i < in.size(); i++) {
	 		bool check = true;
	 		for (int j = 0; j < 12; j++) {
	 		    if (in[i] == vowels[j]) {
	 		    	check = false;
	 		    	break;
	 		    }
	 		}
	 		if (check) {
	 			if (in[i] >= 'A' && in[i] <= 'Z') {
	 				in[i] += 32; 	
	 			}
	 			res.push_back(in[i]);	
	 		}
	 	}    	
	 	for (int i = 0; i < res.size(); i++) {
	 		cout << "." << res[i];
	 	}
	 	cout << endl;
	}    	
	return 0;
}
