#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

struct Edge { 
	int des, lon, cos;
	Edge() {}
	Edge(int _des, int _lon, int _cos) : des(_des), lon(_lon), cos(_cos){}
	bool operator < (const Edge &a) const {
		return lon > a.lon;
	}
};

vector<vector<Edge>> e;
int t, money, roads, cities;
int d[110][11111];
priority_queue<Edge> q;

void in() { 
	cin >> money >> cities >> roads;
	e.assign(cities + 10, vector<Edge>());
	for (int i = 0; i < roads; i++) {
		int src, des, lon, cos;
		cin >> src >> des >> lon >> cos;
		e[--src].push_back(Edge(--des, lon, cos));
	}
}


void process() {
	memset(d, 0x3f, sizeof(d));
	q.push(Edge(0, 0, money));
	d[0][money] = 0;
	while (!q.empty()) {
		int des = q.top().des, lon = q.top().lon, cos = q.top().cos;
		q.pop();
		if (lon > d[des][cos]) continue;
		if (des == cities - 1) { 
			cout << lon << endl;
			return;
		}
		for (Edge &it : e[des]) {
			int des_1  = it.des, lon_1 = it.lon, cos_1 = it.cos;
			if (cos >= cos_1 && d[des_1][cos - cos_1] > lon + lon_1) {
				q.push(Edge(des_1, d[des_1][cos - cos_1] = lon + lon_1, cos - cos_1));
			}
		}
	}
	cout << "-1" << endl;
}

int main(void){
	cin >> t;
	while (t--) {
		in();
		process();
	}
	return 0;
}
