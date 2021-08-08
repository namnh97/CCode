//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/roy-and-trending-topics-1/
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
struct Topic {
	ll id;
	ll oldScore;
	ll currentScore;	
	Topic(ll _id, ll _score, ll _posts, ll _likes, ll _comments, ll _shares) {
		id = _id;
		oldScore = _score;
		currentScore = 50 * _posts + 5 * _likes + 10 * _comments + 20 * _shares;
	}
};
void solve() {
	ll n; cin >> n;
	auto compare = [](const Topic &left, const Topic &right) {
		if ( (left.currentScore - left.oldScore) == (right.currentScore - right.oldScore) ) {
			return left.id < right.id;
		}
		return (left.currentScore - left.oldScore) < (right.currentScore - right.oldScore);
	};

	priority_queue<Topic, vector<Topic>, decltype(compare)> q(compare);
	for (ll i = 0; i < n; i++) {
		ll id, score, posts, likes, comments, shares;
		cin >> id >> score >> posts >> likes >> comments >> shares;
		Topic a = Topic(id, score, posts, likes, comments, shares);
		q.push(a);
	}
	for (ll i = 0; i < 5; i++) {
		Topic first = q.top(); q.pop();
		cout << first.id << " " << first.currentScore << endl;
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

