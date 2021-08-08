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

bool ask(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	string response;
	cin >> response;
	return response[0] == 'Y';
}

pair<int, int> binary_search(int x1, int y1, int x2, int y2) {
	// among points from (x1,y1) to (x2,y2) find the last point that is inside
	bool x_changes = x1 < x2;
	bool y_changes = y1 < y2;
	while(x1 < x2 || y1 < y2) {
		int x_mid = (x1 + x2 + 1) / 2;
		int y_mid = (y1 + y2 + 1) / 2;
		if(ask(x_mid, y_mid)) {
			x1 = x_mid;
			y1 = y_mid;
		}
		else {
			x2 = x_mid - x_changes; // or: x2 = x_mid; if(x_changes) x2--;
			y2 = y_mid - y_changes;
		}
	}
	return {x1, y1};
}

void solve() {
	int M = 1000;
	int half_square_side = binary_search(0, 0, M, 0).first;
	int square_side = 2 * half_square_side;
	int half_triangle_base = binary_search(0, square_side, M, square_side).first;
	int triangle_base = 2 * half_triangle_base;
	int top = binary_search(0, 0, 0, M).second;
	int triangle_height = top - square_side;
	printf("! %d\n", square_side * square_side + triangle_base * triangle_height / 2);
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


