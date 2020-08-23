#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

void debugOut() { cerr << endl; }

int n;
string arc;
vector<string> words, inSignificances;

void solve() {
	int dp[151][151]; memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	int dp2[151][151];
	for (int i = 0; i < (int)words.size(); i++) {
		for (int j = 0; j < (int)arc.length(); j++) {
			// How many letters of this word do we want to use?
			int mx = min(arc.length() - j, words[i].length());
			//dp[i][j]  is the number of ways to use the first i words and the first j words of acro
			for (int k = 0; k <= (int)words[i].length(); k++) {
				dp2[k][0] = 1;
			}
			for (int k = 1; k <= mx; k++) {
				dp2[0][k] = 0;
			}
			for (int k = 0; k < (int)words[i].length(); k++) {
				for (int m = 0; m < mx; m++) {
					dp2[k+1][m+1] = dp2[k][m+1];
					if (words[i][k] == tolower(arc[j+m])) {
						dp2[k+1][m+1] += dp2[k][m];
					}
				}
			}
			for (int k = 1; k <= mx; k++) {
				dp[i+1][j+k] += dp[i][j] * dp2[words[i].length()][k];
			}
		}
	}
	if (dp[words.size()][arc.length()] == 0) {
		cout << arc << " is not a valid abbreviation" << endl;
	} else {
		cout << arc << " can be formed in "
				<< dp[words.size()][arc.length()] << " ways" << endl;
	}
	debugOut();
}

void in() {
	while(1) {
		inSignificances.clear(); words.clear();
		cin >> n;
		debug(n);
		if (n == 0) break;

		fori(i, 1, n) {
			string inSignificance;
			cin >> inSignificance;
			debug(inSignificance);
			inSignificances.push_back(inSignificance);
		}
		cin.ignore();

		while(1) {
			string phrase; getline(cin, phrase);
			if (phrase == "LAST CASE") break;
			debug(phrase);
			istringstream iss(phrase);
			iss >> arc; 
			while (1) {
				string word; iss >> word;
				if (word == "") break;
				if (find(inSignificances.begin(), inSignificances.end(), word) == inSignificances.end()) {
					words.push_back(word);
					debug(word);
				}
			}
			solve();
		}
	}
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	in();
	return 0;
}
