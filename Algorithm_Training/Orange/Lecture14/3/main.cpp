#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

void KMPpreprocess(const string &p, vector<int>& prefix) {
	prefix[0] = 0;
	int m = p.length();
	int len = 0;
	int i = 1;
	while (i < m) {
		if (p[i] == p[len]) {
			len++;
			prefix[i] = len;
			i++;
		} else {
			if (len != 0) {
				// get prefix of the previous character
				len = prefix[len - 1];
			} else {
				prefix[i] = 0;
				i++;
			}
		}
	}
}

void solve() {
    string s;
    while (cin >> s) {
        if (s == "*") {
            break;
        }

        vector<int> prefixI(s.length());
        KMPpreprocess(s, prefixI);
        int m = s.length();
        if (m % (m - prefixI[m - 1])) {
            cout << 1 << endl;
        } else {
            cout << (m / (m - prefixI[m - 1])) << endl;
        }
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


