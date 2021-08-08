#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

void KMPPreprocess(const string& p, vector<int>& prefix) {
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

int KMPSearch(const string& t, const string& p, vector<int> prefix) {
    int count = 0;
    int n = t.length();
    int m = p.length();
    int i = 0, j = 0;
    while (i < n) {
        if (t[i] == p[j]) {
            i++;
            j++;
        }
        if (j == m) {
            count++;
            j = prefix[j - 1];
        } else if (i < n && t[i] != p[j]) {
            if (j != 0) {
                j = prefix[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    return count;
}

void getS(string& S) {
    S.clear();
    string line, word;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> word) {
        S.append(word);
    }
}

void solve() {
    int t; cin >> t;
    cin.ignore();
    string S, s;
    
    for (int tc = 1; tc <= t; tc++) {
        getS(S);
        getline(cin, s);
        vector<int> prefix(s.size());
        KMPPreprocess(s, prefix);
        int result = KMPSearch(S, s, prefix);
        cout << "Case " << tc << ": ";
        cout << result << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


