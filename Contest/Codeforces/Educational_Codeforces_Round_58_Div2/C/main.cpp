#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;
typedef pair<int, int> pt;


int n;
vector< pair<pt, int> > segs;

//function to read input
inline bool read(){
	if(!(cin >> n)){
		//check input
		return false;
	}
	segs.resize(n);
	for(int i = 0; i < n; i++){
		cin >> segs[i].first.first >> segs[i].first.second;
		segs[i].second = i;
	}
	return true;
}
//function to compare each segments 

bool cmp(const pair<pt, int> &a, const pair<pt, int> &b){
	//compare second with second
	if(a.first.second != b.first.second){
		return a.first.second < b.first.second;
	}
	//compare first with first
	if(a.first.first != b.first.first){
		return a.first.first < b.first.first;
	}
	return a.second < b.second;
}
//function to solve problem
inline void solve(){
	sort(segs.begin(), segs.end(), cmp);
	int mn = segs[n-1].first.first; //get left element at index n - 1
	DEBUG(mn);
	for(int i = n - 2; i >= 0; i--){
		if(segs[i].first.second < mn){
			vector<int> ts(n, 2);
			for(int id = 0; id <= i; id++){
				ts[segs[id].second] = 1;
			}
			for(int t : ts){
				cout << t << " ";
			}
			cout << endl;
			return;
		}
		mn = min(mn, segs[i].first.first);
	}
	cout << -1 << endl;

}

int main(void){
	cout << fixed << setprecision(15);
	int tc;
	cin >> tc;
	while(tc--){
		assert(read());
		solve();
	}
	return 0;
}


