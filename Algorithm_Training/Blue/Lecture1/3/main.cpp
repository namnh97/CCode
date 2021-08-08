//https://codeforces.com/problemset/problem/673/A
#include<bits/stdc++.h>
using namespace std;


void solve() {
	int minutes = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		if (t - minutes > 15) {
			cout << minutes + 15;
			return;
		} else {
			minutes = t;
		}
	}
	if (minutes + 15 < 90) {
		cout << minutes + 15;
	} else {
		cout << "90";
	}
}



int main(void){
	solve();
	return 0;
}

