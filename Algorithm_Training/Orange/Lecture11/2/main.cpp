#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 1005;
string s1;
vector<string> text1, text2;
int L[MAX][MAX];

void lcs(const vector<string> text1, const vector<string> text2) {
    memset(L, -1, sizeof(L));
    for (int i = 0; i <= text1.size(); i++) {
        for (int j = 0; j <= text2.size(); j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
}



void solve() {
    while (cin >> s1) {
        text1.clear(); text2.clear();
        if (s1 != "#") {
            text1.pb(s1);
            while (cin >> s1) {
                if (s1 == "#") break;
                text1.pb(s1);
            }
        }


        while (cin >> s1) {
            if (s1 == "#") break;
            text2.pb(s1);
        }

        lcs(text1, text2);
        vector<string> result;
        int i = text1.size(), j = text2.size();
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                result.pb(text1[i - 1]);
                i--;
                j--;
            } else if (L[i - 1][j] > L[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}




int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


