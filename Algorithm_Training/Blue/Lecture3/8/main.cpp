//https://codeforces.com/problemset/problem/334/B
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

const int MAX = 1e6;
int frex[MAX], frey[MAX];
vector<int> uniqueX, uniqueY;
vector<pair<int, int>> points;
void solve() {
	int x, y;
	fori (i, 0, 7) {
		cin >> x >> y;
		points.pb({x, y});
		if (!frex[x]) {
			uniqueX.pb(x);
			frex[x]++;
		}
		if (!frey[y]) {
			uniqueY.pb(y);
			frey[y]++;
		}
	}
	if (uniqueX.size() != 3 || uniqueY.size() != 3) {
		cout << "ugly";
		return;
	}
	sort(uniqueX.begin(), uniqueX.end());
	sort(uniqueY.begin(), uniqueY.end());
	sort(points.begin(), points.end(), [&](const pair<int, int> &left, const pair<int, int> &right) {
			if (left.first == right.first) {
				return left.second < right.second;
			}
			return left.first < right.first;
	});
	int index = 0;
	fori (i, 0, 2) {
		fori (j, 0, 2) {
			if (i == j && i == 1) {
				continue;
			}
			if (uniqueX[i] == points[index].first && uniqueY[j] == points[index].second) {
				index++;
			} else {
				cout << "ugly";
				return;
			}
		}
	}
	cout << "respectable";
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

