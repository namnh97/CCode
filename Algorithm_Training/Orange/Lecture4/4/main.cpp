// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=119
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

string s;
vector<vector<int>> a;

int get(int x, int y, int h, int w) {
    int res = 0;
    for (int i = x; i < x + h; i++) {
        for (int j = y; j < y + w; j++) {
            if (a[i][j] == 1) {
                res++;
            }
        }
    }
    return res;
}

void D2B(vector<string> &dest, int x, int y, int h, int w) {
    if (h == 0 || w == 0) {
        return;
    }

    char c;
    cin >> c;
    if (c == '1') {
        for (int i = x; i < x + h; i++) {
            for (int j = y; j < y + w; j++) {
                dest[i][j] = '1';
            }
        }
        return;
    }
    else {
        if (c == '0') {
            for (int i = x; i < x + h; i++) {
                for (int j = y; j < y + w; j++) {
                    dest[i][j] = '0';
                }
            }
            return;
        }
    }

    D2B(dest, x, y, (h + 1) / 2, (w + 1) / 2); 
    D2B(dest, x, y + (w + 1) / 2, (h + 1) / 2, w / 2);
    D2B(dest, x + (h + 1) / 2, y, h / 2, (w + 1) / 2);
    D2B(dest, x + (h + 1) / 2, y + (w + 1) / 2, h / 2, w / 2);
}

string B2D(int x, int y, int h, int w) {
    if (h == 0 || w == 0) {
        return "";
    }

    int sum = get(x, y, h, w);
    if (sum == 0) {
        return "0";
    } else {
        if (sum == w * h) {
            return "1";
        }
    }

    return "D" + B2D(x, y, (h + 1) / 2, (w + 1) / 2)
                + B2D(x, y + (w + 1) / 2, (h + 1) / 2, w / 2)
                + B2D(x + (h + 1) / 2, y, h / 2, (w + 1) / 2)
                + B2D(x + (h + 1) / 2, y + (w + 1) / 2, h / 2, w/ 2);
}

void solve() {
    while (1) {
        char c;
        int h, w;
        cin >> c;
        if (c == '#') {
            break;
        }
        cin >> h >> w;
        a.clear();
        if (c == 'B') {
            for (int i = 0; i < h; i++) {
                vector<int> tmp;
                for (int j = 0; j < w; j++) {
                    char cc; cin >> cc;
                    if (cc == '0') {
                        tmp.pb(0);
                    } else {
                        tmp.pb(1);
                    }
                }
                a.pb(tmp);
            }
        }
        string res = "";
        if (c == 'B') {
            cout << 'D';
            res = B2D(0, 0, h, w);
        } else {
            cout << 'B';
            vector<string> dest(h, string(w, '0'));
            D2B(dest, 0, 0, h, w);
            for (int i = 0; i < (int)dest.size(); i++) {
                res += dest[i];
            }
        }
        cout << " " << h << " " << w << endl;
        for (int i = 0; i < (int)res.size(); i++) {
            cout << res[i];
            if ((i + 1) % 50 == 0 || i == (int)res.size() - 1) {
                cout << endl;
            }
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


