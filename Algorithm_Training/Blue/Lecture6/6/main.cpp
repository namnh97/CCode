//https://www.spoj.com/problems/ALLIZWEL/
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

const int MAX = 101;
int r, c;
char matrix[MAX][MAX];
bool visited[MAX][MAX];
const string term = "ALLIZZWELL";
int stepr[] = {0, 0, 1, 1, 1, -1, -1, -1};
int stepc[] = {1, -1, 0, 1, -1, 0, 1, -1};
bool found;


bool isValid(int row, int col) {
    return row < r && row >= 0 && col < c && col >= 0;
}

void dfs(int row, int col, int count) {
    if (count == term.size()) {
        found = true;
        return;
    }

    for (int i = 0; i < 8; i++) {
        int nextr = stepr[i] + row;
        int nextc = stepc[i] + col;

        if (isValid(nextr, nextc) &&  matrix[nextr][nextc] == term[count] && !visited[nextr][nextc]) {
            visited[nextr][nextc] = true;
            dfs(nextr, nextc, count + 1);
            visited[nextr][nextc] = false;
        }
    }
}
void solve() {
    int t; cin >> t;
    while (t--) { 
        cin >> r >> c;
        found = false;
        int count = 0;
        for (int i = 0; i < r;  i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == term[0] && !found) {
                    dfs(i, j, 1);
                }
            }
        }
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


