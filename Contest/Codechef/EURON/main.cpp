#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
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

ll merge(vi &a, vi left, vi right) {
	int i = 0, j = 0;
	ll count = 0;
	while (i < (int)left.size() || j < (int)right.size()) {
		if (i == (int)left.size()) {
			a[i + j] = right[j];
			j++;
		} else if (j == (int)right.size()) {
			a[i + j] = left[i];
			i++;
		} else if (left[i] <= right[j]) {
			a[i + j] = left[i];
			i++;
		} else {
			a[i + j] = right[j];
			count += (int)left.size() - i;
			j++;
		}
	}
	return count;
}

ll invCount(vi &a) {
	if ((int)a.size() < 2) {
		return 0;
	}

	int m = ((int)a.size() + 1) / 2;
	vi vleft, vright;

	vleft.assign(a.begin(), a.begin() + m);
	vright.assign(a.begin() + m, a.end());

	return invCount(vleft) + invCount(vright) + merge(a, vleft, vright);
}

void solve() {
	int n; cin >> n;
	vi a;
	fori(i, 0, n - 1){
		int tmp; cin >> tmp;
		a.pb(tmp);
	}
	cout << invCount(a);
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


