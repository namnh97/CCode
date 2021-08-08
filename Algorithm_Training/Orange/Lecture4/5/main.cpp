//https://codeforces.com/problemset/problem/429/D
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

#define INF 1e9
struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
    }
};

bool xCompare(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}

bool yCompare(const Point &p1, const Point &p2) {
    return p2.y < p2.y;
}

ll sqr(ll num) {
    return num * num;
}

ll distance(const Point &p1, const Point &p2) {
    ll x = p1.x - p2.x;
    ll y = p1.y - p2.y;
    return sqr(x) + sqr(y);
}

ll bruteForce(vector<Point> &point_set, int left, int right) {
    ll min_dist = INF;
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j < right; j++) {
            min_dist = min(min_dist, distance(point_set[i], point_set[j]));
        }
    }
    return min_dist;
}

ll stripClosest(vector<Point> &point_set, int left, int right, int mid, double dist_min) {
    Point point_mid = point_set[mid];
    vector<Point> splitted_points;
    for (int i = left; i < right; i++) {
        if (sqr(point_set[i].x - point_mid.x) <= dist_min) {
            splitted_points.push_back(point_set[i]);
        }
    }
    sort(splitted_points.begin(), splitted_points.end(), yCompare);
    ll smallest = INF;
    int l = splitted_points.size();
    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < l && sqr(splitted_points[j].y - splitted_points[i].y) < dist_min; j++) {
            ll d = distance(splitted_points[i], splitted_points[j]);
            smallest = min(smallest, d);
        }
    }
    return smallest;
}

ll minimalDistance(vector<Point> &point_set, int left, int right) {
    if (right - left <= 3) {
        return bruteForce(point_set, left, right);
    }
    int mid = (left + right) / 2;
    ll dist_left = minimalDistance(point_set, left, mid);
    ll dist_right = minimalDistance(point_set, mid + 1, right);
    ll dist_min = min(dist_left, dist_right);
    return min(dist_min, stripClosest(point_set, left, right, mid, dist_min));
}


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> prefixSum(1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum.push_back(prefixSum[i] + a[i]);
    }

    vector<Point> points;
    for (int i = 0; i < n; i++) {
        points.push_back(Point(i, prefixSum[i + 1]));
    }
    sort(points.begin(), points.end(), xCompare);
    long long result = minimalDistance(points, 0, n);
    cout << result;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


