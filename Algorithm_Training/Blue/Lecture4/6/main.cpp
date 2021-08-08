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

const int MAX = 10001;
struct Car {
	int index;
	int arriveTime;
	Car(int i, int t) {
		index = i;
		arriveTime = t;
	}
};
int res[MAX];
queue<Car> sides[2];
int m, t, n;

void solve() {
	int cas; cin >> cas;
	while (cas--) {
		cin >> n >> t >> m;
		fori (i, 1, m) {
			int arrived; string side;
			cin >> arrived >> side;
			if (side == "left") {
				sides[0].push(Car(i, arrived));
			} else {
				sides[1].push(Car(i, arrived));
			}
		}

		int curSide = 0, curTime = 0, nextTime;
		int waiting = !sides[0].empty() + !sides[1].empty();

		while (waiting) {
			if (waiting == 1) {
				nextTime = sides[0].empty() ? sides[1].front().arriveTime : sides[0].front().arriveTime;
			} else {
				nextTime = min(sides[1].front().arriveTime, sides[0].front().arriveTime);
			}

			curTime = max(curTime, nextTime); //find the next time to start the ferry
			int carried = 0;
			while (!sides[curSide].empty()) {
				Car car = sides[curSide].front();
				if (car.arriveTime <= curTime && carried < n) { //load cars in ferry
					res[car.index] = curTime + t;
					carried++;
					sides[curSide].pop();
				}
				else {
					break;
				}
			}
			curTime += t;
			curSide = 1 - curSide;
			waiting = !sides[0].empty() + !sides[1].empty();
		}
		fori (i, 1, m) {
			cout << res[i] << endl;
		}
		if (cas) {
			cout << endl;
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

