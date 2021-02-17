//https://acm.timus.ru/problem.aspx?space=1&num=1585
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

void solve() {
    int t; cin >> t;
    string a, b;
    map<string, int> mp;
    while (t--) {
        cin >> a >> b;
        mp[a]++;
    }
    int maxi = 0;
    string res;
    for (auto &it : mp) {
        if (it.second > maxi) {
            maxi = it.second;
            res = it.first;
        }
    }
    cout << res << " Penguin";
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}
