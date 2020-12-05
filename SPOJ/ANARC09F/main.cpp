#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back

using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

const double eps = 1e-8;
const double pi = 3.141;
const double inf = 1e20;
const int maxp = 1111;

int doubleCompare(double d) {
	if (fabs(d) < eps) return 0;
	return d > eps ? 1 : -1;
}

struct point { 
	double x, y;
	point() {}
	point(double _x, double _y) {
		x = _x;
		y = _y;
	}

	bool operator==(point a) const {
		return doubleCompare(a.x - x) == 0 && doubleCompare(a.y - y) == 0;
	}

	bool operator<(point a) const {
		return doubleCompare(a.x - x) == 0 ? doubleCompare(y - a.y) < 0 : x < a.x;
	}
	
	double len2() {
		return x * x + y * y;
	}

	double distance(point p) {
		return hypot(x - p.x, y - p.y); //sqrt(x^2 + y^2);
	}

	point sub(point p) {
		return point(x - p.x, y - p.y);
	}
	
	double dot(point p) {//dot product 
		return x * p.x + y * p.y;
	}

	double det(point p) {//cross product
		return x * p.y - y * p.x;
	}
};
void solve() {
	int n;
	int z = 0;
	while (1) {
		cin >> n;
		if (!n) break;
		z++;
		vector<point> v;

		double x1, y1, x2, y2, power;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cin >> power;

		point c1(x1, y1);
		point c2(x2, y2);

		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			v.pb(point(x, y));
		}

		int ans = 0;

		for (int i = 0; i < (int)v.size(); i++) {
			double r1 = c1.distance(v[i]);
			double area1 = pi * r1 * r1;
			double remainArea = power - area1;
			if (remainArea < 0) continue;
			double r2 = sqrt(remainArea / pi);
			int cnt = 0;
			for (int j = 0; j < (int)v.size(); j++) {
				if (doubleCompare(r1 - c1.distance(v[j])) > 0 || doubleCompare(r2 - c2.distance(v[j]))) {
					cnt++;
				}
			}
			ans = max(ans, cnt);
		}
		for (int i = 0; i < (int)v.size(); i++) {
			double r1 = c2.distance(v[i]);
			double area1 = pi * r1 * r1;
			double remainArea = power - area1;
			if (remainArea < 0) continue;
			double r2 = sqrt(remainArea / pi);
			int cnt = 0;
			for (int j = 0; j < (int)v.size(); j++) {
				if (doubleCompare(r1 - c2.distance(v[j])) >= 0 || doubleCompare(r2 - c1.distance(v[j]) >= 0)) {
					cnt++;
				}
			}
			ans = max(ans, cnt);
		}
		cout << z << ". " << n - ans << endl;
	}
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

