#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define MAX 100005
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

bool inside(int a, int b, int c) {
	if (a <= b && b <= c)
		return true;
	return false;
}

bool onsegment(pair<int, int> pi, pair<int, int> pj, pair<int, int> pk) {
	bool first = inside(min(pi.first, pj.first), pk.first, max(pi.first, pj.first));
	bool second = inside(min(pi.second, pj.second), pk.second, max(pi.second, pj.second));
	return first & second;

}
struct stick {
	pair<int, int> a, b;
	stick (pair<int, int> _a, pair<int, int> _b) {
		a = _a;
		b = _b;
	}
	bool isIntersect(stick another) {
		int a1 = b.second - a.second; //y2 - y1
		int b1 = a.first - b.first; //x1 - x2
		int c1 = (a1 * a.first) + (b1 * a.second);	// ((x1 * (y2 - y1)) + (y1 * (x1 - x2)))

		int a2 = another.b.second - another.a.second;
		int b2 = another.a.first - another.b.first;
		int c2 = (another.a.first * a2) + (another.a.second * b2);
		
		double det = a1 * b2 - a2 * b1;
		if (det == 0) return false;
		else {
			double x = (b2 * c1 - b1 * c2) / det;
			double y = (a1 * c2 - a2 * c1) / det;
			pair<int, int> intersectPoint = make_pair(x, y);
			if (onsegment(a, b, intersectPoint) && onsegment(another.a, another.b, intersectPoint)) {
				return true;
			}
			return false;

		}
	}
};
int t, n, m;
vector<stick> sticks;
int root[MAX];

int findRoot(int i) {
	if (root[i] != i) {
		root[i] = findRoot(root[i]);
	}
	return root[i];
}

void unionLine(stick a, int indexA, stick b, int indexB) {
	int xset = findRoot(indexA);
	int yset = findRoot(indexB);
	if (xset != yset && a.isIntersect(b)) {
		root[xset] = root[yset];
	}
}

void solve() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			root[i] = i;
			int ax, ay, bx, by;
			cin >> ax >> ay >> bx >> by;
			sticks.pb(stick(make_pair(ax, ay), make_pair(bx, by)));
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				unionLine(sticks[i], i, sticks[j], j);
			}
		}
		for (int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
			if (findRoot(x) == findRoot(y)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

