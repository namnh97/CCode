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


// prioritize the dealinde order
// choose the job having the cheapest cost.
//
void solve() {
	time = 0;
	cost = 0;
	pq = max - heap();
	with each task:
		time += task.b;
		pq.push(task);
		while (time > task.d) {
			t = pq.pop()
				if (t.b > time- task.d) {
					t.b -= (time - task.d);
					cost += (tiem - task.d) / t.a;
					time = task.d;
					pq.push(t);
				}
				else {
					cost += t.b / t.a;
					time = t.b;
				}
		}
		out;
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

