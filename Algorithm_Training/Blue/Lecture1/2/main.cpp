//https://codeforces.com/problemset/problem/731/A
#include<bits/stdc++.h>
using namespace std;


void solve() {
	string in; cin >> in;
	in.insert(in.begin(), 'a');
	int res = 0;
	for (int i = 0; i < (int)in.size() - 1; i++) {
		int first = in[i] - 'a';
		int second = in[i + 1] - 'a';
		int tmp = abs(second - first);
		res += min(tmp, 25 - tmp + 1);
	}
	cout << res;
}



int main(void){
	solve();
	return 0;
}

