#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

void KMPPreprocess(const string p, vector<int> &prefix) {
    prefix[0] = 0;
    int m = p.length();
    int i = 1;
    int len = 0;
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

bool isPassword(vector<int> prefix, int x) {
    for (int i = 1; i < prefix.size() - 1; i++) {
        if (prefix[i] == x) {
            return true;
        }
    }
    return false;
}

void solve() {
    string s; cin >> s;
    vector<int> prefix(s.length());
    KMPPreprocess(s, prefix);
    int x = prefix[s.length() - 1];
    if (x == 0) {
        cout << "Just a legend";
        return;
    }
    
    if (isPassword(prefix, x)) {
        for (int i = 0; i < x; i++) {
            cout << s[i];
        }
        return;
    }

    if (prefix[x - 1] == 0) {
        cout << "Just a legend";
        return;
    }

    if (prefix[x - 1]) {
        for (int i = 0; i < prefix[x - 1]; i++) {
            cout << s[i];
        }
        return;
    }


    cout << "Just a legend";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


