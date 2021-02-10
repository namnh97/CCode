//https://codeforces.com/problemset/problem/691/A
#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int button; 
	if (n == 1) {
		cin >> button;
		if (button == 1) {
			cout << "YES";
		} else {
			cout << "NO";
		}
	}
	else {
		int c = 0;
		for (int i = 0; i < n; i++) {
			cin >> button;
			if (button == 0) {
				c++;
			}
		}
		if (c == 1) {
			cout << "YES";
		} else {
			cout << "NO";
		}
	}
}



int main(void){
	solve();
	return 0;
}


