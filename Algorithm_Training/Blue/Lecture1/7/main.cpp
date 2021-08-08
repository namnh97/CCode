/*
Vanya is managed to enter his favourite site Codehorses. Vanya uses nn distinct passwords for sites at all, however he can't remember which one exactly he specified during Codehorses registration.

Vanya will enter passwords in order of non-decreasing their lengths, and he will enter passwords of same length in arbitrary order. Just when Vanya will have entered the correct password, he is immediately authorized on the site. Vanya will not enter any password twice.

Entering any passwords takes one second for Vanya. But if Vanya will enter wrong password kk times, then he is able to make the next try only 5 seconds after that. Vanya makes each try immediately, that is, at each moment when Vanya is able to enter password, he is doing that.

Determine how many seconds will Vanya need to enter Codehorses in the best case for him (if he spends minimum possible number of second) and in the worst case (if he spends maximum possible amount of seconds).

Dữ liệu nhập
The first line of the input contains two integers nn and kk (1 \leq n, k \leq 1001≤n,k≤100) — the number of Vanya's passwords and the number of failed tries, after which the access to the site is blocked for 5 seconds.

The next n lines contains passwords, one per line — pairwise distinct non-empty strings consisting of latin letters and digits. Each password length does not exceed 100 characters.

The last line of the input contains the Vanya's Codehorses password. It is guaranteed that the Vanya's Codehorses password is equal to some of his n passwords.

Dữ liệu xuất
Print two integers — time (in seconds), Vanya needs to be authorized to Codehorses in the best case for him and in the worst case respectively.
*/
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
	int n, k; cin >> n >> k;
	int countLess = 0, countEqual = 0;
	string tries[n];
	string password;
	fori (i, 0, n - 1) {
		cin >> tries[i];
	}
	cin >> password;
	fori (i, 0, n - 1) {
		if (tries[i].size() < password.size()) {
			countLess++;
		}
		if (tries[i].size() == password.size()) {
			countEqual++;
		}
	}
	int best = countLess + (5 * (countLess / k)) + 1;
	int worst = countLess + countEqual +(((countLess + countEqual - 1) / k) * 5);
	debug(countLess, countEqual);
	cout << best << " " << worst;
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


