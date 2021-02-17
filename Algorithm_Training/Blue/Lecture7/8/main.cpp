//https://www.spoj.com/problems/LAZYPROG/
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

struct Job {
	int a, b, d;
	bool operator<(const Job& next) const {
		return a < next.a;
	}
};

void solve() {
	int testcases; cin >> testcases;
	while(testcases--) {
		int nContracts; cin >> nContracts;
		priority_queue<Job> pq;
		vector<Job> jobs;

		for (int i = 0; i < nContracts; i++) {
			int a, b, c; cin >> a >> b >> c;
			jobs.push_back((Job) {a, b, c});
		}
		sort(jobs.begin(), jobs.end(), [&](const Job &first, const Job &second) {
			return first.d > second.d;
		});
		double money = 0;
		int time = 0;
		for (int i = 0; i < nContracts; i++) {
			time += jobs[i].b;
			pq.push(jobs[i]);
			while (time > jobs[i].d) {
				Job top = pq.top(); pq.pop();

				if ()
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

