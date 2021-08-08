#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

void kmpPreprocess(string p, vector<int> &prefix) {
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
				len = prefix[len - 1];
			} else {
				prefix[i] = 0;
				i++;
			}
		}
	}
}

int kmpSearch(string t, string p, vector<int> &prefix) {
    int n = t.length();
    int m = p.length();
    int i = 0, j = 0;
    int cnt = 0;
    while (i < n) {
        if (p[j] == t[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            cnt++;
            j = prefix[j - 1];
        } else if (i < n && p[j] != t[i]) {
            if (j != 0) {
                j = prefix[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return cnt;
}

void solve() {
    string t, p;
    int k;
    getline(cin, t);
    getline(cin, p);
    cin >> k;

    int l = 0;
    int r = p.length() - 1;
    string ans = "IMPOSSIBLE";
    while (l <= r) {
        int mid = (l + r) >> 1;
        string tmp = "";
        for (int i = 0; i <= mid; i++) {
            tmp += p[i];
        }

        vector<int> prefix(tmp.length());
        kmpPreprocess(tmp, prefix);

        int cnt = kmpSearch(t, tmp, prefix);
        if (cnt >= k) {
            ans = tmp;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


