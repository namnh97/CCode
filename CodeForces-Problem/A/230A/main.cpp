#include<bits/stdc++.h>
#define int64 long long 

using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>

void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}


bool cmp(pair<int, int> &a, pair<int, int> &b){
	return a.first < b.first;
}

int main(void){
	int n, m;
	cin >> n >> m;
	vector< pair<int, int> > v;
	for(int i=0; i<m ;i++){
	int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(), v.end(), cmp);
	int i;
	for(i = 0; i < v.size(); i++){
		if(n <= v[i].first) break;
		else{
			n += v[i].second;
		}
	}
	error(i);
	if(i == m) cout << "YES";
	else cout << "NO";
 	return 0;
}