#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

void KMPPreprocess(vector<int> b, vector<int>& prefix) {
    int m = b.size();
    int len = 0;
    int i = 1;
    while (i < m) {
        if (b[i] == b[len]) {
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

int KMPsearch(vector<int> a, vector<int> b, vector<int> prefix) {
    if (b.size() == 0) {
        return a.size() + 1;
    }

    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    int cnt = 0;
    while (i < n) {
        if (a[i] == b[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cnt++;
            j = prefix[j - 1];
        } else if (i < n && a[i] != b[j]) {
            if (j != 0) {
                j = prefix[j - 1];
            } else {
                i++;
            }
        }
    }
    return cnt;
}

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n - 1), b(w - 1);

    int x, y;
    cin >> x;
    for (int i = 0; i < n - 1; i++) {
        cin >> y;
        a[i] = y - x;
        x = y;
    }

    cin >> x;
    for (int i = 0; i < w - 1; i++) {
        cin >> y;
        b[i] = y - x;
        x = y;
    }

    vector<int> prefix(b.size(), 0);
    KMPPreprocess(b, prefix);
    int result = KMPsearch(a, b, prefix);
    cout << result;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


