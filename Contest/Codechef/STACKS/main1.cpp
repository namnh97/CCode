#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
void debugOut() {
	cerr << endl;
}

const int MAX = 100005;
int *a;
int n, t, size;

int binarySearch(int size, int radius) {
	int left = 0; int right = size - 1;
	int ans = size;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (a[mid] > radius) {
			ans = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return ans;
}

void solve() {
	cin >> t;
	while (t--) {
		cin >> n;
		a = new int[n];
		int size = 0;
		for (int i = 0; i < n; i++) {
			int radius; cin >> radius;
			int idx = binarySearch(size, radius);
			a[idx] = radius;
			if (idx == size) size++;
		}
		cout << size << " ";
		for (int i = 0; i < size; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


